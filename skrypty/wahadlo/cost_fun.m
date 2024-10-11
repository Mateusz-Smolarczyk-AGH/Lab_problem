function loss = cost_fun(x_real, t_real, x0, params)
    [~, y] = ode45(@(t, x)model_wahadlo(t, x, 0, params), t_real, x0);
    loss = sum((y(:, 1) - x_real).^2);
end

