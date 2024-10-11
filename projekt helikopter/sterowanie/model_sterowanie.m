function u = model_sterowanie(w, params)
    p = params.p;
    mu = params.mu;
    u = polyval(p, w, [], mu);
    % Ograniczenie na wartość siły
%     u = min(max(u,-0.65),0.8);
end

