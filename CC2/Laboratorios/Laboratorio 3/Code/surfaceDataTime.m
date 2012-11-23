% Completar de acuerdo al enunciado.
function [] = surfaceDataTime(L,h,k,a,MAX_ITER)
	mesh(eqHeatFD(L,h,k,a,MAX_ITER))
end 
