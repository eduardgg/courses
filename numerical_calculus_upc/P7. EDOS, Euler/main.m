% Objectius:
% - Entendre els conceptes basics dels metodes per a la resolucio numerica
% d'EDOs.
% - Implementar un metode per resoldre EDOs (metode d'Euler)
% - Comprovar experimentalment la convergencia d'un metode
%
% Tasques a fer:
% 1) Executar i mirar aquest script per veure com es pot resoldre el 
%    problema de valor inicial (PVI) amb la funcio de Matlab ode45
% 2) Implementar el metode d'Euler per a la resolucio del mateix PVI
%    Cal crear la funcio Euler amb els arguments d'entrada i sortida
%    especificats a aquest script. 
% 3) Dibuixar una grafica de log10(abs(error)) en funcio de log10(h), on l'error
%    s'evalua com la diferencia entre la solucio analatica i la solucio
%    numerica per x=2. Comprovar si l'ordre de convergencia coincideix amb
%    el teoric.
% Es proposa ara resoldre el PVI y''= -y, y(0)=1, y'(0)=0 per x en (0,2)
% 4) Reduir la EDO de segon ordre a un sistema d'EDOs de 1er ordre
%    Resoldre numericament el PVI amb el metode d'Euler. 
%    Opcional: comprovar la convergencia.

% Resolucio de la EDO dy/dx = -y/(10x+1) per x en (0,1) 
% amb condicio inicial y(0)=1
f=@(x,y) -y/(10*x+1); a=0; b=1;  y0=1;
analitica = @(x) (10 * x + 1).^(-0.1e1 / 0.10e2);

%Solucio amb funcions intrinseques de Matlab
[x,Y]=ode45(f,[a,b],y0);
figure(1), plot(x,Y,'-*'), title('ode45')

%Solucio amb el metode d'Euler
h = 0.1;  
[x,Y]=Euler(f,[a,b],y0,h);
xs = linspace(a,b,100);
figure(2), plot(x,Y,'-*',xs,analitica(xs),'-'), title('Euler')

%error
error = []; hv = [];
for i=1:5
    h = 0.2/2^i;
    hv = [hv,h];
    [ox,Y]=Euler(f,[a,b],y0,h);
    error = [error, log10(analitica(b) - Y(end))];
end
figure(3)
plot(log10(hv),error)


