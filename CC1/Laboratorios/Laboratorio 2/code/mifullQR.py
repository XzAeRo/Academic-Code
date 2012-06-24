from numpy import *
from matrices import A,B,C,D,E

def mifullQR(A):
	# Gramm-Schmidt Orthogonalization
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
	left_null = linalg.solve(transpose(A),zeros((A.shape[0],1)))
	print left_null
	
	## R MATRIX CALCULATION ##
	#R_min = dot(transpose(Q),A)
	# add the following zeros
	#R = zeros((Q.shape[0],min(A.shape))
	#for i in range(Q.shape[1]):
	#	R[i,:] = R_min[i,:]
	
	return Q,R
	
if __name__ == "__main__":
	X = E
	Q,R = mifullQR(X)
		
	print "X:\n", X
	print "Q:\n", Q
	print "R:\n", R
	print "QR:\n", dot(Q,R)

