from numpy import *
from numpy.linalg import *

def partition(ran,n):
	"""This function partitions a range in n parts and returns an array with
	n partitions plus the borders (n + 1 in total)"""
	return linspace(ran[0], ran[1], num=n+1, endpoint=True)

def evaluate(x):
	y = []
	for x_i in x:
		y.append((10*log(x_i**2 + x_i + 1))/(10*x_i**3 - 20*x_i**2 + x_i - 2) )
	return array(y)
	
def create_spl_mat(n):
	A = zeros((n,n))
	A[0,0], A[n-1,n-1] = 1, 1
	for i in range(1,n-1):
		A[i,i-1], A[i,i], A[i,i+1] = 1, 4, 1
	return A
	
def create_spl_Y(y):
	n = len(y)
	Y = zeros(n)
	for i in range(1,n-1):
		Y[i] = y[i-1] - 2*y[i] + y[i+1]
	return Y

def divided_differences(x,y,x_int):
	result = copy(y)
	for i in range(1, len(x)):
		prev = copy(result)
		for j in range(i, len(x)):
			result[j] = (prev[j] - prev[j - 1]) / (x[j] - x[j - i])
	val = result[0]
	prod = 1.0
	for i in range(1,len(x)):
		prod *= (x_int - x[i-1])
		val += (result[i]*prod)
	return val

def splines(x,y,x_int,coef_mat):
	Y = create_spl_Y(y)
	C = solve(coef_mat,Y)
	""" The following code snipet was taken from the StackOverflow forums.
		Returns the index of the value closes to x_int.
		Link: http://goo.gl/Is7W0
	"""
	j = min(range(len(x)), key=lambda i: abs(x[i]-x_int))
	x_j = x[j]
	print x_j
	print x
	print x_int
	h = float((x[len(x)-1] - x[0])/len(x))
	a_j = y[j]
	c_j = C[j]
	b_j = (1/h)*(y[j+1]+y[j]) - (h/3)*(C[j+1]+c_j)
	d_j = (C[j+1] - c_j)/(3*h)
	diff = x_int - x_j
	return a_j + b_j*diff + c_j*(diff**2) + d_j*(diff**3)

def inter_pol(x_int, n, pol):
	ran = [-1,1]
	if x_int < ran[0] or x_int > ran[1]:
		print "Error: invalid input. 'x_int' value must be in the valid domain defined by 'ran'.\n"
		raise ValueError("Invalid 'x_int' value")
	
	x = partition(ran,n)
	y = evaluate(x)
	coef_mat = create_spl_mat(len(x))
	
	if pol == "diff":
		return divided_differences(x,y,x_int)
	elif pol == "spl":
		return splines(x,y,x_int,coef_mat)
	else:
		print "Error: Unknown interpolation method.\nAvailable methods are:\n" \
		"\t'diff':\tNewton Interpolation\n" \
		"\t'spl':\tSplines\n"
		raise ValueError("Unknown interpolation method")
    
if __name__ == "__main__":
	print inter_pol(0.5,10,"spl")
	print inter_pol(0.5,10,"diff")
