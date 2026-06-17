#include <GL/glut.h>

#include "tree.h"
#include "shapes.h"



static void desenharFlor(
    float x,
    float y,
    float r,
    float g,
    float b
)
{
    glColor3f(
        0,
        0.7,
        0
    );

    glBegin(
        GL_LINES
    );

        glVertex2f(
            x,
            y
        );

        glVertex2f(
            x,
            y + 15
        );

    glEnd();



    glColor3f(
        r,
        g,
        b
    );

    circulo(
        x,
        y+20,
        4
    );

    circulo(
        x-4,
        y+16,
        4
    );

    circulo(
        x+4,
        y+16,
        4
    );

    circulo(
        x,
        y+12,
        4
    );
}



void desenharJardim()
{
    desenharFlor(
        100,
        70,
        1,
        0,
        0
    );

    desenharFlor(
        140,
        90,
        1,
        1,
        0
    );

    desenharFlor(
        180,
        60,
        1,
        0,
        1
    );



    desenharFlor(
        620,
        70,
        0,
        0,
        1
    );

    desenharFlor(
        670,
        90,
        1,
        0.5,
        0
    );

    desenharFlor(
        720,
        60,
        1,
        0,
        0
    );
}



void desenharArvore(
    float x,
    float y
)
{
    glColor3f(
        0.5,
        0.2,
        0
    );

    glBegin(
        GL_POLYGON
    );

        glVertex2f(
            x-10,
            y
        );

        glVertex2f(
            x+10,
            y
        );

        glVertex2f(
            x+10,
            y+70
        );

        glVertex2f(
            x-10,
            y+70
        );

    glEnd();



    glColor3f(
        0,
        0.6,
        0
    );

    circulo(
        x,
        y+110,
        35
    );

    circulo(
        x-25,
        y+90,
        30
    );

    circulo(
        x+25,
        y+90,
        30
    );



    glColor3f(
        1,
        0,
        0
    );

    circulo(
        x-10,
        y+100,
        4
    );

    circulo(
        x+15,
        y+115,
        4
    );

    circulo(
        x+5,
        y+90,
        4
    );
}