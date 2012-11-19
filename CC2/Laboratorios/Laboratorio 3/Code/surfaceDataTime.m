% Completar de acuerdo al enunciado.
function [] = surfaceDataTime(MAX_ITER)
	mesh(eqHeatFD(1,0.01,0.00000001,1,MAX_ITER))
end
