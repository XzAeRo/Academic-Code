#!/usr/bin/env python

from pylab import *
from scipy.linalg import *
import numpy as np

def transr(A,degrees):
	n_rows, n_cols = A.shape
	rotation = np.array([[np.cos(degrees), np.sin(degrees)], [-np.sin(degrees), np.cos(degrees)]])
	print rotation
	

if __name__ == "__main__":
	A = imread("Anexos_lab1/pablo-palito.png")[:,:,0]
	gray()
	
	transr(A,0)
	
	#imshow(A)
	#show()
