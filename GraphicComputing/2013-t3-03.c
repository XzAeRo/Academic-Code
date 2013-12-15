/***

Universidad Tecnica Federico Santa Maria
Departamento de Informatica
Segundo Semestre 2013

[INF-342] Computacion Grafica
Profesor: Hubert Hoffmann
Tarea 3

Autores (Grupo 3):
- Patricia Fredes
- Victor Gonzalez

***/

#include <stdio.h>
#include <GL/glut.h>

void init(){
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.2,1.2,-1.2,1.2);
}

void dibujarFiguras(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

    //Triangulo
    printf("[dibujo] Dibujando triangulo... ");
    glBegin(GL_POLYGON);
        glColor3f(1.0,0.0,0.0);
        glVertex2f(-0.5,0.0);
        glVertex2f(-0.0,-1.0);
        glVertex2f(-1.0,-1.0);
    glEnd();
    printf("Listo\n");

    //Cuadrado
    printf("[dibujo] Dibujando cuadrado... ");
    glBegin(GL_POLYGON);
        glColor3f(0.0,1.0,0.0); 
        glVertex2f(0.0,-1.0);
        glVertex2f(1.0,-1.0);
        glVertex2f(1.0,0.0);
        glVertex2f(0.0,0.0); 
    glEnd();
    printf("Listo\n");

    //Rectangulo
    printf("[dibujo] Dibujando rectangulo... ");
    glBegin(GL_POLYGON);                                                         
        glColor3f(0.0,0.0,1.0);
        glVertex2f(-1.0,0.1);                        
        glVertex2f(-1.0,1.0);                             
        glVertex2f(1.0,1.0);                                
        glVertex2f(1.0,0.1);                                             
    glEnd();
    printf("Listo\n\n");

    glutSwapBuffers();
}

void cambiarDimension(int w, int h) {
    // prevenir division por cero
    if(h == 0)
        h = 1;
    float ratio = 1.0* w / h;

    init();

    // fijar la visualizacion al porte de la ventana
    glViewport(0, 0, w, h);

    // fijar la perspectiva correcta
    gluPerspective(0,ratio,0,1);

    // retornar a la vista del modelo
    glMatrixMode(GL_MODELVIEW);

    printf("[display] Nueva dimension de ventana:\n\t\tAncho: %i px\n\t\tAlto: %i px\n",w,h);
}

void processSpecialKeys(int key, int xx, int yy) {

    float fraction = 0.1f;

    switch (key) {
        case GLUT_KEY_LEFT :
            break;
        case GLUT_KEY_RIGHT :
            break;
        case GLUT_KEY_UP :
            break;
        case GLUT_KEY_DOWN :
            break;
    }
}


int main(int argc, char **argv) {

    printf("[init] Inicializando paramtros de GLUT... ");
    // inicializacion de pantalla
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("Tarea 3 - Grupo 03");
    printf("Listo\n");

    // inicialización de datos globales
    init();

    // callback de funcion que dibuja por pantalla
    printf("[display] Llamando a función de dibujo...\n");
    glutDisplayFunc(dibujarFiguras);

    // callback re-dimension de ventana
    printf("[display] Redimensionado de ventana... ");
    glutReshapeFunc(cambiarDimension);
    printf("Listo\n");

    glutSpecialFunc(processSpecialKeys);
    glEnable( GL_DEPTH_TEST );

    // inicializar el pintor
    glutMainLoop();

    return 0;
}
