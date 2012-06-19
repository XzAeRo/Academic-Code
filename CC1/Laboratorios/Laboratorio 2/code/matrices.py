# -*- coding: utf-8 -*-

from numpy import *

A = array([[12,-51,4],[6,167,-68],[-4,24,-41]]).astype(float)
B = array([[19,0,0],[0,5,0],[7,0,0],[0,0,23],[0,31,0],[91,0,7],[13,41,19]]).astype(float)
C = array([[1,1,0,0],[2,1,-1,1],[-2,1,3,0],[0,1,1,0],[0,0,0,1]]).astype(float)
D = array([[-1,1,-1,2],[1,-2,3,-3],[-1,1,0,1],[0,-1,2,-2]]).astype(float)
E = array([[2,3,0,1,8,1],[-5,1,4,-2,-2,5],[1,0,0,-3,9,2]]).astype(float)

documents = array(["Análisis automático de datos en astronomía",
	"Minería de datos distribuidos",
	"Nuevas plataformas para computación en nube",
	"Bases de datos no relacionales distribuidos en computación nube",
	"Astronomía en informática",
	"Implementación de un método molecular para la detección del virus de la influenza humana",
	"Valoración molecular de esquemas de virus humano",
	"Actividad del virus de la coriomeningitis"])
	
incidenceTerms = array(["análisis","automático","datos","astronomía","minería",
	"distribuidos","plataformas","computación","nube","bases","relacionales",
	"informática","método","molecular","detección","virus","humana","humano"])
	
q1 = array(["datos","distribuidos","informátca"])
q2 = array(["virus","nube"])
