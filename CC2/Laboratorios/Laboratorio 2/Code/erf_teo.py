from scipy import *
from numpy import *
from scipy.special import *
from scipy.integrate import *

def roots_weights(n):
	"""	This function computes roots of the nth order Legendre polynomial P_n
		and weights to use in Gaussian Quadrature.
		
		n: order of the nth Legendre polynomial P_n
			
		returns: [x,w] where x are the Legendre roots and w its weights
		"""
	return orthogonal.p_roots(n)
	
def erf_teo(y,n):
	"""	This function computes the Gaussian Quadrature over the Gaussian Error
		Function.
		
		y: float value that sets the upper limit of the integral function
		n: integer value that represents the nth order for the Legendre polynomial
			
		returns: float value of the estimated value for the Gaussian Error Function.
		"""
	
	fix = y/2 # adjusts the function to the [-1,1] interval
	result = 0
	roots, C = roots_weights(n)[0], roots_weights(n)[1]
	func = lambda x: e**(-x**2) # the function to integrate
	
	for i in range(n):
		result += C[i] * func(fix*roots[i] + fix) # gaussian quadrature
	result *= (2/sqrt(pi))*fix # finish the function evaluation
	
	return result

if __name__ == "__main__":
	print erf_teo(4,4)
	
