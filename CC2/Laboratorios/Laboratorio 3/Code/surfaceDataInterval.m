% Completar de acuerdo al enunciado.
function [] = surfaceDataInterval(L, MAX_ITER)
	result = eqHeatFD(L, 0.01, 0.00000001, 1, MAX_ITER);
	plot(result')
end
