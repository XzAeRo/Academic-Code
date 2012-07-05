from numpy import *
from pylab import *
import random as rand

def function(start=-5.0,end=5.0,step=0.01):
	x = start
	X = []
	Y = []
	while x <= end:
		result = 2*sin(2*x) + 1.2*sin(5*x) + rand.uniform(0,1)
		X.append(x)
		Y.append(result)
		x += step
	X = array(X)
	Y = array(Y)
	return X, Y

def pregunta1(x,y):
	plot(x,y,'ro')
	show()
	
def pregunta2(x,y):
	degree1 = 7
	degree2 = 20
	p1 = poly1d(polyfit(x, y, degree1))
	p2 = poly1d(polyfit(x, y, degree2))
	xp = linspace(-5,5,100)
	plot(x,y,".",xp,p1(xp),"-",xp,p2(xp),"--")
	ylim(-5,5)
	show()

if __name__ == "__main__":
	x,y = function()
	#pregunta1(x,y)
	pregunta2(x,y)
