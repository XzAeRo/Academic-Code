#!/usr/bin/env python

import numpy

def transposeMatrix(A):
	n_rows = len(A)
	A_t = [None]*n_rows
	for index in range(n_rows):
		A_t[index] = [None]*n_rows

	for row_index in range(n_rows):
		for col_index in range(n_rows):            
			A_t[row_index][col_index] = A[row_index][col_index]	
	
	return A_t

def checkSimetry(A):
	print "do nothing"

if __name__ == "__main__":
	simetrica = [[1,2,-3],[2,0,5],[-3,5,1]]
	hermitica = [[1,2],[2,1]]
	ortogonal = [[6,-2],[2,6]]
	unitaria = [[4,-2],[-3,1]]
	
	print simetrica
	print transposeMatrix(simetrica)
