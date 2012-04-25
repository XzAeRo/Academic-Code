import numpy, scipy, pylab
import csv
from time import time

def LoadMatrix(path):
	""" Returns: 2D Array

	Funcion que lee archivos .csv y los retorna como una matriz 2D.

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
	
def MatrixMul(met,A,B):
	start = 0.0
	finish = 0.0
	if met == "prod_punto":
		print "Ejecutando producto punto..."
		start = time()
		result = numpy.dot(A,B)
		finish = time()
		print "Producto punto demoro " + str(finish - start) + " segundos."
		print result
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
	
	print test1
	
	MatrixMul("prod_punto", test1, test2)
