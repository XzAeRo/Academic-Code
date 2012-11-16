function [ X, Y ] = partition( xi,xf, n )

xp = linspace(xi,xf,n);
yp = xp;
[X,Y] = meshgrid(xp,yp);

end

