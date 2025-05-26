clear all; close all;

cd('./kolo_zamachowe/')
% [K, tau] = optymalizacja();

cd('../wahadlo/')
[I, U, g, beta] = compute_parameters();
[beta, U] = optymalizacja();
cd('../')

%% 
dataFolder = fullfile('..', 'raw_data');
load(fullfile(dataFolder, 'motor_raw_with_pendulum_4.mat'));

t_real = motor_vel.time(3:end) - 0.02;
x_real = pend_angle.signals.values(3:end);
w_real = motor_vel.signals(1).values(3:end);
u_real = motor_vel.signals(2).values(3:end)/2;
% t_real = StateData.time(3:end) - 0.02;
% x_real = StateData.signals(3).values(3:end);
% w_real = StateData.signals(6).values(3:end);
% u_real = 2 * StateData.signals(1).values(3:end);

u_sim_in.time = t_real;
u_sim_in.signals.values = u_real;
u_sim_in.signals.dimensions = 1;
params = [beta, U, K, tau];

%% 
% Ustawienie parametrów symulacji
simTime = t_real(end);  % Czas symulacji w sekundach
solverStep = 0.01;  % Krok symulacji 0.01 s

% Uruchomienie symulacji z ustawieniem solvera na 'ode4' (fixed-step) i krokiem 0.01 s
simOut = sim('model_testslx_2015a.slx', ...
    'StopTime', num2str(simTime), ...        % Czas symulacji
    'Solver', 'ode4', ...                    % Solver fixed-step
    'FixedStep', num2str(solverStep));       % Krok symulacji
    %% 
x0 = [x_real(1); 0; w_real(1)];
[t, x] = ode45(@(t, x) model(t, x, u_real(1+int16(100*t)), params), t_real, x0);
figure('Name', 'Ostateczny model wahadła', 'Position', [50 50 800 900]);
subplot(3, 1, 1)
stairs(t_real, x_real); hold on
stairs(t, x(:, 1));
legend('Obiekt', 'Model'); title('Wychylenie wahadła')
ylabel('położenie [rad]');
xlabel('czas [s]');

subplot(3, 1, 2)
stairs(t_real, w_real); hold on
stairs(t, x(:, 3))
legend('Obiekt', 'Model'); title('Prędkość obrotowa koła zamachowego')
ylabel('prędkość [rad/s]');
xlabel('czas [s]');
subplot(3, 1, 3)
stairs(t_real, u_real); title('Sygnał sterujący')
legend('Sterowanie');
ylabel('sterowanie');
xlabel('czas [s]');
%%
t_liniowy = out.liniowy.time();
x_liniowy = out.liniowy.signals(1).values;
w_liniowy = out.liniowy.signals(3).values;

figure('Name', 'Ostateczny model wahadła', 'Position', [50 50 800 900]);
subplot(3, 1, 1)
stairs(t_real, x_real); hold on
stairs(t, x(:, 1), 'g', 'LineWidth', 1);

stairs(t_liniowy, x_liniowy, 'r--', 'LineWidth', 1);
legend('Obiekt', 'Model', 'Linearyzacja'); title('Wychylenie wahadła')
ylabel('położenie [rad]');
xlabel('czas [s]');

subplot(3, 1, 2)
stairs(t_real, w_real); hold on
stairs(t, x(:, 3), 'g', 'LineWidth', 1)

stairs(t_liniowy, w_liniowy, 'r--', 'LineWidth', 1);

legend('Obiekt', 'Model', 'Linearyzacja'); title('Prędkość obrotowa koła zamachowego')
ylabel('prędkość [rad/s]');
xlabel('czas [s]');
subplot(3, 1, 3)
stairs(t_real, u_real); title('Sygnał sterujący')
legend('Sterowanie');
ylabel('sterowanie');
xlabel('czas [s]');
%% 
% Zakładam, że dane wyjściowe są w postaci struktury 'simOut' i zawierają sygnały
% np. jeśli mamy sygnał zapisany w To Workspace jako 'simout1', 'simout2', 'simout3', 'simout4' oraz 'control':
t_sim = simOut.tout;      % Czas symulacji
pend_x_sim = simOut.simout.signals.values(:,1);    % Wyjście 1
pend_w_sim = simOut.simout.signals.values(:,2);    % Wyjście 2
motor_w_sim = simOut.simout.signals.values(:,3);   % Wyjście 3
% u_sim = simOut.simout.signals.values(:,5);         % Sterowanie

figure;

% Subplot 1: Porównanie sygnałów sterujących
subplot(3, 1, 1);
plot(t_real, u_real, 'b', 'LineWidth', 1); % Sygnał rzeczywisty
hold on;
plot(t_sim, u_real, 'r--', 'LineWidth', 1); % Sygnał symulacyjny
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
xep = [pi 0 0];
uep = 0;
solv = fsolve(@(x0)model(t, [xep(1) xep(2) x0(1)], x0(2), params), [xep(3); uep]);
xep(3) = solv(1);
uep = solv(2);
% p1 = params(5:10);
% g = 9.8105; 
% I = 0.029572173408016;
% p2 = [2.056467854285133e+02,-5.208575031241387,-1.043284835310092e+03,43.401332957404660,3.454345824430912e+03,1.802723922744937];
% mu2 = [0;0.636602825861413];
% %% 
%% 
A = [0 1 0;
   -12.34 -1.173 0.01033;
   0 0 -1.004];

 B = [0; -4.414; 428.9];
 C = [1 0 0;
   0 1 0 ;
   0 0 1];

 D = [0; 0; 0];
 
 R = 1;
 Q = [5000 0 0;
     0 100 0;
     0 0 0.1];
K_lqr = lqr(A,B,Q,R);
% %% 

