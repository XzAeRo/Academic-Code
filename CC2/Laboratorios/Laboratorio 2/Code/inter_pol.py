from numpy import *
from numpy.linalg import *
import timeit, table_print, sys

def partition(ran,n):
	"""	This function partitions a range in n parts and returns an array with
		n partitions plus the borders (n + 1 in total)."""
	return linspace(ran[0], ran[1], num=n+1, endpoint=True)

def evaluate(x):
	"""	This function evaluates each element of the array 'x', and returns
		and array of results according to the proposed function."""
	y = []
	for x_i in x:
		y.append((10*log(x_i**2 + x_i + 1))/(10*x_i**3 - 20*x_i**2 + x_i - 2) )
	return array(y)
	
def create_spl_mat(n):
	"""	This function creates a matrix of nxn used for solving the 'c_j' 
		ecuations for the Splines interpolation.
		This is the left side matrix of this example: http://goo.gl/jxv9U """
	A = zeros((n,n))
	A[0,0], A[n-1,n-1] = 1, 1
	for i in range(1,n-1):
		A[i,i-1], A[i,i], A[i,i+1] = 1, 4, 1
	return A
	
def create_spl_Y(y):
	"""	This function creates the array of 1xn used for solving the 'c_j'
		ecuations for the Splines interpolation.
		This is the right side array of this example: http://goo.gl/jxv9U """
	n = len(y)
	Y = zeros(n)
	for i in range(1,n-1):
		Y[i] = y[i-1] - 2*y[i] + y[i+1]
	return Y

def divided_differences(x,y,x_int):
	"""	This functions computes the divided differences interpolation method
		(a.k.a Newton interpolation).
		
		x: array-like variable that contains equidistant values for the x-axis.
		y: array-like variable that contains evaluated values of 'x'.
		x_int: float variable used to evaluate the interpolation.
		
		returns: float value of 'x_int' evaluated in the Newton interpolation.
		"""
	result = copy(y)
	for i in range(1, len(x)):
		prev = copy(result)
		for j in range(i, len(x)):
			# compute the divided differences tree
			# this algorithm will ONLY leave the polynomial coeficients
			result[j] = (prev[j] - prev[j - 1]) / (x[j] - x[j - i])
	y_int = result[0]
	prod = 1.0
	for i in range(1,len(x)):
		# solve the polinomial interpolation for x_int
		prod *= (x_int - x[i-1])
		y_int += (result[i]*prod)
	return y_int

def splines(x,y,x_int):
	"""	This functions computes the Splines interpolation method.
	
		x: array-like variable that contains equidistant values for the x-axis.
		y: array-like variable that contains evaluated values of 'x'.
		x_int: float variable used to evaluate the interpolation.
		
		returns: float value of 'x_int' evaluated in the Splines interpolation.
		"""
	Y = create_spl_Y(y)
	coef_mat = create_spl_mat(len(x)) # get the Splines matrix for the c_j coef.
	C = solve(coef_mat,Y)	# gets the c_j coeficients
	"""	The following code snipet was taken from the StackOverflow forums.
		Returns the index of the value closes to x_int.
		Link: http://goo.gl/Is7W0
	"""
	j = min(range(len(x)), key=lambda i: abs(x[i]-x_int))
	
	# define the coeficients for the Splines interpolation
	x_j = x[j]  
	h = float((x[len(x)-1] - x[0])/len(x))
	a_j = y[j]
	c_j = C[j]
	b_j = (1/h)*(y[j+1]+y[j]) - (h/3)*(C[j+1]+c_j)
	d_j = (C[j+1] - c_j)/(3*h)
	diff = x_int - x_j
	
	# solve the ecuation as we return the value
	return a_j + b_j*diff + c_j*(diff**2) + d_j*(diff**3)

def inter_pol(x_int, n, pol):
	"""	This function runs two interpolation methods and return an evaluated 
		result for a given input.
		
		x_int: float variable used to evaluate the interpolation.
		n: number of partitions in the domain of the interpolated function.
		pol: interpolation method. 'diff' for the Newton interpolation and 'spl'
			for the Splines interpolation.
			
		returns: float value of 'x_int' evaluated in the interpolation 'pol'.
		"""
	ran = [-1,1]
	if x_int < ran[0] or x_int > ran[1]:
		print "Error: invalid input. 'x_int' value must be in the valid domain"\
			"defined by 'ran'.\n"
		raise ValueError("Invalid 'x_int' value")
	
	x = partition(ran,n) # partition the domain in n parts
	y = evaluate(x) # evaluate each point of the partition
	
	# execute the chosen interpolation
	if pol == "diff":
		return divided_differences(x,y,x_int)
	elif pol == "spl":
		return splines(x,y,x_int)
	else:
		print "Error: Unknown interpolation method.\nAvailable methods are:\n"\
		"\t'diff':\tNewton Interpolation\n" \
		"\t'spl':\tSplines\n"
		raise ValueError("Unknown interpolation method")
    
if __name__ == "__main__":
	X = array([-0.5,-0.25,0.0,0.25,0.5])
	y = evaluate(X)
	data = []
	data.append(["n", "x", "y_k", "y_int", "pol", "Error Relativo", "Tiempo de Computo"])
	for m in range(1,6):
		n = 2**m
		for pol in ["diff", "spl"]:
			for x in X:
				y_int = inter_pol(x, n, pol)
				comp_time = timeit.timeit("inter_pol(x,n,pol)",setup='x='+str(x)+'; n='+str(n)+'; pol="'+pol+'"; from __main__ import inter_pol',number=10)
				y_real = evaluate([x])[0]
				if y_real != 0:
					rel_err = abs((y_real - y_int) / y_real)
				else:
					rel_err = abs(y_real - y_int)
				data.append([str(n),x,y_real,y_int,pol,rel_err,comp_time])
	
	table_print.pprint_table(sys.stdout, data)
	
