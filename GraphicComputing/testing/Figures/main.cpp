#include <GL/glut.h>

void dibujarTriangulo(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // se limpian los canales de dibujo

    glBegin(GL_TRIANGLES);  // le decimos a OpenGL que dibujaremos un triangulo
        glColor3f(0.0f,0.0f,1.0f);      // color azul (R,G,B) = (0,0,1)
        glVertex3f( 0.0f, 1.0f, 0.0f);  // position relativa (x,y,z) = (0,1,0) punto de arriba

        glColor3f(0.0f,1.0f,0.0f);      // color verde (R,G,B) = (0,1,0)
        glVertex3f(-1.0f,-1.0f, 0.0f);  // position relativa (x,y,z) = (-1,-1,0) punto inferior izquierdo

        glColor3f(1.0f,0.0f,0.0f);      // color rojo (R,G,B) = (1,0,0)
        glVertex3f( 1.0f,-1.0f, 0.0f);  // position relativa (x,y,z) = (1,-1,0) punto inferior derecho
    glEnd();

    glutSwapBuffers();  // eviamos el dibujo a la pantalla
}

int main(int argc, char **argv) {

    // inicializacion de pantalla
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("Triangulo Homosexual");

    // funciones que dibujaran por pantalla
    glutDisplayFunc(dibujarTriangulo);

    // inicializar el pintor
    glutMainLoop();

    return 1;
}
