#include <GL/glut.h>

#include "house.h"
#include "shapes.h"

#include "../state/scene.h"

extern Scene cena;

void desenharCasa()
{
    // Corpo
    glColor3f(
        0.95,
        0.8,
        0.6
    );

    glBegin(GL_POLYGON);

        glVertex2f(280,150);
        glVertex2f(520,150);

        glVertex2f(520,320);
        glVertex2f(280,320);

    glEnd();



    // Telhado

    glColor3f(
        0.7,
        0.1,
        0.1
    );

    glBegin(GL_TRIANGLES);

        glVertex2f(250,320);

        glVertex2f(550,320);

        glVertex2f(400,430);

    glEnd();



    // Chaminé

    glColor3f(
        0.5,
        0.1,
        0.1
    );

    glBegin(GL_POLYGON);

        glVertex2f(450,350);

        glVertex2f(480,350);

        glVertex2f(480,420);

        glVertex2f(450,420);

    glEnd();



    // Porta

    glColor3f(
        0.4,
        0.2,
        0
    );

    glBegin(GL_POLYGON);

        glVertex2f(380,150);

        glVertex2f(430,150);

        glVertex2f(430,250);

        glVertex2f(380,250);

    glEnd();



    // Maçaneta

    glColor3f(
        1,
        1,
        0
    );

    circulo(
        420,
        200,
        3
    );



    // Janelas

    if(cena.estado)
    {
        glColor3f(
            1,
            1,
            0.4
        );
    }
    else
    {
        glColor3f(
            0.5,
            0.8,
            1
        );
    }

    glBegin(GL_POLYGON);

        glVertex2f(310,230);

        glVertex2f(360,230);

        glVertex2f(360,280);

        glVertex2f(310,280);

    glEnd();



    glBegin(GL_POLYGON);

        glVertex2f(450,230);

        glVertex2f(500,230);

        glVertex2f(500,280);

        glVertex2f(450,280);

    glEnd();



    // Divisórias

    glColor3f(
        0,
        0,
        0
    );

    glBegin(GL_LINES);

        glVertex2f(335,230);
        glVertex2f(335,280);

        glVertex2f(310,255);
        glVertex2f(360,255);

        glVertex2f(475,230);
        glVertex2f(475,280);

        glVertex2f(450,255);
        glVertex2f(500,255);

    glEnd();
}