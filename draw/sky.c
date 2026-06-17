#include <GL/glut.h>

#include "sky.h"
#include "shapes.h"

#include "../state/scene.h"

#define PI 3.1415926

extern Scene cena;



static void desenharSol()
{
    glColor3f(
        1,
        1,
        0
    );

    circulo(
        700,
        500,
        40
    );

    glBegin(
        GL_LINES
    );

    for(
        int i=0;
        i<360;
        i+=30
    )
    {
        float ang =
            i *
            PI /
            180;

        glVertex2f(
            700 +
            cos(ang)*45,

            500 +
            sin(ang)*45
        );

        glVertex2f(
            700 +
            cos(ang)*65,

            500 +
            sin(ang)*65
        );
    }

    glEnd();
}



static void desenharLua()
{
    glColor3f(
        1,
        1,
        1
    );

    circulo(
        700,
        500,
        35
    );

    glColor3f(
        0,
        0,
        0.2
    );

    circulo(
        715,
        505,
        30
    );
}



static void desenharNuvem(
    float x,
    float y
)
{
    glColor3f(
        1,
        1,
        1
    );

    circulo(
        x,
        y,
        25
    );

    circulo(
        x+25,
        y+10,
        25
    );

    circulo(
        x+50,
        y,
        25
    );
}



static void desenharEstrelas()
{
    glColor3f(
        cena.brilhoEstrela,
        cena.brilhoEstrela,
        cena.brilhoEstrela
    );

    float estrelas[][2] =
    {
        {100,520},
        {180,470},
        {250,540},
        {330,500},
        {450,530},
        {550,480},
        {640,540}
    };

    for(
        int i=0;
        i<7;
        i++
    )
    {
        circulo(
            estrelas[i][0],
            estrelas[i][1],
            3
        );
    }
}



void desenharCeu()
{
    if(
        cena.estado ==
        0
    )
    {
        desenharSol();

        desenharNuvem(
            100 +
            cena.nuvemX,

            500
        );

        desenharNuvem(
            300 +
            cena.nuvemX,

            450
        );
    }
    else
    {
        desenharLua();

        desenharEstrelas();
    }
}