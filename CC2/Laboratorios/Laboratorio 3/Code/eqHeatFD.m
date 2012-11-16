% Completar de acuerdo al enunciado.
function [result] = eqHeatFD(L, h, k, a)

[X,X_c] = partition(0,L,L/h);
[Y,Y_c] = partition(0,L,L/k);

u_0 = zeros(1,L/h)

for i=1:((L/h)),
	x_i = X(1,i);
	u_0(i) = (e**(2*x_i))*sin(x_i)*cos(x_i);
end

result = u_0;
end

