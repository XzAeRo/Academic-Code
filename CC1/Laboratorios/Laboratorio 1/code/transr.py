#!/usr/bin/env python

from pylab import *
from scipy.linalg import *
import numpy as np
import math


def transr(A,degrees):
	# get the dimentions of the image
	n_rows, n_cols = A.shape
	# get the rotation matrix
	rotation_matrix = np.array([[np.cos(degrees), np.sin(degrees)], [-np.sin(degrees), np.cos(degrees)]])
	
	product = [] # list that holds the transformation matrix

	for i in range(n_rows):
		for j in range(n_cols):
			# get the dot product between the rotation matrix and the (x,y) vector
			p_val = np.dot(rotation_matrix, np.array([i,j]))
			# round float values
			x = round(p_val[0])
			y = round(p_val[1])
			# store the rotation vector
			product.append([x,y])
			
	product = np.array(product) # casted just for the awesome sintax that numpy uses for matrices
	min_x, max_x, min_y, max_y = min(product[:,0]), max(product[:,0]), min(product[:,1]), max(product[:,1])
	# create a new matrix with dimentions that can hold the rotated matrix
	A_r = np.zeros((max_x-min_x+1,max_y-min_y+1))
	
	index = 0 # lame counter
	for i in range(n_rows):
		for j in range(n_cols):
			# move the rotated values to a suitable place (from origin)
			x = product[index][0] + abs(min_x) # this will always let us start from the origin
			y = product[index][1] + abs(min_y)
			# copy the values from (x,y) to (x',y')
			A_r[x,y] = A[i,j]
			index += 1
			
	imshow(A_r)
	show()
	
if __name__ == "__main__":
	A = imread("pablo-palito.png")[:,:,0]
	gray()
	
	transr(A,math.pi/3)
