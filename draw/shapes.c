#include <GL/glut.h>
#include <math.h>

#include "shapes.h"

#define PI 3.1415926

void circulo(
    float cx,
    float cy,
    float raio
)
{
    glBegin(
        GL_POLYGON
    );

    for(
        int i=0;
        i<360;
        i++
    )
    {
        float ang =
            i *
            PI /
            180.0;

        glVertex2f(
            cx +
            cos(ang) *
            raio,

            cy +
            sin(ang) *
            raio
        );
    }

    glEnd();
}