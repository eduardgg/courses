function [x,Y] = Euler(f,I,y0,h)
    a = I(1); b = I(2);
    x = a:h:b;
    n = length(x);
    Y = zeros(1,n); Y(1)=y0;
    for i=2:n
        %xn = x(i-1);yn = Y(i-1);
        Y(i) = Y(i-1) +h*f(x(i-1),Y(i-1));
    end
end
