
%%FENÒMEN DE RUNGE


%%% Exercici 1

PART1m.m

%%% Exercici 2

PART2m.m



%%% Exercici 3

dx = 2/100;
x = -1:dx:1;

N = 8;
    
Pol = zeros(N+1, 101);

for i = 1:N+1
   Pol(i, :) = legendreP(i-1, x); 
end

for m = 2:2:N
    M = zeros(m+1, m+1);  %Matriu normal
    D = zeros(m+1,1);     %Vector normal
        
    for i = 1:m+1
        for j = i:m+1   
            M(i, j) = sum(Pol(i, :).*Pol(j, :))*dx;
            %M(i, j) = integral(@(x) legendreP(i-1, x).*legendreP(j-1, x), -1, 1);
            M(j, i) = M(i, j);            
        end
    end
    
    for i = 1:m+1
        D(i) = sum(Pol(i, :).*f(x))*dx;
        %D(i) = integral(@(x) legendreP(i-1, x).*f(x), -1, 1);
    end    
    
    c = M\D;
    p = zeros(1, 101);
    for j = 1:m+1
         %L = legendreP(j-1, x);
         for i = 1:101
            p(i) = p(i) + Pol(j, i)*c(j);
         end
    end
    plot(x, p);
    hold on
end
plot(x, f(x))
hold on


