function dxdt = model_wahadlo(t, x, F, params)
    beta = params(1); 
    U = params(2);
    
    % Parametry na podstawie skryptu compute_parameters.m
    g = 9.8105; 
    I = 0.022597943261201;

    % Równania ruchu wahadła
    dx1 = x(2);
    dx2 = (-g * U * sin(x(1)) - beta * x(2) + F * 0.178) / I;
    
    % Zwróć pochodne stanu
    dxdt = [dx1; dx2];
end
