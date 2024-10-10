function zero = biseccio(x_k,a,niter) %x_k, a aproximacions inicials
    for i=1:niter
        x_k2 = 0.5*(x_k + a); %formula
        if(polinomi(x_k2)*polinomi(x_k) < 0)
           a = x_k2;
        end
        if (polinomi(x_k2)*polinomi(x_k) > 0)
            x_k = x_k2;
        end
    end
    zero = x_k;
end