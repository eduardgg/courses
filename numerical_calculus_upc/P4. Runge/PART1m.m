x = -1:0.01:1; % dividim l'interval[-1,1]
%per que surti el gràfic
figure(1)
plot(x, f(x))
hold on

for i = 3:2:9 %volem n+1 = 3,5,7,9
    %per calcular els coeficients del polinomi interpolador
    %utilitzem la funció polyfit
    c = polyfit([-1:2/(i-1):1], f([-1:2/(i-1):1]), i-1);
    %on polyfit(x,f(x),grau que volem);
    %utilitzem la funcio polyval per avaluar el polinomi
    plot(x, polyval(c, x))
    %polyval(polinomi,x) retorna els valors del polinomi evaluat a x
    axis([-1 1 -1.5 1.5])
    %axis([xmin xmax ymin ymax])
    hold on
end
%comenta el grafic
legend('f(x)', 'Pol grau 2', 'Pol grau 4', 'Pol grau 6','Pol grau 8')
