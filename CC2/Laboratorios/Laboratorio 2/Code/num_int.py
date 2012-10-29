from erf_teo import *
from erf_real import *
from matplotlib import pyplot

"""
This script runs some tests and gives as output some graphics and Latex friendly code.
"""

def legendre_roots(n):
	"""	Computes the ntn Legendre roots
	"""
	return roots(legendre(n))

def pregunta2():
	for n in range (4,8):
		roots = legendre_roots(n)
		out = "$n$ & $" + str(n) + "$ \\\\ \\hline \n" 
		for i in range(len(roots)):
			out += "$x_" + str(i+1) + "$ & $" + str(roots[i]) + "$ \\\\ \\hline \n" 
		print out
def pregunta3():
	y = 10
	for n in range (4,8):
		roots, C = roots_weights(n)[0], roots_weights(n)[1]
		erf = erf_teo(y,n)
		out = "$n$ & $" + str(n) + "$ \\\\ \\hline \n" 
		for i in range(len(C)):
			out += "$c_" + str(i+1) + "$ & $" + str(C[i]) + "$ \\\\ \\hline \n" 
		print out + "$y$ & $" + str(erf) + "$ \\\\ \\hline \n"
	
def pregunta4():
	y = 10
	n = range(4, 8)
	erf = []
	for i in n:
		erf.append(erf_teo(y,i))
 
	pyplot.plot( n, erf, '-' )
	pyplot.title( 'Cambio de erf_teo respecto a n para y = 10' )
	pyplot.xlabel( 'n' )
	pyplot.ylabel( 'erf_teo' )
	pyplot.show()
	
def pregunta6():
	y = 10
	for n in range (4,8):
		teo_val = erf_teo(y,n)
		real_val = erf_real(y)
		err = abs(teo_val - real_val)/real_val
		print "$"+str(n)+"$ & $"+str(teo_val)+"$ & $"+str(real_val)+"$ & $"+str(err)+"$ \\\\ \\hline\n"
		
	
if __name__ == "__main__":
	pregunta6()
	
