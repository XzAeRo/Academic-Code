#!/usr/bin/env python

import numpy
import csv
from time import time

def LoadMatrix(path):
	""" Returns: 2D Array
	Description: Reads a CSV file and returns a 2D array with the contents of the csv with float type elements.
	"""
	# Leemos el archivo csv y preparamos la matriz de retorno
	handle = csv.reader(open(path,"rb"),delimiter=",")
	raw_matrix = []
	
	for line in handle:
		# Una linea de csv lo transformamos en una fila de la matriz
		row = list(line)
		row = [float(element) for element in row]
		raw_matrix.append(row)
	
	return raw_matrix
	
def matrix_lenght(A):
	""" Returns: Integers Tuple
	Description: Calculates the lenght of the column and the row of a matrix.
	"""
	col_len = len(A)
	row_len = len(A[0])
	return row_len, col_len
	
def prod_punto(A,C):
	""" Returns: 2D Array
	
	
	"""
	B = []
	bij = 0.0
	aik = 0.0
	ckj = 0.0
	
def MatrixMul(met,A,B):
	start = 0.0
	finish = 0.0
	if met == "prod_punto":
		print "Ejecutando producto punto..."
		start = time()
		result = numpy.dot(A,B)
		finish = time()
		print "Producto punto demoro " + str(finish - start) + " segundos."
	elif met == "enf_col":
		print "Enfoque de Columna"
	elif met == "enf_row":
		print "Enfoque de Fila"
	elif met == "enf_col_row":
		print "Enfoque de Columna y Fila"
	else:
		print """[ERROR] Metodo desconocido.
Opciones: 'prod_punto', 'enf_col', 'enf_row', 'enf_col_row'.""" 
	
if __name__ == "__main__":
	random = LoadMatrix("Anexos_lab1/random_matrix.csv")
	vandermonde = LoadMatrix("Anexos_lab1/vandermonde.csv")
	sparse = LoadMatrix("Anexos_lab1/sparse.csv")
	test1 = LoadMatrix("Anexos_lab1/test1.csv")
	test2 = LoadMatrix("Anexos_lab1/test2.csv")
	
	MatrixMul("prod_punto", test1, test2)
