[xx,yy]=meshgrid([0:2:40],[0:2:20]); [n,m]=size(xx);
xs=reshape(xx,n*m,1); ys=reshape(yy,n*m,1);
v = velocityField([xs,ys]);
quiver(xs,ys,v(:,1),v(:,2))
title(sprintf('  Maximum modulus of velocity=%0.1f\n',max(sqrt(v(:,1).^2+v(:,2).^2))))