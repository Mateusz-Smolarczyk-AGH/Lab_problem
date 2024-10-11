function dxdt = model_wiatrak(t, x, u, params)
    K = params(1); tau = params(2);
%     p = params(3:7); mu = params(8);
    p = [2.056467854285133e+02,-5.208575031241387,-1.043284835310092e+03,43.401332957404660,3.454345824430912e+03,1.802723922744937];
    mu = [0;0.636602825861413];
    f_u = polyval(p, u, [], mu);
    dxdt = (K * f_u - x) / tau;
end
