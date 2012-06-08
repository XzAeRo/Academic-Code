from numpy import *
from matrices import *

if __name__ == "__main__":
	q1 = gs(A)
	q,r = linalg.qr(A)
	print q1
	print q
