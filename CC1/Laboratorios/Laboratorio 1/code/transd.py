#!/usr/bin/env python

from pylab import *
from scipy.linalg import *
import numpy as np
import math

	
def transd(A,Sx,Sy):
	# dimentions of the original image
	n_rows, n_cols = A.shape
	# dimentions of the expanded image
	nd_rows, nd_cols = n_rows*Sx, n_cols*Sy
	
	# fill a matrix with zeros with the new image shape
	A_d = np.zeros((nd_rows,nd_cols))
	
	for i in range(n_rows):
		for j in range(n_cols):
			# we expand the vectors to a new location
			x = i*Sx
			y = j*Sy
			# store the value to the new image
			A_d[x,y] = A[i,j]
	imshow(A_d)
	show()

if __name__ == "__main__":
	A = imread("pablo-palito.png")[:,:,0]
	gray()
	
	transd(A,1.5,3)
