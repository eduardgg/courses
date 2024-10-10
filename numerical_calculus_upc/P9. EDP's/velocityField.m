function v=velocityField(X)
x=X(:,1); y=X(:,2);

%%v(x,y)=(10,0) km/h
%v = [10+0*x,0*x];

%rotation centred at (x0,y0)
x0=20; y0=-20;
Px = x-x0; Py= y-y0;  
r=sqrt(Px.^2+Py.^2);
v = (5/45)*[Py,-Px];
%v=0*v;




