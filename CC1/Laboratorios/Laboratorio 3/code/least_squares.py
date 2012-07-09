from numpy import *
from pylab import *
from scipy.stats import norm

def function(start=-5.0,end=5.0,step=0.01):
	x = start
	X = []
	while x <= end:
		X.append(x)
		x += step
	X = array(X)
	Y = [0.0]*len(X)
	Y = 2*sin(2*X) + 1.2*sin(5*X)
	Y = array(Y)
	e = norm.rvs(size=len(Y))
	Y += e
	return X, Y

def function2(start=-5.0,end=5.0,step=0.01):
	x = start
	X = []
	while x <= end:
		X.append(x)
		x += step
	X = array(X)
	Y = [0.0]*len(X)
	Y = 3.0*X**4 + X**3 + 5*X**2 
	e = norm.rvs(size=len(Y))
	Y += e
	
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
	
def pregunta3(x,max_degree):
	degree_counter = max_degree
	degrees = range(max_degree)
	condition_number = [0]*max_degree
	
	for degree in degrees:
		vandermonde = zeros((len(x),degree_counter+1))
		for i in range(len(x)):
			for j in range(degree_counter+1):
				vandermonde[i,j] = x[i]**(j-1)
		
		condition_number[degree_counter-1] = linalg.cond(vandermonde)
		degree_counter -= 1
		
	plot(degrees,condition_number)
	show()
	
def pregunta4():
	x,y = function2()
	degree1 = 2
	degree2 = 4
	p1 = poly1d(polyfit(x, y, degree1))
	p2 = poly1d(polyfit(x, y, degree2))
	xp = linspace(-5,5,100)
	plot(x,y,".",xp,p1(xp),"-",xp,p2(xp),"--")
	show()
	
	
if __name__ == "__main__":
	x,y = function()
	#pregunta1(x,y)
	#pregunta2(x,y)
	#pregunta3(x,20)
	pregunta4()
