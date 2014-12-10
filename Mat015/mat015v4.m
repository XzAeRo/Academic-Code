function calor(L,T,n,m,c)
    % u(x,t) = e^(-3t)sin(x) + xt
    % f(x,t) = x
    % g(x) = sin(x)
    
    % mallado
    dx=L/n;         dt=1/m;
    x = 0:dx:L;     t = 0:dt:T;
    
    lambda = c^2*dt/(dx^2);     % solo definido asi por comodidad
    
    f0 = zeros(n+1,1);          % array con valores iniciales
    U = zeros(n+1,m+1);         % matriz de resultado
    A = zeros(n+1,n+1);         % matriz tridiagonal de rigidez

    % condicion de borde y valor inicial
    for i=1:n
        f0(i,1) = sin(x(1,i));  % u(x,0) = g(x)
    end 
    f0(1,1) = 0;                % u(0,t) = 0
    f0(n+1,1) = 0;              % u(l,t) = 0

    % llenar la matriz tridiagonal con los coeficientes
    for i= 1:1:n
        A(i,i) = 1 + 2*lambda;	
        A(i,i+1) = -lambda	;	
        A(i+1, i) = -lambda	;
    end
    A(n+1,n+1) = 1+2*lambda;    % condicionar el ultimo valor
    
    U(:,1) = f0 + x'*dt;        % inicializacion de algoritmo
    for j = 1:1:m
        U(:,j+1) = A\(f0+ x'*dt); % Resolvemos Au=f0 para u
        f0 = U(:,j+1);
    end 

    % graficamos para comparar
    figure
    contour3(U)

    [xx,tt]=meshgrid(x,t);
    exact=exp(-3.*tt).*sin(xx) + xx.*tt;
    figure
    contour3(exact)

