# -*- coding: utf-8 -*-

from numpy import *
import pylab as pl
from matrices import documents, incidenceTerms, q1, q2

def reduceMatrix(matrix, p):
	U, s, V = linalg.svd(matrix)
	s = diag(s)
	U_r = U[:,[0,p-1]]
	s_r = s[[0,U_r.shape[1]],:]
	V_r =  transpose(V[:,[0,p-1]])
	V_r = append(V_r,zeros((s_r.shape[1]-p,V.shape[0])),axis=0)
	
	matrix_r = dot(U_r, dot(s_r,V_r))

	return matrix_r, U_r, s_r, V_r
	
def translateQuery(query, U, s):
	q = copy(query)
	r_1 = dot(U,s)
	q_t = transpose(expand_dims(q,axis=1))
	r_1 = append(r_1,zeros((q_t.shape[1]-r_1.shape[0],r_1.shape[1])),axis=0)
	return transpose(dot(q_t,r_1))

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
	else:
		U, s, V = linalg.svd(A)
	
	# initialize the query array
	query = zeros((n_terms))
	for query_term in q:
		for i in range(n_terms):
			if query_term == terms[i]:
				query[i] = 1.0
	
	if reduced:
		query = translateQuery(query, U, s)
		query = append(query, zeros((A.shape[1]-query.shape[0],1)), axis=0)

	# prepare the results
	results = zeros((n_docs))
	q_norm = linalg.norm(query)
	
	for i in range(n_docs):
		doc = A[i,:]
		num = dot(doc,query)
		den = q_norm * linalg.norm(doc)
		if den <= 0:
			results[i] = 0.0
		else:
			results[i] = num / den
		
	return results, query, V
		
	
if __name__ == "__main__":
	r1, q1, v1 = LSI(documents, incidenceTerms, q1)
	r2, q2, v2 = LSI(documents, incidenceTerms, q2)
	r3, q3, v3 = LSI(documents, incidenceTerms, q1, True, 2)
	r4, q4, v4 = LSI(documents, incidenceTerms, q2, True, 2)
	
	print "############# 3.3.2 ###############"
	print 
	print "Términos:\n", incidenceTerms
	print "Query 1:\n", q1
	print "Resultado:\n", r1
	print
	print "Query 2:\n", q2
	print "Resultado:\n", r2
	print
	print "############# 3.3.3 ###############"
	print 
	print "Términos:\n", incidenceTerms
	print "Query 1:\n", q3
	print "Resultado:\n", r3
	print
	print "Query 2:\n", q4
	print "Resultado:\n", r4
	pl.plot(v3,q3,'ro')
	pl.show()
	pl.plot(v4,q4,'ro')
	pl.show()
	
