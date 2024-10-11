function params = optimize_model(t_real, x_real, x0, u)
    cost_parametrized = @(params) cost_fun(x_real, t_real, x0, u, params);
    options = optimoptions('fmincon','Display','iter', 'PlotFcn', 'optimplotfval', 'UseParallel',true, 'StepTolerance', 1e-12);
    initial_params = [1, 0.2]; %
    lb = [0.0 0.0]; ub = [5000 1];
    params = fmincon(cost_parametrized, initial_params, [], [], [], [], lb, ub, [], options);
end

