function [I, U, g, beta] = compute_parameters()

    %wczytanie ścieżki do pliku
    scriptPath = mfilename('fullpath');  % Pełna ścieżka do tego pliku skryptu
    [scriptDir, ~, ~] = fileparts(scriptPath);  % Katalog skryptu
    dataFolder = fullfile(scriptDir, '..');
    dataFolder = fullfile(dataFolder, '..', 'data');
    file_list = {'wahadlo_swobodny_przebieg_1.mat', 'wahadlo_swobodny_przebieg_2.mat', 'wahadlo_swobodny_przebieg_3.mat'}; 
    
    % Inicjalizacja zmiennej do przechowywania wszystkich okresów
    all_periods = [];
    all_alha = [];
    % Pętla przez każdy plik
    for i = 1:length(file_list) 
        % Załaduj dane z pliku
        matFilePath = fullfile(dataFolder, file_list{i});
        data = load(matFilePath);
        
        % Znajdź lokalne maksima sygnału (zakładamy, że dane to x = czas i y = sygnał)
        [peaks, locs] = findpeaks(data.y, data.x);
        
        % Oblicz różnice między kolejnymi maksimami (okresy)
        periods = diff(locs);
        
        % Dodaj obliczone okresy do zbiorczej listy
        all_periods = [all_periods; periods];
    
        log_peaks = log(peaks);
        coeffs = polyfit(locs, log_peaks, 1); % Dopasowanie 1-wymiarowego wielomianu (liniowego)
        alpha = -coeffs(1);
        all_alha = [all_alha; alpha];
    
    end
    
    % Oblicz średni okres na podstawie wszystkich okresów
    total_average_period = mean(all_periods);
    total_average_alpha = mean(all_alha);
    beta = total_average_alpha;
    T = total_average_period;
    g = 9.8105; 
    U = (0.151 * 0.178)/sin(pi/2);
    I = (T/(2*pi))*(T/(2*pi))*U*g;
end