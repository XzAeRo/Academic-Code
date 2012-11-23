function [answer] = eqHeatFD(L, h, k, a, MAX_ITER)
	
	% inicialización de variables del programa
	result = [];
	m = L/h;
	X = linspace(0,L,m);
	u_0 = zeros(1,m);
	u_j = [];

	% generamos u_0: condiciones de borde
	for i = 1:m,
		u_0(i) = (exp(2*X(i)))*sin(X(i))*cos(X(i));
	end
	
	A = zeros(m,m);
	lambda = ((a^2)*k)/(h^2);
	difference = 1-(2*lambda);

	% generamos la matriz tridiagonal A
	for i = 1:m,
		if i == 1
			A(1,i) = difference;
			A(1,i+1) = lambda;
		elseif i == m
			A(i,i) = difference;
			A(i,i-1) = lambda;
		else
			A(i,i) = difference;
			A(i,i-1) = lambda;
			A(i,i+1) = lambda;
	end
	
	u_prev = u_0; % copiamos u_0 para efectos de algoritmo

	% realizamos el método de forward difference
	for i = 1:MAX_ITER,
		u_j = A*u_prev';		
		u_j2 = u_j';
		
		u_j(1) = 0;
		u_j(m) = 0;
		
		local_dif = u_j' - u_prev;
		result(:,i) = u_prev;
		u_prev = u_j2;		
		
		% si nos aproximamos lo suficiente nos detenemos
		if max(abs(local_dif)) <= (1.1*10^(-4))
			result(:,i) = u_prev;
			answer = false;
			break
		end
	end
	
	answer = true;
end
