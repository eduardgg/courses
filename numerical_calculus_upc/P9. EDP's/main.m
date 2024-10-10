%Solution of the 2D unsteady convection-diffusion equation with homogeneous
%Dirichlet boundary conditions (u=0 on the boundary) and null initial
%condition. The velocity field is defined at velocityField.m

%DATA
nOfElementsPerKm = 2; %Only integer values are valid
diffusionCoefficient= 0.1;
uSmokeStack = 1;
artificialDiffusionStack=1; %Artificial diffusion added at elements close to the stack and right boundary
figure(1),plotVelocityField;

isSteady = 0; %1 for steady, 0 for unsteady

if isSteady == 0
    finalTime=5; %(h)
    dt = 0.1;
    ts = 0:dt:finalTime;  
    BCevolution = ts; BCevolution(ts>1)=1;
    figure(11), plot(ts,BCevolution), xlabel('t'),ylabel('u at stack')
end

%PREPROCES
%Reference element
degree = 1; theReferenceElement = createReferenceElementTri(degree);
nOfElementNodes = size(theReferenceElement.N,2);
%Mesh: regular mesh in a rectangular domain [0,40]x[0,20] (Km)
[X,T] = CreateMesh(1,nOfElementNodes,[0,40,0,20],40*nOfElementsPerKm+1,20*nOfElementsPerKm+1);
figure(2), clf
PlotMesh(T,X,1,'k-'); title('Computational mesh')
%Definition of Dirichlet boundary conditions
x = X(:,1); y = X(:,2); tol=1.e-4;
nodesCCD1 = find(abs(x)<tol|abs(x-40)<tol|abs(y)<tol|abs(y-20)<tol); %Nodes on the exterior boundary
nodesCCD2 = find(abs(x-6)<0.5+tol & abs(y-10)<0.5+tol); %nodes on the smokestack
nodesCCD = [nodesCCD1; nodesCCD2];
uCCD = [zeros(length(nodesCCD1),1);uSmokeStack*ones(length(nodesCCD2),1)]; 

%System of equations (without BC)
[M,K,f]=computeMatrices(diffusionCoefficient,artificialDiffusionStack,X,T,theReferenceElement);

if isSteady == 1
    %Dirichlet boundary conditions
    unknowns= setdiff([1:size(X,1)],nodesCCD);
    f = f(unknowns)-K(unknowns,nodesCCD)*uCCD; K=K(unknowns,unknowns);
    %System solution
    sol=K\f;
    u = zeros(size(X,1),1); u(unknowns)=sol; u(nodesCCD)=uCCD;
    %POSTPROCESS
    figure(3)
    PlotNodalField(u,X,T), title('FEM solution')
    view(2), axis equal, caxis([0,uSmokeStack]),colorbar
    % figure(4)
    % plotSolution(X,T,u), title('FEM solution')
    % view(2), axis equal, caxis([0,uSmokeStack]),colorbar
else
    %Forward Euler (explicit) with lumped mass matrix
    M = spdiags(diag(M),0,size(M,1),size(M,1));
    A = M\K; f = dt*f;
    u = zeros(size(A,1),1);
    nOfTimeSteps = length(ts)-1;
    %Loop in time steps
    for n=1:nOfTimeSteps
        u=u-dt*(A*u+f); u(nodesCCD)=BCevolution(n+1)*uCCD;
        if mod(n,round(0.2/dt))==0
            figure(3)
            PlotNodalField(u,X,T), title('FEM solution')
            view(2), axis equal, caxis([0,uSmokeStack]),colorbar, axis off
            title(sprintf('t=%0.1f h',dt*n))
            pause(0.5)
        end
    end
end
