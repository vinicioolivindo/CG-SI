#include <GL/glut.h>

#include <math.h>

#include "animation.h"

#include "../state/scene.h"

extern Scene cena;



void animacao()
{
    cena.nuvemX += 0.03f;

    if(
        cena.nuvemX >
        850
    )
    {
        cena.nuvemX =
            -200;
    }



    cena.fumacaY +=
        0.03f;

    if(
        cena.fumacaY >
        30
    )
    {
        cena.fumacaY =
            0;
    }



    cena.brilhoEstrela =
        0.7f +
        0.3f *
        sin(
            glutGet(
                GLUT_ELAPSED_TIME
            ) /
            200.0f
        );



    if(
        cena.andando
    )
    {
        cena.anguloPerna +=
            0.1f;
    }



    if(
        cena.andando
    )
    {
        if(
            cena.estado ==
            0
        )
        {
            if(
                cena.pessoa1X <
                170
            )
            {
                cena.pessoa1X +=
                    0.03f;
            }

            if(
                cena.pessoa2X <
                230
            )
            {
                cena.pessoa2X +=
                    0.03f;
            }
        }
        else
        {
            if(
                cena.pessoa1X <
                560
            )
            {
                cena.pessoa1X +=
                    0.03f;
            }

            if(
                cena.pessoa2X <
                620
            )
            {
                cena.pessoa2X +=
                    0.03f;
            }
        }
    }

    glutPostRedisplay();
}