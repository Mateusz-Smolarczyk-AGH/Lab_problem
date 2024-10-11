function dxdt = model_wahadlo(t, x, F, params)
    % U = 0.016465909059109;
    g = 9.8105; 
    % beta = 0.377950000000000;
    I = 0.029572173408016;
    % beta = 0.01;
    % F = 0.0; % u = 0.3
    beta = params(1);
    U = params(2);

    dx1 = x(2);
    dx2 =  (-g * U * sin(x(1)) - beta * x(2) + F * 0.235) / I;

    dxdt = [dx1; dx2];
end
