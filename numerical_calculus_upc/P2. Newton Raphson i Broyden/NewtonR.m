function [ zero, errV ] = NewtonR( x0 )
    %previ, ens assegurem de les mesures. He de canviar les mesures per les
    %q m interessi!!!!!
    if(size(x0) == [1,3]) x0 = x0';
    elseif(not(length(x0)==3)) disp('x0 ha de tenir mida 3');
    end
    %finalitza previ
    
    xk = x0;
    errV = 0; %errV es el vector d errors
    
    %primera iteració, fora del bucle
    deltax = DF(xk)\(-f(xk));
    x_2k = xk + deltax; %x_2k es la x_k+1
    errV(end) = 1;
    error = errV(end); %error es l ultim error
    xk = x_2k;
    
    %mentre no estem suficientment a prop de l'arrel, iterem newton raphson
    while( error > 1e-10)
        deltax = DF(xk)\(-f(xk)); %formula aqui
        x_2k = xk + deltax; %formula aqui
        errV(end+1) = abs(norm(x_2k -xk)/norm(xk));
        error = errV(end);
        xk = x_2k;
    end
    zero = x_2k;
end

