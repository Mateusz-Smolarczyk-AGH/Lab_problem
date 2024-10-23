clear all; close all;
cd('./kolo_zamachowe/')
[K, tau] = optymalizacja();
cd('../wahadlo/')
[I, U, g, beta] = compute_parameters();
[beta, U] = optymalizacja();
cd('../')

%% 
dataFolder = fullfile('..', 'raw_data');
load(fullfile(dataFolder, 'motor_raw_with_pendulum_3.mat'));

t_real = motor_vel.time(3:end) - 0.02;
x_real = pend_angle.signals.values(3:end);
w_real = motor_vel.signals(1).values(3:end);
u_real = motor_vel.signals(2).values(3:end);

u_sim_in.time = t_real;
u_sim_in.signals.values = u_real;
u_sim_in.signals.dimensions = 1;
params = [beta, U, K, tau];

%% 
% Ustawienie parametrów symulacji
simTime = t_real(end);  % Czas symulacji w sekundach
solverStep = 0.01;  % Krok symulacji 0.01 s

% Uruchomienie symulacji z ustawieniem solvera na 'ode4' (fixed-step) i krokiem 0.01 s
simOut = sim('model_testslx_2022a.slx', ...
    'StopTime', num2str(simTime), ...        % Czas symulacji
    'Solver', 'ode4', ...                    % Solver fixed-step
    'FixedStep', num2str(solverStep));       % Krok symulacji
%% 
% Zakładam, że dane wyjściowe są w postaci struktury 'simOut' i zawierają sygnały
% np. jeśli mamy sygnał zapisany w To Workspace jako 'simout1', 'simout2', 'simout3', 'simout4' oraz 'control':
t_sim = simOut.tout;      % Czas symulacji
pend_x_sim = simOut.simout.signals.values(:,1);    % Wyjście 1
pend_w_sim = simOut.simout.signals.values(:,2);    % Wyjście 2
motor_w_sim = simOut.simout.signals.values(:,3);   % Wyjście 3
motor_a_sim = simOut.simout.signals.values(:,4);   % Wyjście 4
u_sim = simOut.simout.signals.values(:,5);         % Sterowanie

figure;

% Subplot 1: Porównanie sygnałów sterujących
subplot(3, 1, 1);
plot(t_real, u_real, 'b', 'LineWidth', 1); % Sygnał rzeczywisty
hold on;
plot(t_sim, u_sim, 'r--', 'LineWidth', 1); % Sygnał symulacyjny
title('Sygnał sterujący');
xlabel('Czas [s]');
ylabel('Sterowanie');
legend('Rzeczywisty', 'Symulacja');
grid on;
hold off;

% Subplot 2: Porównanie położenia wahadła
subplot(3, 1, 2);
plot(t_real, x_real, 'b', 'LineWidth', 1); % Sygnał rzeczywisty
hold on;
plot(t_sim, pend_x_sim, 'r--', 'LineWidth', 1); % Sygnał symulacyjny
title('Położenie wahadła');
xlabel('Czas [s]');
ylabel('Kąt [rad]');
legend('Rzeczywisty', 'Symulacja');
grid on;
hold off;

% Subplot 3: Porównanie prędkości kątowej silnika
subplot(3, 1, 3);   
plot(t_real, w_real, 'b', 'LineWidth', 1); % Sygnał rzeczywisty
hold on;
plot(t_sim, motor_w_sim, 'r', 'LineWidth', 1); % Sygnał symulacyjny
title('Prędkość kątowa koła');
xlabel('Czas [s]');
ylabel('Prędkość kątowa [rad/s]');
legend('Rzeczywisty', 'Symulacja');
grid on;
hold off;

%% 
 xep = [pi 0 0 0];
 uep = 0;
% solv = fsolve(@(x0)model(t, [xep(1) xep(2) x0(1)], x0(2), params), [xep(3); uep]);
% xep(3) = solv(1);
% uep = solv(2);
% p1 = params(5:10);
% g = 9.8105; 
% I = 0.029572173408016;
% p2 = [2.056467854285133e+02,-5.208575031241387,-1.043284835310092e+03,43.401332957404660,3.454345824430912e+03,1.802723922744937];
% mu2 = [0;0.636602825861413];
% %% 
% A = [0 1 0;
%    -4.022 -0.1859 -0.002412;
%    0 0 -1.891];
% 
%   B = [0; 0; 1.068e+04];
%  R = 1;
%  Q = [50000 0 0;
%      0 1000 0;
%      0 0 0.01];
% K_lqr = lqr(A,B,Q,R);
% %% 

