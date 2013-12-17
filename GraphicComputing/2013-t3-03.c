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

// vertices de las figuras
const float vertice_rectangulo[2][2][2][3] = {{{{-1.0, 0.1, -1.0}, {-1.0, 0.1, 0.0}},
                                               {{-1.0, 1.0, -1.0}, {-1.0, 1.0, 0.0}}},
                                              {{{ 1.0, 0.1, -1.0}, { 1.0, 0.1, 0.0}},
                                               {{ 1.0, 1.0, -1.0}, { 1.0, 1.0, 0.0}}}};

const float vertice_cuadrado[2][2][2][3] = {{{{ 0.0, -1.0, -1.0}, { 0.0, -1.0, 0.0}},
                                             {{ 0.0,  0.0, -1.0}, { 0.0,  0.0, 0.0}}},
                                            {{{ 1.0, -1.0, -1.0}, { 1.0, -1.0, 0.0}},
                                             {{ 1.0,  0.0, -1.0}, { 1.0,  0.0, 0.0}}}};

const float vertice_triangulo[2][2][2][3] = {{{{-1.0, -1.0, -1.0}, {-1.0, -1.0, 0.0}},
                                              {{-0.5,  0.0, -1.0}, {-0.5,  0.0, 0.0}}},
                                             {{{ 0.0, -1.0, -1.0}, { 0.0, -1.0, 0.0}},
                                              {{-0.5,  0.0, -1.0}, {-0.5,  0.0, 0.0}}}};

// estado inicial camara
static float cam[]= {0.0, 0.0, 1.2};
static float delta_cam = 0.1f;

void cuadrado(){

    glBegin(GL_POLYGON);
    
        glColor3f(0.0, 1.0, 0.0);

        //frente
        glVertex3fv(vertice_cuadrado[0][0][1]);
        glVertex3fv(vertice_cuadrado[0][1][1]);
        glVertex3fv(vertice_cuadrado[1][1][1]);
        glVertex3fv(vertice_cuadrado[1][0][1]);

        //fondo
        glVertex3fv(vertice_cuadrado[0][0][0]);
        glVertex3fv(vertice_cuadrado[0][1][0]);
        glVertex3fv(vertice_cuadrado[1][1][0]);
        glVertex3fv(vertice_cuadrado[1][0][0]);

        //arriba
        glVertex3fv(vertice_cuadrado[0][1][0]);
        glVertex3fv(vertice_cuadrado[0][1][1]);
        glVertex3fv(vertice_cuadrado[1][1][1]);
        glVertex3fv(vertice_cuadrado[1][1][0]);

        //abajo
        glVertex3fv(vertice_cuadrado[0][0][0]);
        glVertex3fv(vertice_cuadrado[0][0][1]);
        glVertex3fv(vertice_cuadrado[1][0][1]);
        glVertex3fv(vertice_cuadrado[1][0][0]);

        //derecha
        glVertex3fv(vertice_cuadrado[1][0][0]);
        glVertex3fv(vertice_cuadrado[1][0][1]);
        glVertex3fv(vertice_cuadrado[1][1][1]);
        glVertex3fv(vertice_cuadrado[1][1][0]);

        //izquierda
        glVertex3fv(vertice_cuadrado[0][0][0]);
        glVertex3fv(vertice_cuadrado[0][0][1]);
        glVertex3fv(vertice_cuadrado[0][1][1]);
        glVertex3fv(vertice_cuadrado[0][1][0]);

  glEnd();

}

void rectangulo(){

    glBegin(GL_POLYGON);
    
        glColor3f(0.0, 0.0, 1.0);

        //frente
        glVertex3fv(vertice_rectangulo[0][0][1]);
        glVertex3fv(vertice_rectangulo[0][1][1]);
        glVertex3fv(vertice_rectangulo[1][1][1]);
        glVertex3fv(vertice_rectangulo[1][0][1]);

        //fondo
        glVertex3fv(vertice_rectangulo[0][0][0]);
        glVertex3fv(vertice_rectangulo[0][1][0]);
        glVertex3fv(vertice_rectangulo[1][1][0]);
        glVertex3fv(vertice_rectangulo[1][0][0]);

        //arriba
        glVertex3fv(vertice_rectangulo[0][1][0]);
        glVertex3fv(vertice_rectangulo[0][1][1]);
        glVertex3fv(vertice_rectangulo[1][1][1]);
        glVertex3fv(vertice_rectangulo[1][1][0]);

        //abajo
        glVertex3fv(vertice_rectangulo[0][0][0]);
        glVertex3fv(vertice_rectangulo[0][0][1]);
        glVertex3fv(vertice_rectangulo[1][0][1]);
        glVertex3fv(vertice_rectangulo[1][0][0]);

        //derecha
        glVertex3fv(vertice_rectangulo[1][0][0]);
        glVertex3fv(vertice_rectangulo[1][0][1]);
        glVertex3fv(vertice_rectangulo[1][1][1]);
        glVertex3fv(vertice_rectangulo[1][1][0]);

        //izquierda
        glVertex3fv(vertice_rectangulo[0][0][0]);
        glVertex3fv(vertice_rectangulo[0][0][1]);
        glVertex3fv(vertice_rectangulo[0][1][1]);
        glVertex3fv(vertice_rectangulo[0][1][0]);

  glEnd();

}


void triangulo()
{
  glBegin(GL_POLYGON);

    glColor3f(1.0, 0.0, 0.0);
    //frente
    glVertex3fv(vertice_triangulo[0][0][1]);
    glVertex3fv(vertice_triangulo[0][1][1]);
    glVertex3fv(vertice_triangulo[1][0][1]);

    //fondo
    glVertex3fv(vertice_triangulo[0][0][0]);
    glVertex3fv(vertice_triangulo[0][1][0]);
    glVertex3fv(vertice_triangulo[1][0][0]);

    //abajo
    glVertex3fv(vertice_triangulo[0][0][0]);
    glVertex3fv(vertice_triangulo[0][0][1]);
    glVertex3fv(vertice_triangulo[1][0][1]);
    glVertex3fv(vertice_triangulo[1][0][0]);

    //derecha
    glVertex3fv(vertice_triangulo[1][0][0]);
    glVertex3fv(vertice_triangulo[1][0][1]);
    glVertex3fv(vertice_triangulo[1][1][1]);
    glVertex3fv(vertice_triangulo[1][1][0]);

    //izquierda
    glVertex3fv(vertice_triangulo[0][0][0]);
    glVertex3fv(vertice_triangulo[0][0][1]);
    glVertex3fv(vertice_triangulo[0][1][1]);
    glVertex3fv(vertice_triangulo[0][1][0]);
    
  glEnd();
}
/*

/***
 * pantalla a visualizar, crea las figuras
 */
void dibujarFiguras(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluLookAt(cam[0], cam[1], cam[2], 0.0, 0.0, -5.0, 0.0, 1.0, 0.0);

    rectangulo();

        cuadrado();


    triangulo();

    glFlush();
    glutSwapBuffers();
}

/***
 * Cambia los parametros que generan rotacion y traslacion en las figuras.
 */
void animar()
{
  glutPostRedisplay();
}

/***
 * acciones a realizar por el teclado
 */
void processSpecialKeys(unsigned char key, int x, int y)
{
  if(key == 'x')
    cam[0] += delta_cam;
  if(key == 'X')
    cam[0] -= delta_cam;
    
  if(key == 'y')
    cam[1] += delta_cam;
  if(key == 'Y')
    cam[1] -= delta_cam;
    
  if(key == 'z')
    cam[2] += delta_cam;
  if(key == 'Z')
    cam[2] -= delta_cam;


switch (key) {
        case 'x' :
            cam[0] += delta_cam;
            break;
        case 'X' :
            cam[0] -= delta_cam;
            break;
        case 'y' :
            cam[1] += delta_cam;
            break;
        case 'Y' :
            cam[1] -= delta_cam;
            break;
        case 'z' :
            cam[2] += delta_cam;
            break;
        case 'Z' :
            cam[2] -= delta_cam;
            break;
        case 'r' :
            cam[0] = 0.0;
            cam[1] = 0.0;
            cam[2] = 1.2;
            break;
    }

}

/***
 * parametros iniciales de forma
 */
void cambiarDimension(int w, int h)
{
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glViewport(-1, -1, w, h);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  
  glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 200.0);

  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {

    // inicializacion de pantalla
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("Tarea 3 - Grupo 03");

    printf("Teclas disponibles:\n");
    printf("\t'x': avanzar camara por el eje x.\n");
    printf("\t'X': retroceder camara por el eje x.\n");
    printf("\t'y': avanzar camara por el eje y.\n");
    printf("\t'Y': retroceder camara por el eje y.\n");
    printf("\t'z': avanzar camara por el eje z.\n");
    printf("\t'Z': retroceder camara por el eje z.\n");
    printf("\t'r': resetear camara al punto inicial.\n");

    // callback de funcion que dibuja por pantalla
    glutDisplayFunc(dibujarFiguras);

    // callback de dibujo actualizado
    glutIdleFunc(animar);

    // callback re-dimension de ventana
    glutReshapeFunc(cambiarDimension);

    // callback de teclado
    glutKeyboardFunc(processSpecialKeys);

    glEnable( GL_DEPTH_TEST );

    // inicializar el pintor
    glutMainLoop();

    return 0;
}