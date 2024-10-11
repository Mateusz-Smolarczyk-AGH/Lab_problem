function loss = cost_fun(x_real, t_real, x0, u, params)
    [~, x] = ode45(@(t, x)model_wiatrak(t, x, u(1+int16(100*t)), params), t_real, x0);
    loss = sum(abs(x - x_real));
end

