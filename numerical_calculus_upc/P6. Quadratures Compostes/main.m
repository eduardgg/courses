%CONVERGENCIA DE LES QUADATURES COMPOSTES
%L'objectiu d'aquest exercici es comprovar la convergencia de les
%quadratures compostes. Aquest script mostra l'evolucio de l'error en 
%funcio del numero d'avaluacions de la funcio (cost) per a la quadratura 
%composta del trapezi. 
%
%Completa l'script per a dibuixar tambe l'evolucio de l'error per 
%a les quadratures compostes de:
% a) Simpson
% b) Gauss-Legendre amb 2 punts a cada subinterval (n=1)
% c) Gauss-Legendre amb 3 punts a cada subinterval (n=2)
%
%Observa la convergencia assimptotica. Tenen les quadratures el
%comportament esperat?
%
%Representa ara l'error per al segon exemple (paradoja de Runge).
%Compara l'evolucio de l'error amb l'error amb quadratures simples (1 sol
%interval, augmentant n)

clear all; close all; clc

%Exemple 1
f = @(x)( exp(-x)+0.5*exp(-(x-4).^2) ); a = 0; b = 5; I_ex = exp(-a) - exp(-b) + (1/4)*sqrt(pi)*(erf(b-4) - erf(a-4));
%Exemple 2
%f = @(x)(1./(1+x.^2)); a = -4; b = 4; I_ex = (atan(b) - atan(a)); 

%Composta de trapezi
errorTrap=[];
errorSimp=[];
for k=1:5
    m = 2*2^k; %numero d'intervals
    errorTrap = [errorTrap, abs(compostaTrapezi(f,a,b,m)-I_ex)];
    errorSimp = [errorSimp, abs(compostaSimpson(f,a,b,m)-I_ex)];
end
nPuntsTrap = 2*2.^[1:5]+1;
nPuntsSimp = 2*nPuntsTrap -1;
ajustTrap = (polyfit(log10(nPuntsTrap(end-2:end)),log10(errorTrap(end-2:end)),1));
ajustSimp = (polyfit(log10(nPuntsSimp(end-2:end)),log10(errorSimp(end-2:end)),1));

%Grafica errors
figure(1) 
subplot(2,1,1);
plot(log10(nPuntsTrap),log10(errorTrap),'-o') 
xlabel('log_{10}(#punts)'), ylabel('log_{10}(error)')
legend('Composta de trapezi')
subplot(2,1,2);
plot(log10(nPuntsSimp),log10(errorSimp),'-o') 
xlabel('log_{10}(#punts)'), ylabel('log_{10}(error)')
legend('Composta de Simpson')

fprintf('\nPendent 3 darrers punts:\n Composta trapezi: %0.1f \n',ajustTrap(1))
fprintf('\nPendent 3 darrers punts:\n Composta simpson: %0.1f \n',ajustSimp(1))

