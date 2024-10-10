function [xd,yd,coeficients]=dibuixaSplineCubic(x,S,dS,d2S)
% [xd,yd,coeficients]=dibuixaSplineCubic(x,S,dS,d2S)
%
% Funcio per dibuixar un spline cubic C2
% x  : coordenades dels punts base
% S  : valors de la funcio als punts base
% dS : valors de la segona derivada o []
% d2S: valors de la segona derivada o [] (nomes es fa servir si dS=[])
%
% Retorna els següents elements:
%   xd: eix 'X' que conte els punts de x i divideix els intervals [xi,xi+1] 
%   en 20 punts. Es fa per dibuixar la funcio amb mes detalls.
%   yd: eix 'Y', valors de l'spline avaluat a l'eix 'X'
%
% Es pot dibuixar amb
%  plot(xd,yd)
%
yaux = [];
xd = []; yd = []; coeficients = [];
x01 = [0:1/20:1]; %20 subintervals a cada interval

h=x(2:end)-x(1:end-1);
t=S(2:end)-S(1:end-1);

if isempty(dS)
    %AMB CURVATURES
    %Bucle en intervals ( n+1 = length(x) <=> n = length(x)-1 )
    for i=1:length(x)-1
        a = (d2S(i+1)-d2S(i))/(6*h(i));
        b = d2S(i)/2 ;
        c = (t(i)/h(i) - h(i)*(d2S(i+1)+2*d2S(i))/6);
        d = S(i) ;
        xs = x(i)+x01*h(i); %valors de x a l'interval
        ys = a*(xs-x(i)).^3 + b*(xs-x(i)).^2 + c*(xs-x(i)) + d;
        %anem ampliant els vectors xd,yd
        xd = [xd xs]; yd = [yd ys];
        %els coeficients els retornem en forma de matriu nx4: una fila per
        % interval
        coeficients=[coeficients; a b c d];
    end
else
    %AMB DERIVADES: procediment identic, pero calcul de coefc's diferent
    for i=1:length(x)-1
        a = ( h(i)*(dS(i)+dS(i+1))-2*t(i) )/(h(i)^3);
        b = ( 3*t(i)-h(i)*(2*dS(i)+dS(i+1)) )/(h(i)^2);
        c = dS(i);
        d = S(i) ;
        xs = x(i)+x01*h(i); %valors de x a l'interval
        ys = a*(xs-x(i)).^3 + b*(xs-x(i)).^2 + c*(xs-x(i)) + d;
        xd = [xd xs]; yd = [yd ys]; coeficients=[coeficients; a b c d];
    end
end

% figure(2)
% plot(xd,yd);