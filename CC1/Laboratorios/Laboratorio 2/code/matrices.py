from numpy import *

A = array([[12,-51,4],[6,167,-68],[-4,24,-41]])
B = array([[19,0,0],[0,5,0],[7,0,0],[0,0,23],[0,31,0],[91,0,7],[13,41,19]])
C = array([[1,1,0,0],[2,1,-1,1],[-2,1,3,0],[0,1,1,0],[0,0,0,1]])
D = array([[-1,1,-1,2],[1,-2,3,-3],[-1,1,0,1],[0,-1,2,-2]])
E = array([[2,3,0,1,8,1],[-5,1,4,-2,-2,5],[1,0,0,-3,9,2]])

def gs_cofficient(v1, v2):
    return dot(v2, v1) / dot(v1, v1)

def multiply(cofficient, v):
    return map((lambda x : x * cofficient), v)

def proj(v1, v2):
    return multiply(gs_cofficient(v1, v2) , v1)

def gs(X):
    Y = []
    for i in range(len(X)):
        temp_vec = X[i]
        for inY in Y :
            proj_vec = proj(inY, X[i])
            temp_vec = map(lambda x, y : x - y, temp_vec, proj_vec)
        
        temp_vec = temp_vec / linalg.norm(temp_vec)
        Y.append(temp_vec)
    return array(Y)
