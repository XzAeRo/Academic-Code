#!/usr/bin/env python
# -*- coding: utf-8 -*-
try:
	from mpl_toolkits.mplot3d import Axes3D
	from matplotlib import cm
	from matplotlib.ticker import LinearLocator
	import matplotlib.pyplot as plt
except:
	print "Missing matplotlib modules:\n\t- mpl_toolkits.mplot3d\n\t- matplotlib\n\t- matplotlib.ticker\n\t- matplotlib.pyplot\n\tIgnoring...\n\n"

import numpy as np
import numpy.linalg as la

def plot_implicit(fn, bbox=(-2.5,2.5)):
    ''' create a plot of an implicit function
    fn  ...implicit function (plot where fn==0)
    bbox ..the x,y,and z limits of plotted interval'''
    xmin, xmax, ymin, ymax, zmin, zmax = bbox*3
    fig = plt.figure()
    ax = Axes3D(fig)
    A = np.linspace(xmin, xmax, 100) # resolution of the contour
    B = np.linspace(xmin, xmax, 15) # number of slices
    A1,A2 = np.meshgrid(A,A) # grid on which the contour is plotted

    for z in B: # plot contours in the XY plane
        X,Y = A1,A2
        Z = fn(X,Y,z)
        cset = ax.contour(X, Y, Z+z, [z], zdir='z')
        # [z] defines the only level to plot for this contour for this value of z

    for y in B: # plot contours in the XZ plane
        X,Z = A1,A2
        Y = fn(X,y,Z)
        cset = ax.contour(X, Y+y, Z, [y], zdir='y')

    for x in B: # plot contours in the YZ plane
        Y,Z = A1,A2
        X = fn(x,Y,Z)
        cset = ax.contour(X+x, Y, Z, [x], zdir='x')

    # must set plot limits because the contour will likely extend
    # way beyond the displayed level.  Otherwise matplotlib extends the plot limits
    # to encompass all values in the contour.
    ax.set_zlim3d(zmin,zmax)
    ax.set_xlim3d(xmin,xmax)
    ax.set_ylim3d(ymin,ymax)

    plt.show()

def implicit_function(x,y,z):
	xyz = np.transpose(np.array([x,y,z]))
	return np.transpose(xyz)*D*xyz + B*Q
def surface(A, B, C, D):
	plot_implicit

def eigen_surface(A, B, C):

	A_k = A
	Q_k = np.array
	
	for i in range(1,45):	
		Q,R = la.qr(A_k)
		A_k = np.dot(R,Q)
		if i != 1:
			Q_k=np.dot(Q_k,Q)
		else: 
			Q_k = Q
			
	D = np.dot(np.dot(la.inv(Q_k),A),Q_k)
	
	surface(A,B,C,D,Q_k)
	
	

if __name__ == "__main__":
	A = np.array([[5,2,0],[2,6,2],[0,2,7]])
	B = np.array([0,0,0])
	C = -1
