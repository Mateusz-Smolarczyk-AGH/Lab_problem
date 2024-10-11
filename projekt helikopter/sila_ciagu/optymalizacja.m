function [p, mu] = optymalizacja()
    data = load('charakterystyka_statyczna.mat');
    w = data.charakterystyka_statyczna.w;
    F = data.charakterystyka_statyczna.F;
    
    % Optimize -> 7 degree polynomial fit
    [p,~,mu] = polyfit(w,F,5);
    % Plot
    w_poly = linspace(min(w),max(w),1000);
    F_poly = polyval(p,w_poly,[],mu);
    figure();
    plot(w, F,'o'); hold on
    plot(w_poly,F_poly); hold off
    title('Aproksymacja funkcji siły ciągu'); legend('Real Data', 'Polynomial fit'); xlabel('w [rad]'); ylabel('F [N]'); grid on
end