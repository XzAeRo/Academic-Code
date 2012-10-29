from scipy import *
from numpy import *
from scipy.special import *
from scipy.integrate import *

def legendre_roots(n):
	return roots(legendre(n))
	
def weights(X):
	

def roots_weights(n):
	return orthogonal.p_roots(n)
	
def erf_teo(y,n):
	fix = y/2
	result = 0
	roots, C = roots_weights(n)[0], roots_weights(n)[1]
	func = lambda x: e**(-x**2)
	
	for i in range(n):
		result += C[i] * func(fix*roots[i] + fix)
	result *= fix
	
	return result

if __name__ == "__main__":
	print erf_teo(4,4)
	
