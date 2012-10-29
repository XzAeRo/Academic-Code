from numpy import *
from scipy.integrate import *

def erf_real(y):
	"""	This function evaluates the Gaussian Error Function for a given 'y' upper
		integration limit.
		
		y: float value for the integration upper limit.
			
		returns: float value of 'x_int' evaluated in the interpolation 'pol'.
		"""
	func = lambda x: e**(-x**2) # function to integrate
	return (2/(pi**(0.5)))*quad(func,0,y)[0] # integrate
	
if __name__ == "__main__":
	print erf_real(4)
