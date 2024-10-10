function [ d2s ] = calculaCurvaturesSplineNatural( x,y )
% [ d2s ] = calculaCurvaturesSplineNatural( x,y )
% funcio que calcula les curvatures (s'') de l'spline natural que interpola
% els punts de 'x' passant pels valors de 'y'

% definim les variables 'n', 't', 'h', i l'auxiliar sumH  
%   t(i) = y(i+1) - y(i);
%   h(i) = x(i+1) - x(i);
%   sumH(i) = h(i)+h(i-1);
    n = length(x)-1; %diem que 'x' te longitud n+1 (i=0,...,n o 1,...,n+1)
    h=x(2:end)-x(1:end-1);
    t=y(2:end)-y(1:end-1);
    sumH = zeros(1,n); sumH(2:end) = h(2:end)+h(1:(end-1))

    % omplim la matriu del sistema (n+1)x(n+1)
    % en realitat la 1a i la ultima fila no fan res pq s0'' = sn'' = 0
    A = zeros(n+1);
    A(1,1) = 1; A(n+1,n+1) = 1;
    for i=2:n
       A(i,i) = 2; %coeficient de S''(i)
       A(i,i-1) = h(i-1)/sumH(i); %coeficient de S''(i-1);
       A(i,i+1) = h(i)/sumH(i);
    end
    % omplim el vector de termes independents
    b = zeros(n+1,1);
    for i=2:n
       b(i) = (6/sumH(i))*(t(i)/h(i) - t(i-1)/h(i-1)); 
    end
    % solucionem el sistema
    d2s = A\b;
end