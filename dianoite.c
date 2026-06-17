#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926

int estado = 0;      
int andando = 1;

float pessoa1X = 150;
float pessoa2X = 250;

float nuvemX = 0;
float fumacaY = 0;
float anguloPerna = 0;

float brilhoEstrela = 1.0;

void circulo(float cx, float cy, float r)
{
    glBegin(GL_POLYGON);

    for(int i=0;i<360;i++)
    {
        float ang = i * PI / 180.0;

        glVertex2f(
            cx + cos(ang)*r,
            cy + sin(ang)*r
        );
    }

    glEnd();
}

void desenharSol()
{
    glColor3f(1,1,0);
    circulo(700,500,40);

    glBegin(GL_LINES);

    for(int i=0;i<360;i+=30)
    {
        float ang = i * PI / 180;

        glVertex2f(
            700 + cos(ang)*45,
            500 + sin(ang)*45);

        glVertex2f(
            700 + cos(ang)*65,
            500 + sin(ang)*65);
    }

    glEnd();
}

void desenharLua()
{
    glColor3f(1,1,1);
    circulo(700,500,35);

    if(estado == 0)
        glColor3f(0.5,0.8,1.0);
    else
        glColor3f(0.0,0.0,0.2);
    circulo(715,505,30);
}

void desenharEstrelas()
{
    glColor3f(brilhoEstrela, brilhoEstrela, brilhoEstrela);

    circulo(100,520,3);
    circulo(180,470,3);
    circulo(250,540,3);
    circulo(330,500,3);
    circulo(450,530,3);
    circulo(550,480,3);
    circulo(640,540,3);
}

void desenharNuvem(float x, float y)
{
    glColor3f(1,1,1);

    circulo(x,y,25);
    circulo(x+25,y+10,25);
    circulo(x+50,y,25);
}

void desenharFumaca()
{
    glColor3f(0.8,0.8,0.8);

    circulo(475,420+fumacaY,10);
    circulo(485,440+fumacaY,12);
    circulo(470,460+fumacaY,14);
}

void desenharCasa()
{
    // Corpo
    glColor3f(0.95,0.8,0.6);

    glBegin(GL_POLYGON);
        glVertex2f(280,150);
        glVertex2f(520,150);
        glVertex2f(520,320);
        glVertex2f(280,320);
    glEnd();

    // Telhado
    glColor3f(0.7,0.1,0.1);

    glBegin(GL_TRIANGLES);
        glVertex2f(250,320);
        glVertex2f(550,320);
        glVertex2f(400,430);
    glEnd();

    // Chaminé
    glColor3f(0.5,0.1,0.1);

    glBegin(GL_POLYGON);
        glVertex2f(450,350);
        glVertex2f(480,350);
        glVertex2f(480,420);
        glVertex2f(450,420);
    glEnd();

    // Porta
    glColor3f(0.4,0.2,0);

    glBegin(GL_POLYGON);
        glVertex2f(380,150);
        glVertex2f(430,150);
        glVertex2f(430,250);
        glVertex2f(380,250);
    glEnd();

    // Maçaneta
    glColor3f(1,1,0);
    circulo(420,200,3);

    // Janela esquerda
    if(estado == 1)
        glColor3f(1,1,0.4);
    else
        glColor3f(0.5,0.8,1);

    glBegin(GL_POLYGON);
        glVertex2f(310,230);
        glVertex2f(360,230);
        glVertex2f(360,280);
        glVertex2f(310,280);
    glEnd();

    // Janela direita
    glBegin(GL_POLYGON);
        glVertex2f(450,230);
        glVertex2f(500,230);
        glVertex2f(500,280);
        glVertex2f(450,280);
    glEnd();

    // Divisórias das janelas
    glColor3f(0,0,0);

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

void desenharArvore(float x, float y)
{
    glColor3f(0.5,0.2,0);

    glBegin(GL_POLYGON);
        glVertex2f(x-10,y);
        glVertex2f(x+10,y);
        glVertex2f(x+10,y+70);
        glVertex2f(x-10,y+70);
    glEnd();

    glColor3f(0,0.6,0);

    circulo(x,y+110,35);
    circulo(x-25,y+90,30);
    circulo(x+25,y+90,30);

    // maçãs
    glColor3f(1,0,0);
    circulo(x-10,y+100,4);
    circulo(x+15,y+115,4);
    circulo(x+5,y+90,4);
}

void desenharFlor(float x,float y,float r,float g,float b)
{
    glColor3f(0,0.7,0);

    glBegin(GL_LINES);
        glVertex2f(x,y);
        glVertex2f(x,y+15);
    glEnd();

    glColor3f(r,g,b);

    circulo(x,y+20,4);
    circulo(x-4,y+16,4);
    circulo(x+4,y+16,4);
    circulo(x,y+12,4);
}

void desenharJardim()
{
    desenharFlor(100,70,1,0,0);
    desenharFlor(140,90,1,1,0);
    desenharFlor(180,60,1,0,1);

    desenharFlor(620,70,0,0,1);
    desenharFlor(670,90,1,0.5,0);
    desenharFlor(720,60,1,0,0);
}

void desenharPessoa(float x, float y, int tipo)
{
    float movimento = sin(anguloPerna) * 8;

    // Cabeça
    glColor3f(1.0,0.85,0.7);
    circulo(x,y+60,12);

    // Cabelo
    if(tipo == 1)
        glColor3f(0.1,0.1,0.1);
    else
        glColor3f(0.4,0.2,0.0);

    circulo(x,y+66,10);

    // Olhos
    glPointSize(3);
    glColor3f(0,0,0);

    glBegin(GL_POINTS);
        glVertex2f(x-4,y+62);
        glVertex2f(x+4,y+62);
    glEnd();

    // Corpo (roupas diferentes)
    if(tipo == 1)
        glColor3f(0.2,0.2,1.0); // azul
    else
        glColor3f(1.0,0.2,0.5); // rosa

    glBegin(GL_POLYGON);
        glVertex2f(x-12,y+45);
        glVertex2f(x+12,y+45);
        glVertex2f(x+10,y+10);
        glVertex2f(x-10,y+10);
    glEnd();

    // Braços
    glColor3f(1.0,0.85,0.7);

    glBegin(GL_LINES);

        glVertex2f(x-12,y+35);
        glVertex2f(x-25,y+20);

        glVertex2f(x+12,y+35);
        glVertex2f(x+25,y+20);

    glEnd();

    // Pernas animadas
    glColor3f(0,0,0);

    glBegin(GL_LINES);

        glVertex2f(x-5,y+10);
        glVertex2f(x-10 + movimento,y-20);

        glVertex2f(x+5,y+10);
        glVertex2f(x+10 - movimento,y-20);

    glEnd();

    // Sapatos
    glBegin(GL_LINES);

        glVertex2f(x-10 + movimento,y-20);
        glVertex2f(x-16 + movimento,y-20);

        glVertex2f(x+10 - movimento,y-20);
        glVertex2f(x+16 - movimento,y-20);

    glEnd();
}
void display()
{
    if(estado == 0)
        glClearColor(0.5,0.8,1.0,1.0);
    else
        glClearColor(0.0,0.0,0.2,1.0);

    glClear(GL_COLOR_BUFFER_BIT);

    // Céu
    if(estado == 0)
    {
        desenharSol();

        desenharNuvem(100+nuvemX,500);
        desenharNuvem(300+nuvemX,450);
    }
    else
    {
        desenharLua();
        desenharEstrelas();
    }

    // Grama
    glColor3f(0,0.7,0);

    glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(800,0);
        glVertex2f(800,150);
        glVertex2f(0,150);
    glEnd();

    desenharCasa();

    desenharFumaca();

    desenharArvore(150,150);
    desenharArvore(650,150);

    desenharJardim();

    // Pessoas
    desenharPessoa(pessoa1X,130,1);
    desenharPessoa(pessoa2X,130,2);

    glFlush();
}

void animacao()
{
    // Nuvens
    nuvemX += 0.03;

    if(nuvemX > 850)
        nuvemX = -200;

    // Fumaça
    fumacaY += 0.03;

    if(fumacaY > 30)
        fumacaY = 0;

    // Piscar estrelas
    brilhoEstrela = 0.7 + 0.3*sin(glutGet(GLUT_ELAPSED_TIME)/200.0);

    // Movimento das pernas
    if(andando)
        anguloPerna += 0.1;

    // Caminhada suave
    if(andando)
    {
        if(estado == 0)
        {
            if(pessoa1X < 170)
                pessoa1X += 0.03;

            if(pessoa2X < 230)
                pessoa2X += 0.03;
        }
        else
        {
            if(pessoa1X < 560)
                pessoa1X += 0.03;

            if(pessoa2X < 620)
                pessoa2X += 0.03;
        }
    }

    glutPostRedisplay();
}
void teclado(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 't':
        case 'T':

            estado = !estado;

            if(estado == 0)
            {
                pessoa1X = 150;
                pessoa2X = 250;
            }
            else
            {
                pessoa1X = 170;
                pessoa2X = 230;
            }

            break;

        case 'm':
        case 'M':

            andando = !andando;
            break;

        case 'r':
        case 'R':

            estado = 0;
            pessoa1X = 150;
            pessoa2X = 250;
            nuvemX = 0;
            fumacaY = 0;
            break;
    }

    glutPostRedisplay();
}

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,800,0,600);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,600);

    glutCreateWindow("Casa Animada - Dia e Noite");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(teclado);
    glutIdleFunc(animacao);

    glutMainLoop();

    return 0;
}