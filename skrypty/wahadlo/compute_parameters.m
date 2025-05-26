function [I, U, g, beta] = compute_parameters()

    % Wczytanie ścieżki do pliku
    scriptPath = mfilename('fullpath');  % Pełna ścieżka do tego pliku skryptu
    [scriptDir, ~, ~] = fileparts(scriptPath);  % Katalog skryptu
    dataFolder = fullfile(scriptDir, '..');
    dataFolder = fullfile(dataFolder, '..', 'data');
    file_list = {'wahadlo_swobodny_przebieg_1.mat', 'wahadlo_swobodny_przebieg_2.mat', 'wahadlo_swobodny_przebieg_3.mat'}; 
    
    % Inicjalizacja zmiennych do przechowywania danych zbiorczych
    all_periods = [];
    all_alpha = [];
    
    figure; % Tworzymy nowy rysunek
    tiledlayout(length(file_list), 1); % Ustawiamy układ wykresów
    
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
        
        % Logarytmowanie maksimów i dopasowanie wykładnicze
        log_peaks = log(peaks);
        coeffs = polyfit(locs, log_peaks, 1); % Dopasowanie 1-wymiarowego wielomianu (liniowego)
        alpha = -coeffs(1);
        all_alpha = [all_alpha; alpha];
        
        % Rysowanie sygnału i lokalnych maksimów
        nexttile; % Nowy podział na kafelki
        plot(data.x, data.y, 'b-', 'DisplayName', 'Sygnał'); hold on;
        plot(locs, peaks, 'ro', 'DisplayName', 'Maksima');
        plot(data.x, exp(coeffs(1)*data.x + coeffs(2)), 'g--', 'DisplayName', 'Dopasowanie wykładnicze');
        title([sprintf('\\beta = %.4f', alpha)]);
        xlabel('Czas [s]');
        ylabel('Amplituda');
        legend('show');
        grid on;
        
%         % Dodanie wartości alpha na wykresie
%         text_position_x = locs(end) - (locs(end) - locs(1)) * 0.1; % Ustawienie tekstu na 10% szerokości od końca
%         text_position_y = max(peaks) * 0.8; % Ustawienie tekstu na 80% wysokości maksymalnej amplitudy
%         text(text_position_x, text_position_y, sprintf('\\alpha = %.4f', alpha), ...
%              'Color', 'red', 'FontSize', 12, 'FontWeight', 'bold');
    end
    
    % Oblicz średni okres i średnie alpha
    total_average_period = mean(all_periods);
    total_average_alpha = mean(all_alpha);
    beta = total_average_alpha;
    T = total_average_period;
    
    % Stałe
    g = 9.8105; 
    U = (0.151 * 0.178)/sin(pi/2);
    I = (T/(2*pi))^2 * U * g;
    
    % Wyświetlanie wyników na konsoli
    disp('Średni okres T:');
    disp(T);
    disp('Współczynnik tłumienia beta:');
    disp(beta);
    disp('Moment bezwładności I:');
    disp(I);
    disp('Moment siły U:');
    disp(U);
end
