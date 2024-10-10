function f=sourceTerm(X) 

x=X(:,1); y=X(:,2);

f = 0*x;

% %gaussian centred at (x0,y0)
% x0=5;y0=10;
% r2 = ((x-x0).^2+(y-y0).^2);
% f=10^2*exp(-r2/2);
