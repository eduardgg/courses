function [M,K,f]=computeMatrices(diffusionCoefficient,artificialDiffusionStack,X,T,theReferenceElement)

IPweights = theReferenceElement.IPweights;
IPcoord = theReferenceElement.IPcoord;
N=theReferenceElement.N;
Nxi=theReferenceElement.Nxi;
Neta=theReferenceElement.Neta;

nOfNodes = size(X,1);
[nOfElements,nOfElementNodes] = size(T);

M=spalloc(nOfNodes,nOfNodes,9*nOfNodes);
K=spalloc(nOfNodes,nOfNodes,9*nOfNodes);
f=zeros(nOfNodes,1);

%Loop in elements (Galerkin formulation)
for i=1:nOfElements
    Te=T(i,:); %index of the nodes in the element
    Xe=X(Te,:); %coordinates of the nodes in the element
    [Me,Ke,fe]=elementalComputations(diffusionCoefficient,Xe,IPcoord,IPweights,N,Nxi,Neta);
    K(Te,Te)=K(Te,Te)+Ke; %assembly of elemental matrix
    M(Te,Te)=M(Te,Te)+Me; %assembly of elemental matrix
    f(Te) = f(Te) + fe;
    %figure(11), spy(K), disp('Press any key to continue'), pause
end

if artificialDiffusionStack>0
    L = 3;
    %Loop in elements close to the stack (SUPG contribution)
    xmid = sum(reshape(X(T',1),nOfElementNodes,nOfElements))/nOfElementNodes;%mid point of the elements
    ymid = sum(reshape(X(T',2),nOfElementNodes,nOfElements))/nOfElementNodes;
    elementsArtificialDiffusion = find(abs(xmid-5.5)<L+0.5 & abs(ymid-9.5)<L+0.5); %stack
    elementsArtificialDiffusion = [elementsArtificialDiffusion, find(abs(xmid-40)<L)]; %right boundary
    distance = min(min(abs(xmid(elementsArtificialDiffusion)-6),abs(ymid(elementsArtificialDiffusion)-10)),abs(xmid(elementsArtificialDiffusion)-40));
    %figure(2), hold on, plot(xmid(elementsArtificialDiffusion),ymid(elementsArtificialDiffusion),'ro'), hold off
    k = log10(artificialDiffusionStack);
    for i=1:length(elementsArtificialDiffusion)
        Te=T(elementsArtificialDiffusion(i),:); %index of the nodes in the element
        Xe=X(Te,:); %coordinates of the nodes in the element
        d=distance(i); alpha = k-distance(i)*(k+4)/L; 
        Ke=elementalDiffusion(10^alpha,Xe,IPcoord,IPweights,N,Nxi,Neta);
        K(Te,Te)=K(Te,Te)+Ke; %assembly of elemental matrix
    end
end


%_______________________________________
%Elemental matrix and vector
function [Me,Ke,fe]=elementalComputations(diffusionCoefficient,Xe,IPcoord,IPweights,N,Nxi,Neta)

nnodes = size(Xe,1);
Ke=zeros(nnodes);
Me=zeros(nnodes);
fe=zeros(nnodes,1);
xe = Xe(:,1); ye = Xe(:,2);
%Loop in integration points
for k=1:length(IPweights)
    Nk=N(k,:);
    Nkxi=Nxi(k,:);
    Nketa=Neta(k,:); 
    xk = Nk*Xe; 
    %Jacobian 
    J = [Nkxi*xe Nkxi*ye;Nketa*xe Nketa*ye];
    %Derivatives of shape function with (x,y)
    Nkxy = J\[Nkxi;Nketa];
    %Differentia of volume
    dxy=IPweights(k)*det(J);
    %Elemental matrix and vector
    Ke = Ke + (diffusionCoefficient*(Nkxy'*Nkxy) + Nk'*(velocityField(xk)*Nkxy))*dxy;
    Me = Me + Nk'*Nk*dxy;
    fe = fe + sourceTerm(xk)*Nk'*dxy;
end
  
%_______________________________________
%Elemental matrix for diffusion operator
function Ke=elementalDiffusion(diffusionCoefficient,Xe,IPcoord,IPweights,N,Nxi,Neta)

nnodes = size(Xe,1);
Ke=zeros(nnodes);
xe = Xe(:,1); ye = Xe(:,2);
%Loop in integration points
for k=1:length(IPweights)
    Nk=N(k,:);
    Nkxi=Nxi(k,:);
    Nketa=Neta(k,:); 
    xk = Nk*Xe; 
    %Jacobian 
    J = [Nkxi*xe Nkxi*ye;Nketa*xe Nketa*ye];
    %Derivatives of shape function with (x,y)
    Nkxy = J\[Nkxi;Nketa];
    %Differentia of volume
    dxy=IPweights(k)*det(J);
    %Elemental matrix and vector
    Ke = Ke + (diffusionCoefficient*(Nkxy'*Nkxy))*dxy;
end
  