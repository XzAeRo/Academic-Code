from numpy import *
from matrices import documents, incidenceTerms, q1, q2

def reduceMatrix(matrix, p):
	U, s, V = linalg.svd(matrix)
	U_r = U[:,[0,p-1]]
	s_r = s[[0,U_r.shape[1]],:]
	V_r = V[:,[0,p-1]]
	matrix_r = dot(U_r, dot(s_r,V_r))
	
	return matrix_rs, U_r, s_r, V_r
	
def translateQuery(query, U, s):
	return dot(transpose(query),dot(U,s))

def LSI(documents, incidenceTerms, q, reduced=False, p=None):
	docs = copy(documents)
	terms = copy(incidenceTerms)
	n_docs = len(docs)
	n_terms = len(terms)
	
	# lower case all the documents for faster semantic searchings
	for i in range(n_docs):
		docs[i] = docs[i].lower()
	
	# initialize the incidence matrix
	A = zeros((n_docs,n_terms))
	# fill the incidence matrix with the required values
	for i in range(n_docs):
		for j in range(n_terms):
			if terms[j] in docs[i]:
				A[i,j] = 1.0
				
	if reduced:
		A, U, s, V = reduceMatrix(A,p)
	
	# initialize the query array
	query = zeros((n_terms))
	for query_term in q:
		for i in range(n_terms):
			if query_term == terms[i]:
				query[i] = 1.0
	
	if reduced:
		query = translateVector(query, U, s)
	
	# prepare the results
	results = zeros((n_docs))
	q_norm = linalg.norm(query)
	
	for i in range(n_docs):
		doc = A[i,:]
		num = dot(query,doc)
		den = q_norm * linalg.norm(doc)
		results[i] = num / den # calculates the cos between two vectors
		
	print results
		
	
if __name__ == "__main__":
	q = q1
	LSI(documents, incidenceTerms, q, True, 2)
