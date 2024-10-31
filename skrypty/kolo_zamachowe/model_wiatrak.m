function dxdt = model_wiatrak(t, x, u, params)
    K = params(1);
    tau = params(2);
    I_kola = 0.000232559;

    % Wyraz (211.6 * u + 0.953) jest wynikiem regresji liniowej charakterystyki statycznej z excela
    dxdt = ((K * (211.6*u + 0.953) - x) / tau);

end
