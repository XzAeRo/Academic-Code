#!/usr/bin/env python

import numpy as np
import scipy as sp


def squareMatrix(A):
	n_rows, n_cols = A.shape
	
	if n_rows == n_cols:
		return True
	else:
		return False

def transposeMatrix(A):
	# Obsolete
	A_t = []
	for row_index in range(len(A)):
		A_t.append([row[row_index] for row in A])
	
	return A_t

def checkSimetry(A):
	n_rows = len(A)
	n_cols = len(A[0])
	
	# verify that the given matrix is a square matrix (nxn)
	if squareMatrix(A) == False:
		return ""
	
	# verify that the given matrix equals the transposed matrix
	A_t = sp.transpose(A)
	for row_index in range(n_rows):
		for col_index in range(n_cols):
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
	A_t = sp.transpose(A)
	for row_index in range(n_rows):
		for col_index in range(n_cols):
			A_ij = complex(A[row_index][col_index])
			A_t_ij = complex(A_t[row_index][col_index])
			if A_ij != A_t_ij.conjugate():
				return ""
				
	return "hermitiana"
	
def checkOrthogonal(A):
	# do nothing
	pass
	
if __name__ == "__main__":
	simetrica = np.array([[1,2,-3],[2,0,5],[-3,5,1]])
	hermitica = np.array([[3,'2+j'],['2-j',1]])
	ortogonal = np.array([[6,-2],[2,6]])
	unitaria = np.array([[4,-2],[-3,1]])
	
	A = simetrica
	print checkSimetry(A), checkHermitian(A)
