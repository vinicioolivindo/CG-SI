#ifndef SCENE_H
#define SCENE_H

typedef struct
{
    int estado;
    int andando;

    float pessoa1X;
    float pessoa2X;

    float nuvemX;
    float fumacaY;

    float anguloPerna;

    float brilhoEstrela;

} Scene;

extern Scene cena;

void resetarCena(void);

#endif