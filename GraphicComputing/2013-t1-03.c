#include <stdio.h>
#include <GL/glut.h>

void dibujarFiguras(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    glClearColor(1.0,1.0,1.0,1.0);
    double xy_margin = -1.2;

    //Triangulo
    printf("[dibujo] Dibujando triangulo... ");
    glBegin(GL_POLYGON);
        glColor3f(1.0,0.0,0.0);
        glVertex3f(-0.5,0.0,xy_margin);

        glColor3f(1.0,0.0,0.0);
        glVertex3f(-0.0,-1.0,xy_margin);

        glColor3f(1.0,0.0,0.0);
        glVertex3f(-1.0,-1.0,xy_margin);
    glEnd();
    printf("Listo\n");

    //Cuadrado
    printf("[dibujo] Dibujando cuadrado... ");
    glBegin(GL_POLYGON);
        glColor3f(0.0,1.0,0.0); 
        glVertex3f(0.1,-1.0,xy_margin);

        glColor3f(0.0,1.0,0.0);
        glVertex3f(1.0,-1.0,xy_margin);

        glColor3f(0.0,1.0,0.0);
        glVertex3f(1.0,0.0,xy_margin);

        glColor3f(0.0,1.0,0.0);
        glVertex3f(0.1,0.0,xy_margin); 
    glEnd();
    printf("Listo\n");

    //Rectangulo
    printf("[dibujo] Dibujando rectangulo... ");
    glBegin(GL_POLYGON);                                                         
        glColor3f(0.0,0.0,1.0);
        glVertex3f(-1.0,0.1,xy_margin);

        glColor3f(0.0,0.0,1.0);                                              
        glVertex3f(-1.0,1.0,xy_margin);

        glColor3f(0.0,0.0,1.0);                                              
        glVertex3f(1.0,1.0,xy_margin);  

        glColor3f(0.0,0.0,1.0);                                              
        glVertex3f(1.0,0.1,xy_margin);                                             
    glEnd();
    printf("Listo\n\n");

    glutSwapBuffers();
}

void cambiarDimension(int w, int h) {
    // prevenir division por cero
    if(h == 0)
        h = 1;
    float ratio = 1.0* w / h;

    // usar matriz de proyeccion
    glMatrixMode(GL_PROJECTION);

    // resetear matriz (matriz identidad)
    glLoadIdentity();

    // fijar la visualizacion al porte de la ventana
    glViewport(0, 0, w, h);

    // fijar la perspectiva correcta
    gluPerspective(90,ratio,1,1000);

    // retornar a la vista del modelo
    glMatrixMode(GL_MODELVIEW);

    printf("[display] Nueva dimension de ventana:\n\t\tAncho: %i px\n\t\tAlto: %i px\n",w,h);
}



int main(int argc, char **argv) {

    printf("[init] Inicializando paramtros de GLUT... ");
    // inicializacion de pantalla
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("Tarea 1 - Grupo 03");
    printf("Listo\n");

    // callback de funcion que dibuja por pantalla
    printf("[display] Llamando a función de dibujo...\n");
    glutDisplayFunc(dibujarFiguras);

    // callback re-dimension de ventana
    printf("[display] Redimensionado de ventana... ");
    glutReshapeFunc(cambiarDimension);
    printf("Listo\n");

    // modo 3D
    glEnable( GL_DEPTH_TEST);

    // inicializar el pintor
    glutMainLoop();

    return 0;
}
