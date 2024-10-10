% CALCUL I DIBUIX D'SPLINES
% Aquest script calcula i dibuixa l'Spline cubic C1 amb aproximaci� de les
% derivades, per als punts base i valors de la funcio a x i y.
%
% EXERCICIS:
% (1) Mira l'ajuda i el codi de la funcio dibuixaSplineCubic per veure que fa.
% (2) Implementa una funcio amb cap�alera 
%        function d2S = calculaCurvaturesSplineNatural(x,y)
%     que donats x i y, calculi les curvatures als punts base corresponents
%     a l'Spline natural. Descomenta les linies corresponents a l'Spline
%     natural a aquest codi. Observa els dos Splines. Son raonables els
%     resultats?
% (3) Implementa l'Spline C1 parabolic fent una aproximaci� de la derivada
%     per al primer punt. Dibuixa l'aproximaci� obtinguda.
% (4) Per a cada un dels Splines dibuixa (i) l'aproximaci� amb les dades
%     donades i (ii) modificant el valor del 3er punt de 1 a 2. Observa
%     on i quant afecta la modificaci� del valor en cada cas.
% (5) Dibuixa la base de cada un dels Splines. Es una base local? Explica
%     aix� el comportament dels Spline a l'apartat anterior?
%     (Pot ser util la funcio subplot)

%Dades
x = [0,1,3,4,5,7]; y = [1,1.25,1,0.5,0,0.4];
x2 = [0,1,3,4,5,7]; y2 = [1,1.25,2,0.5,0,0.4];

%Spline C1 cubic amb aproximacio de les derivades
i = 2:length(x)-1;
dS = [ (y(2)-y(1))/(x(2)-x(1)) (y(i-1)-y(i+1))./(x(i-1)-x(i+1)) (y(end)-y(end-1))/(x(end)-x(end-1))]
[xS1,yS1,coeficients]=dibuixaSplineCubic(x,y,dS,[]);
% coeficients
% figure(1)
% plot(xS1,yS1,'r-',x,y,'ko','LineWidth',2)
% legend('C1 cubic')
dS2 = [ (y2(2)-y2(1))/(x2(2)-x2(1)) (y2(i-1)-y2(i+1))./(x2(i-1)-x2(i+1)) (y2(end)-y2(end-1))/(x2(end)-x2(end-1))]
[xS12,yS12,coeficients]=dibuixaSplineCubic(x2,y2,dS2,[]);

%Spline natural (poner: _JoaquimBrugues para probar el de Joaquim)
d2S = calculaCurvaturesSplineNatural(x,y)
[xS2,yS2,coeficients]=dibuixaSplineCubic(x,y,[],d2S);
% coeficients
% figure(1)
% plot(xS1,yS1,'r-',xS2,yS2,'b-',x,y,'ko','LineWidth',2)
% legend('C1 cubic','Natural')
d2S2 = calculaCurvaturesSplineNatural(x2,y2)
[xS22,yS22,coeficients]=dibuixaSplineCubic(x2,y2,[],d2S2);

%Spline parabolic C1 (recurrent)
[xS3,yS3,coeficients]=dibuixaSplineC1Parabolic(x,y);
%coeficients
[xS32,yS32,coeficients]=dibuixaSplineC1Parabolic(x2,y2);
% PLOTTING:
figure(1)
subplot(2,1,1);
plot(xS1,yS1,'r-',xS2,yS2,'b-',xS3,yS3,'g-',x,y,'ko','LineWidth',2)
legend('C1 cubic','Natural','parabolic','punts')
subplot(2,1,2);
plot(xS12,yS12,'r-',xS22,yS22,'b-',xS32,yS32,'g-',x2,y2,'ko','LineWidth',2)
legend('C1 cubic','Natural','parabolic','punts')
title('Modificant el 3r punt de 1 a 2');