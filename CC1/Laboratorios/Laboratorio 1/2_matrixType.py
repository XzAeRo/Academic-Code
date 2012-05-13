#!/usr/bin/env python

import numpy as np
from numpy.linalg import *
import math

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
		return False
	
	# verify that the given matrix equals the transposed matrix
	for i in range(n_rows):
		for j in range(n_cols):
			if not A[i,j] == A[j,i]:
				# if the elements of the matrix and the transposed don't match, instanly the matrix A is not symetrical
				return False
	
	# tell everyone that we have found a symetrical matrix
	return True
	
def checkHermitian(A):
	# get the dimentions of the matrix A
	n_rows, n_cols = A.shape
	
	# verify that the given matrix is a square matrix (nxn)
	if squareMatrix(A) == False:
		return False
	
	# verify that the conjugate of the transposed equals the matrix
	for i in range(n_rows):
		for j in range(n_cols):
			# we need to cast the elements of the matrix to compare the conjugate of them
			A_ij = complex(A[i,j])
			A_t_ij = complex(A[j,i])
			if A_ij != A_t_ij.conjugate():
				# if the elements of the matrix and the conjugated transposed don't match, instanly the matrix A is not hermitian
				return False
				
	# tell everyone that we have found a hermitian matrix
	return True
	
def checkOrthogonal(A):
	# get the dimentions of the matrix A
	n_rows, n_cols = A.shape
	
	# verify that the given matrix is a square matrix (nxn)
	if squareMatrix(A) == False:
		return False
		
	# get the transpose and get the product between the matrix A and the transposed
	A_t = np.transpose(A)
	try:
		product = np.dot(A,A_t)
	except ValueError:
		return False
	
	for i in range(n_rows):
		for j in range(n_cols):
			p_value = round(product[i,j])
			if i==j and p_value != 1:
				return False
			if i!=j and p_value != 0:
				return False
				
	return True
	
def checkUnitary(A):
	# get the dimentions of the matrix A
	n_rows, n_cols = A.shape
	
	# verify that the given matrix is a square matrix (nxn)
	if squareMatrix(A) == False:
		return False
		
	# get the transpose and get the product between the matrix A and the transposed
	A_c = np.asarray(np.matrix(A).getH())
	
	product = np.dot(A,A_c)
	
	for i in range(n_rows):
		for j in range(n_cols):
			p_value = round(product[i,j])
			if i==j and p_value != complex(1):
				return False
			if i!=j and p_value != complex(0):
				return False
				
	return True
					
def prop(A):
	simetrica, hermitiana, ortogonal, unitaria = checkSimetry(A), checkHermitian(A), checkOrthogonal(A), checkUnitary(A)
	result = ""
	
	if simetrica:
		result += "simetrica"
	if hermitiana:
		if len(result) > 0:
			result += " hermitiana"
		else:
			result += "hermitiana"
	if ortogonal:
		if len(result) > 0:
			result += " ortogonal"
		else:
			result += "ortogonal"
	if unitaria:
		if len(result) > 0:
			result += " unitaria"
		else:
			result += "unitaria"
	
	return result
	
if __name__ == "__main__":
	simetrica = np.array([[1,2,-3],[2,0,5],[-3,5,1]])
	hermitiana = np.array([[3,2+1j],[2-1j,1]])
	ortogonal = np.array([[2.0/3,-2.0/3,1.0/3],[1.0/3,2.0/3,2.0/3],[2.0/3,1.0/3,-2.0/3]])
	unitaria = np.array([[2.0**-0.5,2**-0.5,0],[-1/math.sqrt(2)*1j,-1/math.sqrt(2)*1j,0],[0,0,1j]])
	identidad = np.array([[1,0],[0,1]])
	
	A = identidad

	print prop(A)
