%punts equiespaiats
I=-1:0.01:1;
%Imatges
fI=f(I);

X = -1:(2/100):1;
fX = f(X);
P2MQ = polyfit(X,fX,2);
P4MQ = polyfit(X,fX,4);
P6MQ = polyfit(X,fX,6);
P8MQ = polyfit(X,fX,8);

plot(I,fI,I,polyval(P2MQ,I),I,polyval(P4MQ,I),I,polyval(P6MQ,I),I,polyval(P8MQ,I));
title('aproximacio polinomica duna funcio amb Pn = polinomi de grau n');
l=legend('funcio','P2','P4','P6','P8');