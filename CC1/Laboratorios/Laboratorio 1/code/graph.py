import numpy as np
import pylab as pl
from math import *
from random import *

def generateRandomMatrix(n):
	vectors = np.zeros((n,2)) # setup n (x,y) vectors
	for i in range(n):
		# fill the (x,y) vectors with random numbers between -10 and 10
		vectors[i,0] = uniform(-10,10)
		vectors[i,1] = uniform(-10,10)
	return vectors

def getNorm(vector):
	# return the p-norm with p=2 for 2-D vectors
	return sqrt(vector[0]**2 + vector[1]**2)

def graph(n,norm):
	vectors = generateRandomMatrix(n) # get random vectors
	
	for i in range(n):
		# for each vector we compute the required operation (induced norm)
		vectors[i,:] = (vectors[i,:]/getNorm(vectors[i,:]))*norm
	
	# setup a graph with the values of the vectors (each value is represented by a red 'o')
	pl.plot(vectors[:,0],vectors[:,1],'ro')
	pl.show()
	

if __name__ == "__main__":
	graph(1000,2)
