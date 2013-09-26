#include <GL/glut.h>

void dibujarTriangulo(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
        glColor3f(0.0f,0.0f,1.0f);  // color azul (R,G,B) = (0,0,1)
        glVertex3f(-2,-2,-5.0);

        glColor3f(0.0f,1.0f,0.0f);  // color verde (R,G,B) = (0,1,0)
        glVertex3f(2,0.0,-5.0);

        glColor3f(1.0f,0.0f,0.0f);  // color rojo (R,G,B) = (1,0,0)
        glVertex3f(0.0,2,-5.0);
    glEnd();

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
    gluPerspective(45,ratio,1,1000);

    // retornar a la vista del modelo
    glMatrixMode(GL_MODELVIEW);

}

float angle_x = 0.0f, angle_y = 0.0f;

void animarEscena(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    gluLookAt(	0.0f, 0.0f, 10.0f,  // posicion de la camara
            0.0f, 0.0f,  0.0f,      // punto al que mira la camara
            0.0f, 1.0f,  0.0f);     // inclinacion de la camara (0,1,0) = sin inclinacion

    glRotatef(angle_x, 1.0f, 0.0f, 0.0f); // rotar en torno al eje X con un angulo = angle_x
    glRotatef(angle_y, 0.0f, 1.0f, 0.0f); // rotar en torno al eje Y con un angulo = angle_y

    // dibujar triangulo (notar que es basicamente lo mismo que lo que esta en la funcion dibujarTriangulo)
    glBegin(GL_TRIANGLES);
        glColor3f(0.0f,0.0f,1.0f);
        glVertex3f(-2.0f,-2.0f, 0.0f);

        glColor3f(0.0f,1.0f,0.0f);
        glVertex3f( 2.0f, 0.0f, 0.0);

        glColor3f(1.0f,0.0f,0.0f);
        glVertex3f( 0.0f, 2.0f, 0.0);
    glEnd();


    // Draw Body
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(0.0f ,0.0f, 0.0f);
    glutSolidSphere(0.8f,20,20);

    glutSwapBuffers();
}

void processSpecialKeys(int key, int xx, int yy) {

    float fraction = 0.1f;

    switch (key) {
        case GLUT_KEY_LEFT :
            angle_y -= 1.5f;
            break;
        case GLUT_KEY_RIGHT :
            angle_y += 1.5f;
            break;
        case GLUT_KEY_UP :
            angle_x -= 1.5f;
            break;
        case GLUT_KEY_DOWN :
            angle_x += 1.5f;;
            break;
    }
}

int main(int argc, char **argv) {

    // inicializacion de pantalla
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(320,320);
    glutCreateWindow("Triangulo");

    // callback de funcion que dibuja por pantalla
    glutDisplayFunc(dibujarTriangulo);

    // callback re-dimension de ventana
    glutReshapeFunc(cambiarDimension);

    // callback de animacion: "cuando el dibujo se encuentre ocioso, utilzar esta funcion"
    glutIdleFunc(animarEscena);

    glutSpecialFunc(processSpecialKeys);

    // OpenGL init

    //glEnable(GL_LIGHTING);
    glEnable( GL_DEPTH_TEST | GL_LIGHTING);


    // inicializar el pintor
    glutMainLoop();

    return 0;
}
