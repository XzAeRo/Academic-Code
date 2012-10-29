from numpy import *
from scipy.integrate import *

def erf_real(y):
	func = lambda x: e**(-x**2)
	return (2/(pi**(0.5)))*quad(func,0,y)[0]
	
if __name__ == "__main__":
	print erf_real(4)
