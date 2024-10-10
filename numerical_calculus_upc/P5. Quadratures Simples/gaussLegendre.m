clear;
clc;
a = 0;
b = 5;
I = exp(-a)-exp(-b)+(sqrt(pi)/4)*(erf(b-4) - erf(a-4))
m = (b-a)/2; n = (a+b)/2;
g = @(x) exp(-(m*x+n)) + 0.5*exp((-1)*((m*x+n)-4).^2);

%% 1er apartat: integrar en [0,5] amb n=4 (5pts integracio)
% z   : Punts de Gauss (vector columna)
% w   : Pesos (vector fila)
[z,w] = QuadraturaGauss(5);
% Aproximem la integral per un sumatori, fent un canvi de [-1,1] a [a,b]
Iaprox = m*(w*g(z))

%% 2on apartat: integrar amb n=0,1,...,14
error = [];
for i=1:15
    [z,w] = QuadraturaGauss(i);