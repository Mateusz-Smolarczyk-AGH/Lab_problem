function [p, mu] = optymalizacja()
    data = load('char_sterowanie.mat');
    w = data.w;
    u = data.u;
    
    % Optimize -> 7 degree polynomial fit
    [p,~,mu] = polyfit(u, w, 5);
    
    % Plot
    u_poly = linspace(min(u), max(u), 1000);
    w_poly = polyval(p, u_poly, [], mu);
    figure();
    plot(u, w,'o'); hold on
    plot(u_poly, w_poly); hold off
    title('Aproksymacja funkcji siły ciągu'); legend('Real Data', 'Polynomial fit'); xlabel('w [rad]'); ylabel('F [N]'); grid on
end