import numpy as np
import pylab as pl
from math import *
from random import *

def generateRandomMatrix(n):
	vectors = np.zeros((n,2))
	for i in range(n):
		vectors[i,0] = uniform(-10,10)
		vectors[i,1] = uniform(-10,10)
	return vectors

def getNorm(vector):
	return sqrt(vector[0]**2 + vector[1]**2)

def graph(n,norm):
	vectors = generateRandomMatrix(n)
	print vectors
	
	for i in range(n):
		vectors[i,:] = (vectors[i,:]/getNorm(vectors[i,:]))*norm
		
	pl.plot(vectors[:,0],vectors[:,1],'yo')
	pl.show()
	

if __name__ == "__main__":
	graph(1000,2)
