#include <GL/glut.h>

#include <math.h>

#include "person.h"
#include "shapes.h"

#include "../state/scene.h"

extern Scene cena;



void desenharPessoa(
    float x,
    float y,
    int tipo
)
{
    float movimento =
        sin(
            cena.anguloPerna
        ) * 8;



    // cabeça

    glColor3f(
        1,
        0.85,
        0.7
    );

    circulo(
        x,
        y+60,
        12
    );



    // cabelo

    if(tipo==1)
    {
        glColor3f(
            0.1,
            0.1,
            0.1
        );
    }
    else
    {
        glColor3f(
            0.4,
            0.2,
            0
        );
    }

    circulo(
        x,
        y+66,
        10
    );



    // olhos

    glPointSize(
        3
    );

    glColor3f(
        0,
        0,
        0
    );

    glBegin(
        GL_POINTS
    );

        glVertex2f(
            x-4,
            y+62
        );

        glVertex2f(
            x+4,
            y+62
        );

    glEnd();



    // roupa

    if(tipo==1)
    {
        glColor3f(
            0.2,
            0.2,
            1
        );
    }
    else
    {
        glColor3f(
            1,
            0.2,
            0.5
        );
    }

    glBegin(
        GL_POLYGON
    );

        glVertex2f(
            x-12,
            y+45
        );

        glVertex2f(
            x+12,
            y+45
        );

        glVertex2f(
            x+10,
            y+10
        );

        glVertex2f(
            x-10,
            y+10
        );

    glEnd();



    // braços

    glColor3f(
        1,
        0.85,
        0.7
    );

    glBegin(
        GL_LINES
    );

        glVertex2f(
            x-12,
            y+35
        );

        glVertex2f(
            x-25,
            y+20
        );

        glVertex2f(
            x+12,
            y+35
        );

        glVertex2f(
            x+25,
            y+20
        );

    glEnd();



    // pernas

    glColor3f(
        0,
        0,
        0
    );

    glBegin(
        GL_LINES
    );

        glVertex2f(
            x-5,
            y+10
        );

        glVertex2f(
            x-10+movimento,
            y-20
        );



        glVertex2f(
            x+5,
            y+10
        );

        glVertex2f(
            x+10-movimento,
            y-20
        );

    glEnd();



    // sapatos

    glBegin(
        GL_LINES
    );

        glVertex2f(
            x-10+movimento,
            y-20
        );

        glVertex2f(
            x-16+movimento,
            y-20
        );



        glVertex2f(
            x+10-movimento,
            y-20
        );

        glVertex2f(
            x+16-movimento,
            y-20
        );

    glEnd();
}