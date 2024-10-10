function [ J ] = DF( x )
%previ, ens assegurem de les mesures. He de canviar les mesures per les
    %q m interessi!!!!!!!!
    if( not(length(x) == 3))
        disp('Largument de la funcio ha de ser un vector de 3 components!');
    end
    %fi previ
    
    x1 = x(1);
    x2 = x(2);
    x3 = x(3);
    %Alerta: cal canviar J per la q ens interessi
    J = zeros(3);
    J(1,1) = 6;
    J(1,2) = 2*x3*sin(x2*x3);
    J(1,3) = 2*x2*sin(x2*x3);
    J(2,1) = x1*(( x1^2 + sin(x3)+1.06)^(-1/2));
    J(2,2) = 9;
    J(2,3) = 0.5*cos(x3)*( (x1^2 + sin(x3) + 1.06)^(-1/2) );
    J(3,1) = 3*x2*exp(x1*x2);
    J(3,2) = 3*x1*exp(x1*x2);
    J(3,3) = 60;
    
    %comentari final: es poden calcular les derivades numericament com
    %f(x+hi)-f(x-hi)/2hi;
end

