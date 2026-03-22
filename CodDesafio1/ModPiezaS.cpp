#include <iostream>

#include "ModPiezaS.h"
#include "ModTablero.h"
#include "ModValidaciones.h"

void rota1PiezaS(){

    unsigned char mascara1 = (0x80 >> (priColPieza % 8));
    unsigned char mascara2 = (0x80 >> (priColPieza % 8));

    if (((Tablero[(ultFilaPieza - 2)][(priColPieza / 8)] & mascara1) == 0x00) &&
        ((Tablero[(ultFilaPieza - 1)][(priColPieza / 8)] & mascara2) == 0x00)) {
        // Ingresa 1s
        Tablero[(ultFilaPieza - 2)][(priColPieza / 8)] |= mascara1;
        Tablero[(ultFilaPieza - 1)][(priColPieza / 8)] |= mascara2;

        // Ingresa 0s
        unsigned char mascara3 = (0x80 >> ((priColPieza + 2) % 8));
        Tablero[(ultFilaPieza - 1)][((priColPieza + 2) / 8)] &= (unsigned char)(~mascara3);

        unsigned char mascara4 = (0x80 >> (priColPieza % 8));
        Tablero[(ultFilaPieza)][(priColPieza / 8)] &= (unsigned char)(~mascara4);
    }
}

void rota2PiezaS(){

    unsigned char mascara1 = (0x80 >> ((priColPieza + 2) % 8));
    unsigned char mascara2 = (0x80 >> (priColPieza % 8));

    if (((Tablero[(ultFilaPieza - 1)][((priColPieza + 2) / 8)] & mascara1) == 0x00) &&
        ((Tablero[(ultFilaPieza)][(priColPieza / 8)] & mascara2) == 0x00)) {
        // Ingresa 1s
        Tablero[(ultFilaPieza - 1)][((priColPieza + 2) / 8)] |= mascara1;
        Tablero[(ultFilaPieza)][(priColPieza / 8)] |= mascara2;

        // Ingresa 0s
        unsigned char mascara3 = (0x80 >> (priColPieza % 8));
        Tablero[(ultFilaPieza - 2)][(priColPieza / 8)] &= (unsigned char)(~mascara3);

        unsigned char mascara4 = (0x80 >> (priColPieza % 8));
        Tablero[(ultFilaPieza - 1)][(priColPieza / 8)] &= (unsigned char)(~mascara4);
    }
}

void bajarPiezaSOrigin(const int &y)
{
    unsigned char mascara1 = (0x80 >> (priColPieza % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 1) % 8));
    unsigned char mascara3 = (0x80 >> ((priColPieza + 2) % 8));

    if (ultFilaPieza == -1) {
        if (((Tablero[(ultFilaPieza + 2)][(priColPieza / 8)] & mascara1) == 0x00) &&
            ((Tablero[(ultFilaPieza + 2)][((priColPieza + 1) / 8)] & mascara2) == 0x00)) {
            // Ingresa 1s
            Tablero[(ultFilaPieza + 1)][(priColPieza / 8)] |= mascara1;
            Tablero[(ultFilaPieza + 1)][((priColPieza + 1) / 8)] |= mascara2;

            ultFilaPieza += 1;
        }
        else {
            gameOver = true;
        }
    }
    else if (ultFilaPieza == 0) {
        if (((Tablero[(ultFilaPieza)][((priColPieza + 2) / 8)] & mascara3) == 0x00) &&
            ((Tablero[(ultFilaPieza + 1)][(priColPieza / 8)] & mascara1) == 0x00) &&
            ((Tablero[(ultFilaPieza + 1)][((priColPieza + 1) / 8)] & mascara2) == 0x00)) {
            // Ingresa 1s
            Tablero[(ultFilaPieza)][((priColPieza + 2) / 8)] |= mascara3;
            Tablero[(ultFilaPieza + 1)][(priColPieza / 8)] |= mascara1;
            Tablero[(ultFilaPieza + 1)][((priColPieza + 1) / 8)] |= mascara2;

            // Ingresa 0s
            Tablero[(ultFilaPieza)][(priColPieza / 8)] &= (unsigned char)(~mascara1);

            ultFilaPieza += 1;
        }
        else {
            fijarPieza = true;
        }
    }
    else if (((Tablero[(ultFilaPieza)][((priColPieza + 2) / 8)] & mascara3) == 0x00) &&
             ((Tablero[(ultFilaPieza + 1)][(priColPieza / 8)] & mascara1) == 0x00) &&
             ((Tablero[(ultFilaPieza + 1)][((priColPieza + 1) / 8)] & mascara2) == 0x00)) {
        // Ingresa 1s
        Tablero[(ultFilaPieza)][((priColPieza + 2) / 8)] |= mascara3;
        Tablero[(ultFilaPieza + 1)][(priColPieza / 8)] |= mascara1;
        Tablero[(ultFilaPieza + 1)][((priColPieza + 1) / 8)] |= mascara2;

        // Ingresa 0s
        Tablero[(ultFilaPieza - 1)][((priColPieza + 1) / 8)] &= (unsigned char)(~mascara2);
        Tablero[(ultFilaPieza - 1)][((priColPieza + 2) / 8)] &= (unsigned char)(~mascara3);
        Tablero[(ultFilaPieza)][(priColPieza / 8)] &= (unsigned char)(~mascara1);

        ultFilaPieza += 1;
        if(ultFilaPieza == (y - 1)){
            fijarPieza = true;
        }
    }
    else {
        fijarPieza = true;
    }
}

void bajarPiezaSRot1(const int &y)
{
    unsigned char mascara1 = (0x80 >> (priColPieza % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 1) % 8));

    if (((Tablero[(ultFilaPieza)][(priColPieza / 8)] & mascara1) == 0x00) &&
        ((Tablero[(ultFilaPieza + 1)][((priColPieza + 1) / 8)] & mascara2) == 0x00)) {
        // Ingresa 1s
        Tablero[(ultFilaPieza)][(priColPieza / 8)] |= mascara1;
        Tablero[(ultFilaPieza + 1)][((priColPieza + 1) / 8)] |= mascara2;

        // Ingresa 0s
        Tablero[(ultFilaPieza - 2)][(priColPieza / 8)] &= (unsigned char)(~mascara1);
        Tablero[(ultFilaPieza - 1)][((priColPieza + 1) / 8)] &= (unsigned char)(~mascara2);

        ultFilaPieza += 1;
        if(ultFilaPieza == (y - 1)){
            fijarPieza = true;
        }
    }
    else {
        fijarPieza = true;
    }
}

void moverDerechaPiezaSOrigin(const int &x)
{
    unsigned char mascara1 = (0x80 >> ((priColPieza + 3) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 2) % 8));

    if ((priColPieza + 3) == x * 8) {
        return;
    }
    else if (((Tablero[(ultFilaPieza - 1)][((priColPieza + 3) / 8)] & mascara1) == 0x00) &&
        ((Tablero[(ultFilaPieza)][((priColPieza + 2) / 8)] & mascara2) == 0x00)) {
        // Ingresa 1s
        Tablero[(ultFilaPieza - 1)][((priColPieza + 3) / 8)] |= mascara1;
        Tablero[(ultFilaPieza)][((priColPieza + 2) / 8)] |= mascara2;

        // Ingresa 0s
        unsigned char mascara3 = (0x80 >> ((priColPieza + 1) % 8));
        Tablero[(ultFilaPieza - 1)][((priColPieza + 1) / 8)] &= (unsigned char)(~mascara3);

        unsigned char mascara4 = (0x80 >> (priColPieza % 8));
        Tablero[(ultFilaPieza)][(priColPieza / 8)] &= (unsigned char)(~mascara4);

        priColPieza += 1;
    }
    else {
        return;
    }
}

void moverDerechaPiezaSRot1(const int &x)
{
    unsigned char mascara1 = (0x80 >> ((priColPieza + 1) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 2) % 8));
    unsigned char mascara3 = (0x80 >> ((priColPieza + 2) % 8));

    if ((priColPieza + 2) == x * 8) {
        return;
    }

    else if (((Tablero[(ultFilaPieza - 2)][((priColPieza + 1) / 8)] & mascara1) == 0x00) &&
        ((Tablero[(ultFilaPieza - 1)][((priColPieza + 2) / 8)] & mascara2) == 0x00) &&
        ((Tablero[(ultFilaPieza)][((priColPieza + 2) / 8)] & mascara3) == 0x00)) {
        // Ingresa 1s
        Tablero[(ultFilaPieza - 2)][((priColPieza + 1) / 8)] |= mascara1;
        Tablero[(ultFilaPieza - 1)][((priColPieza + 2) / 8)] |= mascara2;
        Tablero[(ultFilaPieza)][((priColPieza + 2) / 8)] |= mascara3;

        // Ingresa 0s
        unsigned char mascara4 = (0x80 >> (priColPieza % 8));
        Tablero[(ultFilaPieza - 2)][(priColPieza / 8)] &= (unsigned char)(~mascara4);

        unsigned char mascara5 = (0x80 >> (priColPieza % 8));
        Tablero[(ultFilaPieza - 1)][(priColPieza / 8)] &= (unsigned char)(~mascara5);

        unsigned char mascara6 = (0x80 >> ((priColPieza + 1) % 8));
        Tablero[(ultFilaPieza)][((priColPieza + 1) / 8)] &= (unsigned char)(~mascara6);

        priColPieza += 1;
    }
    else {
        return;
    }
}

void moverIzquierdaPiezaSOrigin()
{
    unsigned char mascara1 = (0x80 >> (priColPieza % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza - 1) % 8));

    if (priColPieza == 0) {
        return;
    }
    else if (((Tablero[(ultFilaPieza - 1)][(priColPieza / 8)] & mascara1) == 0x00) &&
             ((Tablero[(ultFilaPieza)][((priColPieza - 1) / 8)] & mascara2) == 0x00)) {
        // Ingresa 1s
        Tablero[(ultFilaPieza - 1)][(priColPieza / 8)] |= mascara1;
        Tablero[(ultFilaPieza)][((priColPieza - 1) / 8)] |= mascara2;

        // Ingresa 0s
        unsigned char mascara3 = (0x80 >> ((priColPieza + 2) % 8));
        Tablero[(ultFilaPieza - 1)][((priColPieza + 2) / 8)] &= (unsigned char)(~mascara3);

        unsigned char mascara4 = (0x80 >> ((priColPieza + 1) % 8));
        Tablero[(ultFilaPieza)][((priColPieza + 1) / 8)] &= (unsigned char)(~mascara4);

        priColPieza -= 1;
    }
    else {
        fijarPieza = true;
    }
}

void moverIzquierdaPiezaSRot1()
{
    unsigned char mascara1 = (0x80 >> ((priColPieza - 1) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza - 1) % 8));
    unsigned char mascara3 = (0x80 >> (priColPieza % 8));

    if (priColPieza == 0) {
        return;
    }
    else if (((Tablero[(ultFilaPieza - 2)][((priColPieza - 1) / 8)] & mascara1) == 0x00) &&
             ((Tablero[(ultFilaPieza - 1)][((priColPieza - 1) / 8)] & mascara2) == 0x00) &&
             ((Tablero[(ultFilaPieza)][(priColPieza / 8)] & mascara3) == 0x00)) {
        // Ingresa 1s
        Tablero[(ultFilaPieza - 2)][((priColPieza - 1) / 8)] |= mascara1;
        Tablero[(ultFilaPieza - 1)][((priColPieza - 1) / 8)] |= mascara2;
        Tablero[(ultFilaPieza)][(priColPieza / 8)] |= mascara3;

        // Ingresa 0s
        unsigned char mascara4 = (0x80 >> (priColPieza % 8));
        Tablero[(ultFilaPieza - 2)][(priColPieza / 8)] &= (unsigned char)(~mascara4);

        unsigned char mascara5 = (0x80 >> ((priColPieza + 1) % 8));
        Tablero[(ultFilaPieza - 1)][((priColPieza + 1) / 8)] &= (unsigned char)(~mascara5);

        unsigned char mascara6 = (0x80 >> ((priColPieza + 1) % 8));
        Tablero[(ultFilaPieza)][((priColPieza + 1) / 8)] &= (unsigned char)(~mascara6);

        priColPieza -= 1;
    }
    else {
        fijarPieza = true;
    }
}
