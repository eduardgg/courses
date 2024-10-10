function [ fx ] = f( x )
%previ, ens assegurem q x tingui la mida correcte
    if(not(length(x) == 3))
        disp('Largument de la funcio ha de ser un vector de 3 components!');
    end
    %fi previ
    
    x1 = x(1);
    x2 = x(2);
    x3 = x(3);
    
    %fx = zeros(1,3);
    fx(1) = 6*x1-2*cos(x2.*x3)-1;
    fx(2) = 9*x2+sqrt((x1.^2)+sin(x3)+1.06)+0.9;
    fx(3) = 60*x3+3*exp(x1.*x2)+10*pi-3;
    fx = fx';
end

