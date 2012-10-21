from numpy import *
from scipy.special import *

def legendre_roots(n):
	return roots(legendre(n))
	
if __name__ == "__main__":
	print legendre_roots(8)
