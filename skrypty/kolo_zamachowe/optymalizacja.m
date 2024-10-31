function [K, tau] = optymalizacja()
    % Pobierz ścieżkę do bieżącego skryptu
    scriptPath = mfilename('fullpath');  
    [scriptDir, ~, ~] = fileparts(scriptPath);  
    
    % Ścieżka do folderu z danymi
    dataFolder = fullfile(scriptDir, '..', '..', 'raw_data');

    % Załaduj dane
    data = load(fullfile(dataFolder, 'motor_raw_with_pendulum_3.mat'));
    t_real = data.motor_vel.time(3:end) - 0.02;
    x_real = data.motor_vel.signals(1).values(3:end);
    u = data.motor_vel.signals(2).values(3:end);
    
    x0 = x_real(1);
    fprintf("Warunek początkowy: %g\n", x0);
    
    % Optymalizacja parametrów modelu
    params = optimize_model(t_real, x_real, x0, u);
    
    % Porównanie wyników optymalizacji
    f_optim = figure('Name', 'Optymalizacja modelu wiatraka');
    subplot(2, 1, 1);
    stairs(t_real, x_real); hold on;
    [t, x] = ode45(@(t, x) model_wiatrak(t, x, u(1 + int16(100 * t)), params), t_real, x0);
    stairs(t, x(:, 1));
    legend('Real', 'Model');
    title('Model po optymalizacji');
    
    % Weryfikacja modelu na innych danych
    data = load(fullfile(dataFolder, 'motor_raw_with_pendulum_4.mat'));
    t_real = data.motor_vel.time(3:end) - 0.02;
    x_real = data.motor_vel.signals(1).values(3:end);
    u = data.motor_vel.signals(2).values(3:end);
    x0 = x_real(1);
    
    subplot(2, 1, 2);
    stairs(t_real, x_real); hold on;
    [t, x] = ode45(@(t, x) model_wiatrak(t, x, u(1 + int16(100 * t)), params), t_real, x0);
    stairs(t, x(:, 1));
    legend('Real', 'Model');
    title('Weryfikacja modelu z innym przebiegiem');

    % Zwróć zoptymalizowane parametry
    K = params(1);
    tau = params(2);
end