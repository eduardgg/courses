function [ zero, errV ] = Broyden( x0 )
    %previ, ens assegurem de les mesures. He de canviar les mesures per les
    %q m interessi!!!!!!!!
    if(size(x0) == [1,3]) x0 = x0';
    elseif(not(length(x0)==3)) disp('x0 ha de tenir mida 3');
    end
    %fi previ
    
    xk = x0;
    errV = 0;
    S = DF(xk); %prenem la primera S igual a la jacobiana
    
    %primera iteracio fora del bucle
    deltax = S\(-f(xk)); %formula aqui
    x_2k = xk + deltax; %formula aqui
    errV(end) = 1; %primer error
    error = errV(end); %error guarda l error de l ultima iteracio
    xk = x_2k;
    
    while( error > 1e-10)
        % 1- Calcular u, v
        u = (1/norm(deltax)^2)*f(xk);
        v = deltax;
        % 2 - Calcular S
        S = S + u*v';
        % 3 - Calcular deltax
        deltax = S\(-f(xk)); %formula aqui
        x_2k = xk + deltax; %formula aqui
        errV(end+1) = abs(norm(x_2k -xk)/norm(xk));
        error = errV(end);
        xk = x_2k;
    end
    zero = x_2k;
end