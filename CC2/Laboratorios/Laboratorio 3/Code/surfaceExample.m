function []  = surface( )
%SURFACE Summary of this function goes here
%   Detailed explanation goes here

x = 0:30;
y = x; 
[X, Y] = meshgrid(x, y);
Z = X.^2.*Y.^2; 
 surf(X, Y, Z);
end

