% Solucio de l'equacio de conveccio-difusio estacionaria 1D
%     a u_x - nu u_xx = 1   x en (0,1)
%     u(0)=u(1)= 0
% amb elements finits lineals de mida uniforme h
%
% Exercicis:
% 1) Calcula la solucio a x=0.5 amb 2 xifres significatives (correctes) per a a=nu=1
%
% mirem què passa amb 1000 i 10000 elements i si no canvia es correcte
% 2) Executa l'script per a numElements = 20, velocitat a=1 i difusio
%    nu = 1,0.1,0.01,0.001
%
% hi ha oscil·lacions numeriques, peta :(
% 3) Comprova experimentalment que la condicio per a que la solucio numerica no
%    tingui oscil-lacions es a*h/(2*nu)<1 (numero de Peclet<1)
%    Comprova-ho per a nu = 0.1 i per a nu=0.01
%
%
% 4) Dedueix la forma feble del problema i la discretitzacio i comprova que
%    correspon al sistema implementat en aquest script

a = 1; %velocitat 
nu = input('  Coeficient de difusio nu (1 per defecte)= ');
if isempty(nu), nu=1; end
numElements = input('  Numero elements (20 per defecte) = '); %numero d'elements
if isempty(numElements), numElements = 20; end

%Discretitzacio (malla)
h = 1/numElements;
x = 0:h:1; %coordenades dels nodes

%Matrius i terme independent
n = numElements-1; d = ones(n,1);
C = spdiags([-d/2,d/2],[-1,1],n,n); %discretitzacio de u_x
D = (1/h)*spdiags([-d,2*d,-d],[-1:1],n,n); %discretitzacio de u_xx
K = a*C + nu*D;
f = h*d;

%Solucio del sistema
u = K\f;

%Condicions de contorn
u = [0; u ;0];

%Postproces
figure(1), plot(x,u,'o-')
if mod(n,2)==0
    solucio_puntmig = u(n/2);
else    
    solucio_puntmig = (u((n-1)/2)+u((n+1)/2))/2;
end
fprintf('  u^h(0.5) = %0.8f\n\n',solucio_puntmig)


