function [zero,errV] = newton(x_k,niter)
    errV = zeros(1,niter); %vector errors
    
    for i=1:niter
       x_k2 = x_k - (polinomi(x_k))/derivada(x_k); %formula
       errV(i) = abs((x_k-x_k2)/x_k2);
       x_k = x_k2;
    end
    
    zero = x_k;
end

%polinomi es la funcio
%derivada es la drvida de la funcio
