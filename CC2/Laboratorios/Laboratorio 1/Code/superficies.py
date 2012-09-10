#!/usr/bin/env python
# -*- coding: utf-8 -*-

from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm
from matplotlib.ticker import LinearLocator
import matplotlib.pyplot as plt
import numpy as np
import numpy.linalg as la

def plot_figure(x,y,z):
	fig = plt.figure()
	ax = Axes3D(fig)
	u = np.linspace(0, 2 * np.pi, 100)
	v = np.linspace(0, np.pi, 100)

	x = 10 * np.outer(np.cos(u), np.sin(v))
	y = 10 * np.outer(np.sin(u), np.sin(v))
	z = 10 * np.outer(np.ones(np.size(u)), np.cos(v))
	ax.plot_surface(x, y, z,  rstride=4, cstride=4, color='b')

	plt.show()

def eigen_surface(A,B,C):
	Q, R = la.qr(A)
	Q_inv = la.inv(Q)
	D = Q_inv*A*Q
	print D
	print la.svd(A)

if __name__ == "__main__":
	A = np.array([[5,2,0],[2,6,2],[0,2,7]])
	eigen_surface(A,2,3)
