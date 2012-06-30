from numpy import *
from pylab import *


def function(start=-10.0,end=10.0,step=0.01):
	x = start
	X = []
	Y = []
	while x <= end:
		result = 2*sin(2*x) + 1.2*sin(5*x)
		X.append(x)
		Y.append(result)
		x += step
	X = array(X)
	Y = array(Y)
	return X, Y

if __name__ == "__main__":
	x,y = function()
	plot(x,y,'ro')
	plot(x+random(),y+random(),'bo')
	show()
