clear all; close all;
cd('../wiatrak/')
[K, tau] = optymalizacja();
cd('../sila_ciagu/')
[p1, mu1] = optymalizacja();
cd('../wahadlo/')   
[beta, U] = optymalizacja();
cd('../kompletny_model/')

%% 
addpath('../wiatrak/')
addpath('../sila_ciagu/')
addpath('../wahadlo/')

data = load('weryfikacja_calosc3.mat');
t_real = data.ScopeData.time;
x_real = data.ScopeData.signals(4).values;
w_real = data.ScopeData.signals(5).values;
u = data.ScopeData.signals(7).values;
u_sim.time = t_real;
u_sim.signals.values = u;
u_sim.signals.dimensions = 1;
params = [beta, U, K, tau, p1, mu1'];

x0 = [x_real(1); 0; w_real(1)];
[t, x] = ode45(@(t, x) model(t, x, u(1+int16(100*t)), params), t_real, x0);
figure('Name', 'Ostateczny model helikoptera', 'Position', [50 50 800 900]);
subplot(3, 1, 1)
stairs(t_real, x_real); hold on
stairs(t, x(:, 1));
legend('Real', 'Model'); title('Wychylenie wahadła')
subplot(3, 1, 2)
stairs(t_real, data.ScopeData.signals(5).values); hold on
stairs(t, x(:, 3))
legend('Real', 'Model'); title('Prędkość obrotowa wiatraka')
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

