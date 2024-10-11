function [K, tau] = optymalizacja()
    data = load('weryfikacja_calosc2.mat');
    t_real = data.ScopeData.time;
    x_real = data.ScopeData.signals(5).values;
    u = data.ScopeData.signals(7).values;
    
    % Nie ma chyba potrzeby tu przycinać zarejestrowanych danych
    % Select time range
    % [t_real, x_real, f_sel] = trim_data(t_real, x_real);
    % clf;
    % stairs(t_real, x_real);
    % stairs(t_real, u)
    % legend('Real Data'); xlabel('t [s]'); grid on
    x0 = x_real(1);
    fprintf("Warunek początkowy %g\n", x0)
    
    % Optimize
    params = optimize_model(t_real, x_real, x0, u);
    f_optim = figure('Name', 'Optymalizacja modelu wiatraka');
    subplot(2, 1, 1)
    stairs(t_real, x_real); hold on
    [t, x] = ode45(@(t, x)model_wiatrak(t, x, u(1+int16(100*t)), params), t_real, x0);
    stairs(t, x(:, 1))
    legend('Real', 'Model'); title('Model po optymalizacji')
    
    % Compare
    data = load('pomiar_wiatrak2.mat');
    t_real = data.ScopeData.time;
    x_real = data.ScopeData.signals(5).values;
    u = data.ScopeData.signals(7).values;
    x0 = x_real(1);
    figure(f_optim)
    subplot(2, 1, 2)
    stairs(t_real, x_real); hold on
    [t, x] = ode45(@(t, x)model_wiatrak(t, x, u(1+int16(100*t)), params), t_real, x0);
    stairs(t, x(:, 1))
    legend('Real', 'Model'); title('Weryfikacja modelu z innym przebiegiem')

    K = params(1); tau = params(2);
end



