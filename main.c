#include <GL/glut.h>

#include "state/scene.h"

#include "draw/sky.h"
#include "draw/house.h"
#include "draw/tree.h"
#include "draw/person.h"
#include "draw/smoke.h"

#include "animation/animation.h"

#include "input/keyboard.h"

void desenharGrama()
{
    glColor3f(
        0,
        0.7,
        0
    );

    glBegin(GL_POLYGON);

        glVertex2f(0,0);

        glVertex2f(800,0);

        glVertex2f(800,150);

        glVertex2f(0,150);

    glEnd();
}

void display()
{
    if(cena.estado == 0)
    {
        glClearColor(
            0.5,
            0.8,
            1,
            1
        );
    }
    else
    {
        glClearColor(
            0,
            0,
            0.2,
            1
        );
    }

    glClear(
        GL_COLOR_BUFFER_BIT
    );

    desenharCeu();

    desenharGrama();

    desenharCasa();

    desenharFumaca();

    desenharArvore(
        150,
        150
    );

    desenharJardim();

    desenharArvore(
        650,
        150
    );

    desenharPessoa(
        cena.pessoa1X,
        130,
        1
    );

    desenharPessoa(
        cena.pessoa2X,
        130,
        2
    );

    glFlush();
}

void init()
{
    glMatrixMode(
        GL_PROJECTION
    );

    glLoadIdentity();

    gluOrtho2D(
        0,
        800,
        0,
        600
    );
}

int main(
    int argc,
    char** argv
)
{
    glutInit(
        &argc,
        argv
    );

    glutInitDisplayMode(
        GLUT_SINGLE |
        GLUT_RGB
    );

    glutInitWindowSize(
        800,
        600
    );

    glutCreateWindow(
        "Casa Animada"
    );

    init();

    glutDisplayFunc(
        display
    );

    glutIdleFunc(
        animacao
    );

    glutKeyboardFunc(
        teclado
    );

    glutMainLoop();

    return 0;
}