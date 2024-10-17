clear all; close all;
cd('./wahadlo/')
[I, U, g, beta] = compute_parameters();
[beta, U] = optymalizacja();
cd('../kolo_zamachowe/')
[K, tau] = optymalizacja();

%% 
% scriptPath = mfilename('fullpath');  % Pełna ścieżka do tego pliku skryptu
% [scriptDir, ~, ~] = fileparts(scriptPath);  % Katalog skryptu
% dataFolder = fullfile(dataFolder, '..', 'raw_data');
% data = load(fullfile(dataFolder, 'motor_raw_with_pendulum_5.mat'));

t_real = motor_vel.time(3:end) - 0.02;
x_real = pend_angle.signals.values(3:end);
w_real = motor_vel.signals(1).values(3:end);
u = motor_vel.signals(2).values(3:end);
u_sim.time = t_real;
u_sim.signals.values = u;
u_sim.signals.dimensions = 1;
params = [beta, U, K, tau];


%% 
% Uruchom symulację modelu
simOut = sim('model_testslx.slx');
y1 = simOut.simout1.signals.values(:,1);   % Wyjście 1

% Wykres wyjścia 1
subplot(5,1,1);
plot(t, y1);
xlabel('Czas (s)');
ylabel('Wyjście 1');
title('Wykres wyjścia 1');
grid on;
%% 

% Zakładam, że dane wyjściowe są w postaci struktury 'simOut' i zawierają sygnały
% np. jeśli mamy sygnał zapisany w To Workspace jako 'simout1', 'simout2', 'simout3', 'simout4' oraz 'control':
t = simOut.tout;      % Czas symulacji
y1 = simOut.simout.signals.values(:,1);   % Wyjście 1
y2 = simOut.simout.signals.values(:,2);   % Wyjście 2
y3 = simOut.simout.signals.values(:,3);   % Wyjście 3
y4 = simOut.simout.signals.values(:,4);   % Wyjście 4

% Stwórz figurę z 5 wykresami
figure;

% Wykres wyjścia 1
subplot(5,1,1);
plot(t, y1);
xlabel('Czas (s)');
ylabel('Wyjście 1');
title('Wykres wyjścia 1');
grid on;

% Wykres wyjścia 2
subplot(5,1,2);
plot(t, y2);
xlabel('Czas (s)');
ylabel('Wyjście 2');
title('Wykres wyjścia 2');
grid on;

% Wykres wyjścia 3
subplot(5,1,3);
plot(t, y3);
xlabel('Czas (s)');
ylabel('Wyjście 3');
title('Wykres wyjścia 3');
grid on;

% Wykres wyjścia 4
subplot(5,1,4);
plot(t, y4);
xlabel('Czas (s)');
ylabel('Wyjście 4');
title('Wykres wyjścia 4');
grid on;

% % Wykres sterowania
% subplot(5,1,5);
% plot(t, u_sim);
% xlabel('Czas (s)');
% ylabel('Sterowanie');
% title('Wykres sterowania');
% grid on;

%% 

% x0 = [x_real(1); 0; w_real(1); 0];
% [t, x] = ode45(@(t, x) model(t, x, u(1+int16(100*t)), params), t_real, x0);
figure('Name', 'Ostateczny model wachadla', 'Position', [50 50 800 900]);
subplot(3, 1, 1)
stairs(t_real, x_real); hold on
stairs(t, x(:, 1));
legend('Real', 'Model'); title('Wychylenie wahadła')
subplot(3, 1, 2)
stairs(t_real, data.ScopeData.signals(5).values); hold on
stairs(t, x(:, 3))
legend('Real', 'Model'); title('Prędkość obrotowa koła')
subplot(3, 1, 3)
stairs(t_real, u); title('Sygnał sterujący')

%% 
xep = [deg2rad(-2*21.37) 0 2000];
uep = 0;
solv = fsolve(@(x0)model(t, [xep(1) xep(2) x0(1)], x0(2), params), [xep(3); uep]);
xep(3) = solv(1);
uep = solv(2);
p1 = params(5:10);
g = 9.8105; 
I = 0.029572173408016;
p2 = [2.056467854285133e+02,-5.208575031241387,-1.043284835310092e+03,43.401332957404660,3.454345824430912e+03,1.802723922744937];
mu2 = [0;0.636602825861413];
%% 
A = [0 1 0;
   -4.022 -0.1859 -0.002412;
   0 0 -1.891];
 
  B = [0; 0; 1.068e+04];
 R = 1;
 Q = [50000 0 0;
     0 1000 0;
     0 0 0.01];
K_lqr = lqr(A,B,Q,R);
%% 

