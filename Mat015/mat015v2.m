function calor(T,l,dt,dx,c)
    % u(x,t) = e^(-3t)sin(x) + xt
    % f(x,t) = x
    % g(x) = sin(x)

    n      = (T-0)/dt;
    m      = (l-0)/dx;
    lambda = c^2*dt/dx^2        % lambda debe ser menor a 1
    u      = zeros(m+1,n+1);

    x = 0:dx:l;
    t = 0:dt:T;

    for j=1:m+1,
        u(j,1) = sin(x(j));     % u(x,0) = g(x)
    end

    for k=1:n
        u(1,k+1)=0.;            % u(0,t) = 0
        for j=2:m
            u(j,k+1)=u(j,k)+lambda*(u(j+1,k)-2*u(j,k)+u(j-1,k))+dt*x(j);
        end
        u(m+1,k+1)=0.;          % u(l,t) = 0
    end

    % comparacion con resultado real
    %for j=1:m
    %    for k=1:n
    %        [j k x(j) t(k) u(j,k) exp(-3*t(k))*sin(x(j))+x(j)*t(k)]
    %    end
    %end
    
    [xx,tt]=meshgrid(x,t);
    exact=exp(-3.*tt).*sin(xx) + xx.*tt;


    [u(:,end) exact(end,:)']
    
    figure
    contour3(u)
    
    figure
    contour3(exact)
   