function [ w ] = newtonCotes1( x, a, b )
% given [x0,...,xn],a,b this function returns [w0,...,wn] s.t.
% sum(wi*f(xi)) approximates integral(f) in [a,b]
n = length(x) - 1;
sizeX = size(x);
if(sizeX(1,2) == 1) x = x';
end

%Primer construim la matriu i el vector de termes independents
A = zeros(n+1);
B = zeros(n+1,1);
for i=1:(n+1)
    A(i,:) = x.^(i-1);
    B(i) = (1/i)*(b^i - a^i);
end

%Resolem el sistema
w = A\B;
end

