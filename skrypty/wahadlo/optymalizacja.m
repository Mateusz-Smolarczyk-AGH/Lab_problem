function [beta, U] = optymalizacja()
    % Pobranie ścieżki do folderu z danymi
    scriptPath = mfilename('fullpath');  
    [scriptDir, ~, ~] = fileparts(scriptPath);  
    dataFolder = fullfile(scriptDir, '..', '..', 'data');

    % Załaduj dane rzeczywiste (przebieg 2)
    data = load(fullfile(dataFolder, 'wahadlo_swobodny_przebieg_1.mat'));
    t_real = data.x;
    x_real = data.y;
    
    % Warunki początkowe
    x0 = [x_real(1), 0];
    
    % Optymalizacja parametrów modelu
    params = optimize_model(t_real, x_real, x0);
    
    % Wizualizacja wyników optymalizacji
    f_optim = figure('Name', 'Optymalizacja modelu wahadła');
    subplot(2, 1, 1);
    stairs(t_real, x_real); hold on;
    [t, x] = ode45(@(t, x) model_wahadlo(t, x, 0, params), t_real, x0);
    stairs(t, x(:, 1));
    legend('Real', 'Model');
    title('Model wahadła po optymalizacji');
    
    % Weryfikacja modelu na innych danych (przebieg 1)
    data = load(fullfile(dataFolder, 'wahadlo_swobodny_przebieg_2.mat'));
    t_real = data.x;
    x_real = data.y;
    x0 = [x_real(1), 0];
    
    % Wizualizacja weryfikacji modelu
    subplot(2, 1, 2);
    stairs(t_real, x_real); hold on;
    [t, x] = ode45(@(t, x) model_wahadlo(t, x, 0, params), t_real, x0);
    stairs(t, x(:, 1)); hold off;
    legend('Real', 'Model');
    title('Weryfikacja modelu z innym przebiegiem');
    
    % Zwróć zoptymalizowane parametry
    beta = params(1);
    U = params(2);
end