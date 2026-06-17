#include <GL/glut.h>

#include "smoke.h"
#include "shapes.h"

#include "../state/scene.h"

extern Scene cena;

void desenharFumaca()
{
    glColor3f(
        0.8,
        0.8,
        0.8
    );

    circulo(
        475,
        420 +
        cena.fumacaY,
        10
    );

    circulo(
        485,
        440 +
        cena.fumacaY,
        12
    );

    circulo(
        470,
        460 +
        cena.fumacaY,
        14
    );
}