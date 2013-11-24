#include <stdio.h>
#include <GL/glut.h>

float x_translation;
int toTheRight

void init(){
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.2,1.2,-1.2,1.2);
    x_translation = 0.0;
    toTheRight = 1;
}

void dibujarFiguras(void) {

    glClear(GL_COLOR_BUFFER_BIT); 

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
        glVertex2f(0.1,-1.0);

        glVertex2f(1.0,-1.0);

        glVertex2f(1.0,0.0);

        glVertex2f(0.1,0.0); 
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

void animarEscena(){
    glClear(GL_COLOR_BUFFER_BIT);



    glLoadIdentity();
    // triangulo
    glTranslatef(x_translation ,0.0f,0.0f);
    glBegin(GL_POLYGON);
        glColor3f(1.0,0.0,0.0);
        glVertex2f(-0.5,0.0);

        glVertex2f(-0.0,-1.0);

        glVertex2f(-1.0,-1.0);
    glEnd();
    glLoadIdentity();

    if (toTheRight == 1){    
        x_translation += 0.01;
        if (x_translation > 2.3)
            toTheRight = 0;
    } else {
        x_translation -= 0.01;
        if (x_translation < -1.3)
            toTheRight = 1;
    }
    
    //Cuadrado
    glBegin(GL_POLYGON);
        glColor3f(0.0,1.0,0.0); 
        glVertex2f(0.1,-1.0);

        glVertex2f(1.0,-1.0);

        glVertex2f(1.0,0.0);

        glVertex2f(0.1,0.0); 
    glEnd();

    //Rectangulo
    glBegin(GL_POLYGON);                                                         
        glColor3f(0.0,0.0,1.0);
        glVertex2f(-1.0,0.1);
                                        
        glVertex2f(-1.0,1.0);
                                           
        glVertex2f(1.0,1.0);  
                                          
        glVertex2f(1.0,0.1);                                             
    glEnd();

    glutSwapBuffers();
}


int main(int argc, char **argv) {

    printf("[init] Inicializando paramtros de GLUT... ");
    // inicializacion de pantalla
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("Tarea 2 - Grupo 03");
    printf("Listo\n");

    // initialize data
    init();

    // callback de funcion que dibuja por pantalla
    printf("[display] Llamando a función de dibujo...\n");
    glutDisplayFunc(dibujarFiguras);

    // callback re-dimension de ventana
    printf("[display] Redimensionado de ventana... ");
    glutReshapeFunc(cambiarDimension);
    printf("Listo\n");

    // callback
    glutIdleFunc(animarEscena);

    // inicializar el pintor
    glutMainLoop();

    return 0;
}
