from numpy import *
from matrices import *

def miredQR(A):
	## GRAMM-SCHMIDT ORTHOGONALIZATION ##
	Q = copy(A) # safe copy of A
	n, k = Q.shape # number of rows and columns

	for j in range(k):
		for i in range(j):
			# dot product between Vi and Vj
			D = dot(Q[:,i],Q[:,j]) 
			# regressive substracting of Vi and Vj
			# now whe have Qi, but not normalized yet
			Q[:,j] -= D*Q[:,i]
		# normalization of the Qi vector
		norm = linalg.norm(Q[:,j])
		Q[:,j] *= 1.0/norm
	
	# we already have our Q matrix
	
	## R MATRIX CALCULATION ##
	R = dot(transpose(Q),A)
	
	return Q, R
	
if __name__ == "__main__":

	X = A
	Q,R = miredQR(X)
		
	print "X:\n", X
	print "Q:\n", Q
	print "R:\n", R
	print "QR:\n", dot(Q,R)
