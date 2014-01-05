/***

Universidad Tecnica Federico Santa Maria
Departamento de Informatica
Segundo Semestre 2013

[INF-342] Computacion Grafica
Profesor: Hubert Hoffmann
Tarea 4

Autores (Grupo 3):
- Patricia Fredes
- Victor Gonzalez

Tomado desde el codigo fuente de 06-sphere.cpp

***/

//	Recursive subdivision of cube (Chapter 6).
//	Three display modes: wire frame, constant, and interpolative shading
//	Program also illustrates defining materials and light sources

#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

typedef float point[4];

// Initial tetrahedron

point v[]={{0.0, 0.0, 1.0}, {0.0, 0.942809, -0.33333},
          {-0.816497, -0.471405, -0.333333}, {0.816497, -0.471405, -0.333333}};

int n=4, mode;
GLfloat light0_position[]={1.0,  1.0, 1.0, 0.0};
GLfloat light1_position[]={1.0, -1.0, 1.0, 0.0};
float step = 0.1f;

// Display one triangle using a line loop for wire frame, a single
// normal for constant shading, or three normals for interpolative shading
void triangle(point a, point b, point c)
{	
	glBegin(GL_POLYGON);
		glNormal3fv(a);
		glVertex3fv(a);
		glNormal3fv(b);
		glVertex3fv(b);
		glNormal3fv(c);
		glVertex3fv(c);
	glEnd();
}

// Normalize a vector
void normal(point p)
{	
	float d =0.0;
	int i;
	for(i=0; i<3; i++) d+=p[i]*p[i];
		d=sqrt(d);
	if(d>0.0) for(i=0; i<3; i++) p[i]/=d;
}

// Triangle subdivision using vertex numbers
// righthand rule applied to create outward pointing faces
void divide_triangle(point a, point b, point c, int m)
{	point v1, v2, v3;
	int j;
	if(m>0)
	{	for(j=0; j<3; j++) v1[j]=a[j]+b[j];
		normal(v1);
		for(j=0; j<3; j++) v2[j]=a[j]+c[j];
		normal(v2);
		for(j=0; j<3; j++) v3[j]=b[j]+c[j];
		normal(v3);
		divide_triangle(a, v1, v2, m-1);
		divide_triangle(c, v2, v3, m-1);
		divide_triangle(b, v3, v1, m-1);
		divide_triangle(v1, v3, v2, m-1);
	}
	else(triangle(a,b,c)); /* draw triangle at end of recursion */
}

/* Apply triangle subdivision to faces of tetrahedron */
void tetrahedron(int m)
{	divide_triangle(v[0], v[1], v[2], m);
	divide_triangle(v[3], v[2], v[1], m);
	divide_triangle(v[0], v[3], v[1], m);
	divide_triangle(v[0], v[2], v[3], m);
}

void updateLights(){
	glLightfv(GL_LIGHT0, GL_POSITION,light0_position);
	glLightfv(GL_LIGHT1, GL_POSITION,light1_position);
}

/* Displays all three modes, side by side */
void display(void)
{	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	updateLights();
	glLoadIdentity();
	tetrahedron(n);
	glFlush();
}

void myReshape(int w, int h)
{	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w <= h)
		glOrtho(-1.5,1.5,-1.5*(GLfloat)h/(GLfloat)w,
      			+1.5*(GLfloat)h/(GLfloat)w,-10.0,10.0);
	else
   		glOrtho(-1.5*(GLfloat)w/(GLfloat)h,
      			+1.5*(GLfloat)w/(GLfloat)h,-1.5,1.5,-10.0,10.0);
	glMatrixMode(GL_MODELVIEW);
	display();
}

void myinit(void)
{ 	GLfloat mat_specular[]=  {1.0, 1.0, 1.0, 1.0};
	GLfloat mat_diffuse[]=   {1.0, 1.0, 1.0, 1.0};
	GLfloat mat_ambient[]=   {1.0, 1.0, 1.0, 1.0};
	GLfloat mat_shininess=   {100.0};

	GLfloat light0_ambient[]= {0.0, 0.0, 1.0, 1.0};
	GLfloat light0_diffuse[]= {1.0, 1.0, 1.0, 1.0};
	GLfloat light0_specular[]={1.0, 1.0, 1.0, 1.0};

	GLfloat light1_ambient[]= {1.0, 0.0, 0.0, 1.0};
	GLfloat light1_diffuse[]= {1.0, 1.0, 1.0, 1.0};
	GLfloat light1_specular[]={1.0, 1.0, 1.0, 1.0};

/* set up ambient, diffuse, and specular components for light 0 */
	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR,light0_specular);
	glLightfv(GL_LIGHT0, GL_POSITION,light0_position);

/* set up ambient, diffuse, and specular components for light 1 */
	glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR,light1_specular);
	glLightfv(GL_LIGHT1, GL_POSITION,light1_position);

/* define material proerties for front face of all polygons */
	glMaterialfv(GL_FRONT,GL_SPECULAR,	mat_specular);
	glMaterialfv(GL_FRONT,GL_AMBIENT,	mat_ambient);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,	mat_diffuse);
	glMaterialf(GL_FRONT, GL_SHININESS,mat_shininess);
	glEnable(GL_SMOOTH);		/*enable smooth shading */
	glEnable(GL_LIGHTING);		/* enable lighting */
	glEnable(GL_LIGHT0);		/* enable light 0 */
	glEnable(GL_LIGHT1);		/* enable light 1 */
	glEnable(GL_DEPTH_TEST);	/* enable z buffer */
	glClearColor(0.0, 0.4, 0.4, 1.0);
	glColor3f(0.0, 0.0, 0.0);
}

void processSpecialKeys(unsigned char key, int x, int y)
{
	switch (key) {
	    case '0' :
	    	glDisable(GL_LIGHT0);
	        break;
	    case '1' :
	    	glEnable(GL_LIGHT0);
	        break;
	    case '2' :
	    	glDisable(GL_LIGHT1);
	        break;
	    case '3' :
	    	glEnable(GL_LIGHT1);
	        break;
	    case 'x' :
	    	light0_position[0] -= step;
	        break;
	    case 'X' :
	    	light0_position[0] += step;
	        break;
	    case 'y' :
	    	light0_position[1] -= step;
	        break;
	    case 'Y' :
	    	light0_position[1] += step;
	        break;
	    case 'z' :
	    	light0_position[2] -= step;
	        break;
	    case 'Z' :
	    	light0_position[2] += step;
	        break;
	    case 'a' :
	    	light1_position[0] -= step;
	        break;
	    case 'A' :
	    	light1_position[0] += step;
	        break;
	    case 'b' :
	    	light1_position[1] -= step;
	        break;
	    case 'B' :
	    	light1_position[1] += step;
	        break;
	    case 'c' :
	    	light1_position[2] -= step;
	        break;
	    case 'C' :
	    	light1_position[2] += step;
	        break;
	    case 'r' :
			light0_position[0] = 1.0;
			light0_position[1] = 1.0;
			light0_position[2] = 1.0;

			light1_position[0] = 1.0;
			light1_position[1] =-1.0;
			light1_position[2] = 1.0;

			glEnable(GL_LIGHT0);
			glEnable(GL_LIGHT1);
	    	break;
	    case 27: // Escape key
			exit (0);
			break;
	}

}

int main(int argc, char **argv)
{	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Tarea 4 - Grupo 3");
	myinit();
	glutKeyboardFunc(processSpecialKeys);
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutIdleFunc(display);

	printf("\nTeclas disponibles:\n\n");

	printf("Light0 (azul):\n\t");
	printf("'0': Apagar fuente de luz");
	printf("\r\t\t\t\t\t'1': Encender fuente de luz\n\t");
	printf("'x': Mover en direccion -x");
	printf("\r\t\t\t\t\t'X': Mover en direccion +x\n\t");
	printf("'y': Mover en direccion -y");
	printf("\r\t\t\t\t\t'Y': Mover en direccion +y\n\t");
	printf("'z': Mover en direccion -z");
	printf("\r\t\t\t\t\t'Z': Mover en direccion +z\n\t");

	printf("\nLight1 (rojo):\n\t");
	printf("'2': Apagar fuente de luz");
	printf("\r\t\t\t\t\t'3': Encender fuente de luz\n\t");
	printf("'a': Mover en direccion -x");
	printf("\r\t\t\t\t\t'A': Mover en direccion +x\n\t");
	printf("'b': Mover en direccion -y");
	printf("\r\t\t\t\t\t'B': Mover en direccion +y\n\t");
	printf("'c': Mover en direccion -z");
	printf("\r\t\t\t\t\t'C': Mover en direccion +z\n\t");

	printf("\nGlobales:\n\t");
	printf("ESC: Salir de la aplicacion\n\t");
	printf("'r': Volver al estado inicial (reset)\n");

	glutMainLoop();
	return 0;
}