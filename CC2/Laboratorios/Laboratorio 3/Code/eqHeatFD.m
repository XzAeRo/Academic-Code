% Completar de acuerdo al enunciado.
function [result] = eqHeatFD(L, h, k, a)

	[X,Y] = partition(0,L,L/h);

	% condiciones de borde para u_0
	u_0 = zeros(1,L/h);
	u_j = [];
	for i = 1:((L/h)),
		x_i = X(1,i);
		u_0(i) = (e**(2*x_i))*sin(x_i)*cos(x_i);
	end
	[u_j] = [u_j;u_0];

	% matriz A
	A = zeros(L/h,L/h);
	lambda = (a*a*k)/(h*h);
	l = 1-(2*lambda);
	for i = 1:(L/h),
		% matriz A
		if i == 1
			A(1,1) = l;
			A(1,2) = lambda;
		elseif i== (L/h)
			A(i,i) = l;
			A(i,i-1) = lambda;
		else
			A(i,i) = l;
			A(i,i+1) = lambda;
			A(i,i-1) = lambda;
	end

	MAX_ITER = 20;

	for i=1:MAX_ITER,
		uj_1 = repmat(u_j(i,:), L/h, 1);
		uj = A.*uj_1;
		[u_j] = [u_j,uj.'];
		uj(0) = 0;
		uj(L/h) = 0;
	end
	result = u_j;
end
