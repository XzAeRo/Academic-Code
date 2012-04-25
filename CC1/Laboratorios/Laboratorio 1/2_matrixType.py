#!/usr/bin/env python

import numpy


def squareMatrix(A):
	n_rows = len(A)
	n_cols = len(A[0])
	
	if n_rows == n_cols:
		return True
	else:
		return False

def transposeMatrix(A):
	n_rows = len(A)
	A_t = [None]*n_rows
	for index in range(n_rows):
		A_t[index] = [None]*n_rows

	for row_index in range(n_rows):
		for col_index in range(n_rows):            
			A_t[row_index][col_index] = A[col_index][row_index]	
	
	return A_t

def checkSimetry(A):
	n_rows = len(A)
	n_cols = len(A[0])
	
	# verify that the given matrix is a square matrix (nxn)
	if squareMatrix(A) == False:
		return ""
	
	# verify that the given matrix equals the transposed matrix
	A_t = transposeMatrix(A)
	for row_index in range(0,n_rows):
		for col_index in range(0,n_cols):
			if not A[row_index][col_index] == A_t[row_index][col_index]:
				return ""
	
	# now that that we have an square matrix and the transposed matrix equals the original, anounce that tha matrix is symetrical.
	return "simetrica"
	
def checkHermitian(A):
	n_rows = len(A)
	n_cols = len(A[0])
	
	# verify that the given matrix is a square matrix (nxn)
	if squareMatrix(A) == False:
		return ""
	
	# verify that the conjugate of the transposed matrix equals the matrix
	A_t = transposeMatrix(A)
	for row_index in range(0,n_rows):
		for col_index in range(0,n_cols):
			A_ij = complex(A[row_index][col_index])
			A_t_ij = complex(A_t[row_index][col_index])
			if A_ij != A_t_ij.conjugate():
				return ""
				
	return "hermitiana"
	
def checkOrthogonal(A):
	# do nothing
	pass
	
if __name__ == "__main__":
	simetrica = [[1,2,-3],[2,0,5],[-3,5,1]]
	hermitica = [[3,'2+j'],['2-j',1]]
	ortogonal = [[6,-2],[2,6]]
	unitaria = [[4,-2],[-3,1]]
	
	A = [[1,2],[3,4]]
	checkOrthogonal(A)
	A = numpy.matrix(A)
	print A[0]
	#print checkSimetry(A), checkHermitian(A)