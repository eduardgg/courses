function [ d2s ] = calculaCurvaturesSplineNatural_JoaquimBrugues( x,y )
%CALCULACURVATURESSPLINENATURAL: calcula les curvatures als punts base per
%a l'spline natural donat per x, y.

    h=x(2:end)-x(1:end-1);
    t=y(2:end)-y(1:end-1);
    n = max(size(x));
    l = [0, h(2:end-1)./(h(2:end-1)+h(1:end-2))];
    mu = [ h(2:end-1)./(h(2:end-1)+h(3:end)), 0];
    d = 6*(t(2:end)./h(2:end)-t(1:end-1)./h(1:end-1))./(h(2:end)+h(1:end-1));
    d = d';
    A = spdiags([mu' 2*ones(n-2,1) l'],-1:1,n-2,n-2);
    d2s = A\d;
    d2s = [0 d2s' 0];
    A
    d
end

