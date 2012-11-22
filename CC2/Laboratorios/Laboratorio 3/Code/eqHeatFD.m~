function [result] = eqHeatFD(L, h, k, a, MAX_ITER)
	
	result = [];
	m = L/h;

%Se genera la partición de L con los m valores correspondientes a los X_i.
	X = linspace(0,L,m);
	u_0 = zeros(1,m);
	u_j = [];

%Se evaluan los X_i en la funcion de la condicion de borde para generar
%el vector U_0 inicial.
	for i = 1:m,
		u_0(i) = (exp(2*X(i)))*sin(X(i))*cos(X(i));
	end

%Se crea la matriz tridiagonal A.
	A = zeros(m,m);
	lambda = ((a^2)*k)/(h^2);
	dif = 1-(2*lambda);
	
	for i = 1:m,
		if i == 1
			A(1,i) = dif;
			A(1,i+1) = lambda;
		elseif i == m
			A(i,i) = dif;
			A(i,i-1) = lambda;
		else
			A(i,i) = dif;
			A(i,i-1) = lambda;
			A(i,i+1) = lambda;
	end
	
	u_ant = u_0;

	%Se ejecuta lo que aparece en el pseudo-codigo desde la linea 5
	%hasta la linea 12.
	for iter = 1:MAX_ITER,
		u_j = A*u_ant';		
		u_j2 = u_j';
		
		u_j(1) = 0;
		u_j(m) = 0;
		
		diferencia = u_j' - u_ant;
		
		result(:,iter) = u_ant;
		
		u_ant = u_j2;		
		
		if max(abs(diferencia)) <= (1.1*10^(-4))
			result(:,iter) = u_ant;
			iter;
			break
		end
	end
end
