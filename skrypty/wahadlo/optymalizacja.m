function [beta, U] = optymalizacja()
    scriptPath = mfilename('fullpath');  % Pełna ścieżka do tego pliku skryptu
    [scriptDir, ~, ~] = fileparts(scriptPath);  % Katalog skryptu
    dataFolder = fullfile(scriptDir, '..');
    dataFolder = fullfile(dataFolder, '..', 'data');
    data = load(fullfile(dataFolder, 'wahadlo_swobodny_przebieg_2.mat'));
%     t_real = pend_angle.time;
%     x_real = pend_angle.signals.values;
    t_real = data.x;
    x_real = data.y;

%     % Select time range
%     [t_real, x_real, f_sel] = trim_data(t_real, x_real);
%     clf;
%     stairs(t_real, x_real);
%     legend('Real Data'); xlabel('t [s]'); ylabel('x [rad]'); grid on
    x0 = [x_real(1), 0];
%     fprintf("Warunek początkowy %g\n", x0)
    
    % Optimize
    params = optimize_model(t_real, x_real, x0);
    f_optim = figure('Name', 'Optymalizacja modelu wahadła');
    subplot(2, 1, 1)
    stairs(t_real, x_real); hold on
    [t, x] = ode45(@(t, x)model_wahadlo(t, x, 0, params), t_real, x0);
    stairs(t, x(:, 1))
    legend('Real', 'Model'); title('Model wahadła po optymalizacji')
    
    % Compare
    data = load(fullfile(dataFolder, 'wahadlo_swobodny_przebieg_1.mat'));
%     t_real = pend_angle.time;
%     x_real = pend_angle.signals.values;
    t_real = data.x;
    x_real = data.y;

    x0 = [x_real(1), 0];
    figure(f_optim)
    subplot(2, 1, 2)
    stairs(t_real, x_real); hold on
    [t, x] = ode45(@(t, x)model_wahadlo(t, x, 0, params), t_real, x0);
    stairs(t, x(:, 1)); hold off
    legend('Real', 'Model'); title('Weryfikacja modelu z innym przebiegiem')
    beta = params(1); U = params(2);
%     figure(f_optim);
%     stairs(t_real, x_real);
%     legend('Położenie wahadła'); xlabel('t [s]'); ylabel('x [rad]'); grid on
%     title('Przebieg położenia wahadła');
end



