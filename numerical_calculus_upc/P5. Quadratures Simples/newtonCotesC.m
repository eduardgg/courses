% clear;
% clc;
a = 0;
b = 5;
I = exp(-a)-exp(-b)+(sqrt(pi)/4)*(erf(b-4) - erf(a-4))

% EXERCICI 1: aproximar amb n=4 (5 punts)
n = 4;
x=0:((b-a)/n):5;
w = newtonCotes1(x,a,b);
approxN4 = 0;
for i=1:length(x)
    approxN4 = approxN4 + w(i)*f1(x(i));
end
approxN4

%% EXERCICI 2: aproximar amb n=1,...,14 i plotting de l'error
% errorV = zeros(1,14);
% logX = log(1:14);
% for n=1:14
%     x=0:((b-a)/n):5;
%     w = newtonCotes1(x,a,b);
%     approx = 0;
%     for i=1:length(x)
%         approx = approx + w(i)*f1(x(i));
%     end
%     errorV(n) = abs(I - approx);
% end
% plot(logX,log(errorV))
% xlabel('log(#punts)'); ylabel('log(error)');
% title('Error Newton-Cotes');