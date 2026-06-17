#include <GL/glut.h>

#include "keyboard.h"

#include "../state/scene.h"

extern Scene cena;



void teclado(
    unsigned char key,
    int x,
    int y
)
{
    switch(key)
    {
        case 't':

        case 'T':

            cena.estado =
                !cena.estado;

            if(
                cena.estado ==
                0
            )
            {
                cena.pessoa1X =
                    150;

                cena.pessoa2X =
                    250;
            }
            else
            {
                cena.pessoa1X =
                    170;

                cena.pessoa2X =
                    230;
            }

        break;



        case 'm':

        case 'M':

            cena.andando =
                !cena.andando;

        break;



        case 'r':

        case 'R':

            resetarCena();

        break;
    }

    glutPostRedisplay();
}