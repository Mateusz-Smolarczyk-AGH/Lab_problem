clear all;
file_list = {'wahadlo_swobodny_przebieg_1.mat', 'wahadlo_swobodny_przebieg_2.mat', 'wahadlo_swobodny_przebieg_3.mat'}; 

% Inicjalizacja zmiennej do przechowywania wszystkich okresów
all_periods = [];
all_alha = [];
% Pętla przez każdy plik
for i = 1:length(file_list)
    % Załaduj dane z pliku
    data = load(file_list{i});
    
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
alfa = total_average_alpha;
T = total_average_period;
g = 9.8105; 
U = (0.151 * 0.178)/sin(pi/2);
I = (T/(2*pi))*(T/(2*pi))*U*g;