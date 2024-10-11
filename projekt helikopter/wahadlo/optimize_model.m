function params = optimize_model(t_real, x_real, x0)
    cost_parametrized = @(params) cost_fun(x_real, t_real, x0, params);
    options = optimoptions('fmincon','Display','iter', 'PlotFcn', 'optimplotfval', 'UseParallel',true);
    initial_params = [0.2, 0.02]; %
    lb = [0.0 0.0]; ub = [1.0 0.5];
    params = fmincon(cost_parametrized, initial_params, [], [], [], [], lb, ub, [], options);
end

