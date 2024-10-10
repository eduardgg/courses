function theReferenceElement = createReferenceElementTri(degree)
%theReferenceElement = createReferenceElementTri(degree)
%Creates a struct with the information of the reference element, for
%triangle discretizations

switch degree
    case 1
        z = [0.5 0; 0 0.5; 0.5 0.5];
        w = [1 1 1]/6;
        xi = z(:,1); eta=z(:,2);
        N = [1-xi-eta,   xi,   eta];
        Nxi  = [-ones(size(xi))   ones(size(xi))    zeros(size(xi))]; 
        Neta = [-ones(size(xi))   zeros(size(xi))   ones(size(xi))]; 
        nodesCoord = [0,0;1,0;0,1];
    otherwise
        error('Element not implemented yet')
end
theReferenceElement=struct('IPweights',w,'IPcoord',z,'N',N,'Nxi',Nxi,'Neta',Neta,'type','TRI','nodesCoord',nodesCoord);
