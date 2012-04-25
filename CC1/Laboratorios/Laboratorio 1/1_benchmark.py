import numpy, scipy, pylab
import csv

def LoadMatrix(path):
""" Returns: 2D Array

Funcion que lee archivos .csv y los retorna como una matriz 2D.

"""
	# Leemos el archivo csv y preparamos la matriz de retorno
	handle = csv.reader(open(path,"rb"),delimiter=",")
	matrix = []
	
	for line in handle:
		# Una linea de csv lo transformamos en una fila de la matriz
		row = list(line)
		matrix.append(row)
	
	return matrix
	
def MatrixMul(met,A,B):
	print "Hello World"
	
if __name__ == "__main__":
	random = LoadMatrix("Anexos_lab1/random_matrix.csv")
	vandermonde = LoadMatrix("Anexos_lab1/vandermonde.csv")
	sparse = LoadMatrix("Anexos_lab1/sparse.csv")
