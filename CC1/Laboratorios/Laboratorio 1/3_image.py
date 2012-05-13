#!/usr/bin/env python

from pylab import *
from scipy.linalg import *
import numpy as np
import math

def transr(A,degrees):
	n_rows, n_cols = A.shape
	rotation_matrix = np.array([[np.cos(degrees), np.sin(degrees)], [-np.sin(degrees), np.cos(degrees)]])
	x = []*(n_rows*n_cols)
	y = []*(n_rows*n_cols)
	
	for i in range(n_rows):
		for j in range(n_cols):
			location = np.dot(rotation_matrix,np.array([i,j])).astype(int)
			x.append(location[0])
			y.append(location[1])
	
	new_shape = max(x)-min(x)+1,max(y)-min(y)+1
	dif_x, dif_y = 0-min(x), 0-min(y)
	x.reverse()
	y.reverse()
	
	A_r = np.zeros(new_shape)
	print new_shape
	print x, y
	for i in range(len(x)):
		x[i] = x[i] + dif_x
	for i in range(len(y)):
		y[i] = y[i] + dif_y
	
	print x,y	
		
	for i in range(n_rows):
		for j in range(n_cols):
			a,b =x.pop(),y.pop()
			A_r[x.pop(),y.pop()] = A[i,j]
			
	return A_r

if __name__ == "__main__":
	A = imread("Anexos_lab1/test_image.png")[:,:,0]
	gray()
	
	A_r = transr(A,math.pi/2)
	
	imshow(A_r)
	show()
