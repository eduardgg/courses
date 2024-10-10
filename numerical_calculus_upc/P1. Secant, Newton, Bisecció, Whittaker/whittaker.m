function [zero, errV] = whittaker(x_k,m,niter)
    errV = zeros(1,niter); %vector d errors
    
    for i=1:niter
        x_k2 = x_k - (1/m)*polinomi(x_k);%pendent m
        errV(i) = abs((x_k-x_k2)/x_k2); %actualitzem vector errors
        x_k = x_k2; 
    end
    
    zero = x_k;
end