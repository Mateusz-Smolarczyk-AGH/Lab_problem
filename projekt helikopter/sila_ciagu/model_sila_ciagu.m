function F = model_sila_ciagu(w, params)
    p = params.p;
    mu = params.mu;
    F = polyval(p,w,[],mu);
    % Ograniczenie na wartość siły
    F = min(max(F,-0.65),0.8);
end

