function dxdt = model(t, x, u, params)
    beta = params(1); U = params(2); K = params(3); tau = params(4);
    g = 9.8105; 
    I = 0.0226;    
    I_kola = 0.000232559;

    dx3 = ((K * (423.21*u + 0.953) - x(3)) / tau);

    dx1 = x(2);
    dx2 =  (-g * U * sin(x(1)) - beta * x(2) - dx3 * I_kola) / I;

    dxdt = [dx1; dx2; dx3];
end

