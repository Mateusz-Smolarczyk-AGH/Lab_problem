function dxdt = model(t, x, u, params)
    beta = params(1); U = params(2); K = params(3); tau = params(4);
    p1 = params(5:10); mu1 = params(11:end);
    p2 = [2.056467854285133e+02,-5.208575031241387,-1.043284835310092e+03,43.401332957404660,3.454345824430912e+03,1.802723922744937];
    mu2 = [0;0.636602825861413];
    f_u = polyval(p2, u, [], mu2);

    g = 9.8105; 
    I = 0.029572173408016;
    
    F = polyval(p1, x(3),[],mu1);
    F = min(max(F,-0.65),0.8);
    
    dx1 = x(2);
    dx2 =  (-g * U * sin(x(1)) - beta * x(2) - F * 0.235) / I;
    dx3 = (K * f_u - x(3)) / tau;
    
    dxdt = [dx1; dx2; dx3];
end

