function [t_real, x_real, f] = trim_data(t_real, x_real)
    f = figure('Name', 'Select t0');
    stairs(t_real, x_real);
    legend('Real Data'); xlabel('t [s]'); ylabel('x [rad]'); grid on
    [t0, ~] = ginput(1);
    [~, i0] = min(abs(t_real - t0));
    t_real = t_real(i0:end) - t_real(i0);
    x_real = x_real(i0:end);
end

