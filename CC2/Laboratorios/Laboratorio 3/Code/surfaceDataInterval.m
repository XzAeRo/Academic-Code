% Completar de acuerdo al enunciado.
function [] = surfaceDataInterval(L,h,k,a,MAX_ITER)
	result = eqHeatFD(L, h, k, a, MAX_ITER);
	plot(result')
end
