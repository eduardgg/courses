function [zero, errV] = secant(x_k0,x_k1,niter)
    errV = zeros(1,niter); %vector d errors
    
    for i=1:niter
        x_k2 = x_k0 + polinomi(x_k0)*(x_k0 - x_k1)/(polinomi(x_k1) - polinomi(x_k0)); %formula
        errV(i) = abs((x_k1-x_k2)/x_k2);
        x_k0 = x_k1; %actualitzacio aproximacions 'inicials'
        x_k1 = x_k2; 
    end
    
    zero = x_k2;
end