#!/usr/bin/env python

import numpy as np
import scipy as sp
from scipy.linalg import *
from numpy.linalg import *

def squareMatrix(A):
	n_rows, n_cols = A.shape
	
	if n_rows == n_cols:
		return True
	else:
		return False

def checkSimetry(A):
	# get the dimensions of the matrix A
	n_rows, n_cols = A.shape
	
	# verify that the given matrix is a square matrix (nxn)
	if squareMatrix(A) == False:
		return ""
	
	# verify that the given matrix equals the transposed matrix
	A_t = sp.transpose(A)
	for row_index in range(n_rows):
		for col_index in range(n_cols):
			if not A[row_index][col_index] == A_t[row_index][col_index]:
				# if the elements of the matrix and the transposed don't match, instanly the matrix A is not symetrical
				return ""
	
	# tell everyone that we have found a symetrical matrix
	return "simetrica"
	
def checkHermitian(A):
	# get the dimentions of the matrix A
	n_rows, n_cols = A.shape
	
	# verify that the given matrix is a square matrix (nxn)
	if squareMatrix(A) == False:
		return ""
	
	# verify that the conjugate of the transposed equals the matrix
	A_t = sp.transpose(A)
	for row_index in range(n_rows):
		for col_index in range(n_cols):
			# we need to cast the elements of the matrix to compare the conjugate of them
			A_ij = complex(A[row_index][col_index])
			A_t_ij = complex(A_t[row_index][col_index])
			if A_ij != A_t_ij.conjugate():
				# if the elements of the matrix and the conjugated transposed don't match, instanly the matrix A is not hermitian
				return ""
				
	# tell everyone that we have found a hermitian matrix
	return "hermitiana"
	
def checkOrthogonal(A):
	# get the dimentions of the matrix A
	n_rows, n_cols = A.shape
	
	# verify that the given matrix is a square matrix (nxn)
	if squareMatrix(A) == False:
		return ""
		
	# get the transpose and get the product between the matrix A and the transposed
	A_t = sp.transpose(A)
	product1 = np.dot(A,A_t)
	product2 = np.dot(A_t,A)
	
	# the singular value decomposition (svd) allows us to easily know if the product of A and the transposed is the identity matrix
	U1, s1, V1 = np.linalg.svd(product1)
	U2, s2, V2 = np.linalg.svd(product2)
	
	for row_index in range(n_rows):
		for col_index in range(n_cols):
			if U1[row_index][col_index] == U2[row_index][col_index]:
				if row_index == col_index:
					if U1[row_index][col_index] == 1 and U2[row_index][col_index] == 1:
						# nothing relevant here
						pass
					else:
						# if the diagonal of the matrixs are not equal to 1, then they are not identity matrix, ergo, the matrix A is not orthogonal
						return ""
			else:
				# if the rest of the matrixs are not equal, then instantly the matrix A is not orthogonal
				return ""
	
	# tell everyone that we have found an orthogonal matrix
	return "ortogonal"
					
	
	
if __name__ == "__main__":
	simetrica = np.array([[1,2,-3],[2,0,5],[-3,5,1]])
	hermitica = np.array([[3,'2+j'],['2-j',1]])
	ortogonal = np.array([[6,-2],[2,6]])
	unitaria = np.array([[4,-2],[-3,1]])
	
	A = ortogonal
	print checkOrthogonal(unitaria)
	#print checkSimetry(A), checkHermitian(A)
