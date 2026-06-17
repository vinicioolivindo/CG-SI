#include "scene.h"

Scene cena =
{
    0,
    1,

    150,
    250,

    0,
    0,

    0,

    1
};

void resetarCena()
{
    cena.estado = 0;

    cena.andando = 1;

    cena.pessoa1X = 150;
    cena.pessoa2X = 250;

    cena.nuvemX = 0;

    cena.fumacaY = 0;

    cena.anguloPerna = 0;

    cena.brilhoEstrela = 1;
}