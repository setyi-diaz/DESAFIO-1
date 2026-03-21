#include <iostream>

#include "ModPiezaJ.h"
#include "ModTablero.h"
#include "ModValidaciones.h"

void rota1PiezaJ(){
    unsigned char mascara1 = (0x80 >> (priColPieza % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 1) % 8));
    unsigned char mascara3 = (0x80 >> (priColPieza % 8));

    if(((Tablero[(ultFilaPieza - 1)][(priColPieza / 8)] & mascara1) == 0x00) &&
       ((Tablero[(ultFilaPieza - 1)][((priColPieza + 1) / 8)] & mascara2) == 0x00) &&
       ((Tablero[(ultFilaPieza)][(priColPieza / 8)] & mascara3) == 0x00)){
        // Ingresa 1s
        Tablero[(ultFilaPieza - 1)][(priColPieza / 8)] |= mascara1;
        Tablero[(ultFilaPieza - 1)][((priColPieza + 1) / 8)] |= mascara2;
        Tablero[(ultFilaPieza)][(priColPieza / 8)] |= mascara3;

        // Ingresa 0s
        unsigned char mascara4 = (0x80 >> ((priColPieza + 2) % 8));
        unsigned char mascara5 = (0x80 >> ((priColPieza + 1) % 8));
        unsigned char mascara6 = (0x80 >> ((priColPieza + 2) % 8));
        Tablero[(ultFilaPieza - 2)][((priColPieza + 2) / 8)] &= (unsigned char)(~mascara4);
        Tablero[(ultFilaPieza)][((priColPieza + 1) / 8)] &= (unsigned char)(~mascara5);
        Tablero[(ultFilaPieza)][((priColPieza + 2) / 8)] &= (unsigned char)(~mascara6);
    }
}

void rota2PiezaJ(){
    unsigned char mascara1 = (0x80 >> (priColPieza % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 1) % 8));

    if(((Tablero[(ultFilaPieza - 2)][(priColPieza / 8)] & mascara1) == 0x00) &&
       ((Tablero[(ultFilaPieza - 2)][((priColPieza + 1) / 8)] & mascara2) == 0x00)){
        // Ingresa 1s
        Tablero[(ultFilaPieza - 2)][(priColPieza / 8)] |= mascara1;
        Tablero[(ultFilaPieza - 2)][((priColPieza + 1) / 8)] |= mascara2;

        // Ingresa 0s
        unsigned char mascara3 = (0x80 >> ((priColPieza + 1) % 8));
        unsigned char mascara4 = (0x80 >> ((priColPieza + 2) % 8));
        Tablero[(ultFilaPieza - 1)][((priColPieza + 1) / 8)] &= (unsigned char)(~mascara3);
        Tablero[(ultFilaPieza - 1)][((priColPieza + 2) / 8)] &= (unsigned char)(~mascara4);
    }
}

void rota3PiezaJ(){
    unsigned char mascara1 = (0x80 >> ((priColPieza + 2) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 1) % 8));
    unsigned char mascara3 = (0x80 >> ((priColPieza + 2) % 8));

    if(((Tablero[(ultFilaPieza - 1)][((priColPieza + 2) / 8)] & mascara1) == 0x00) &&
       ((Tablero[(ultFilaPieza)][((priColPieza + 1) / 8)] & mascara2) == 0x00) &&
       ((Tablero[(ultFilaPieza)][((priColPieza + 2) / 8)] & mascara3) == 0x00)){
        // Ingresa 1s
        Tablero[(ultFilaPieza - 1)][((priColPieza + 2) / 8)] |= mascara1;
        Tablero[(ultFilaPieza)][((priColPieza + 1) / 8)] |= mascara2;
        Tablero[(ultFilaPieza)][((priColPieza + 2) / 8)] |= mascara3;

        // Ingresa 0s
        unsigned char mascara4 = (0x80 >> (priColPieza % 8));
        unsigned char mascara5 = (0x80 >> ((priColPieza + 1) % 8));
        unsigned char mascara6 = (0x80 >> (priColPieza % 8));
        Tablero[(ultFilaPieza - 2)][(priColPieza / 8)] &= (unsigned char)(~mascara4);
        Tablero[(ultFilaPieza - 2)][((priColPieza + 1) / 8)] &= (unsigned char)(~mascara5);
        Tablero[(ultFilaPieza - 1)][(priColPieza / 8)] &= (unsigned char)(~mascara6);
    }
}

void rota4PiezaJ(){
    unsigned char mascara1 = (0x80 >> ((priColPieza + 2) % 8));

    if((Tablero[(ultFilaPieza - 2)][((priColPieza + 2) / 8)] & mascara1) == 0x00){
        // Ingresa 1s
        Tablero[(ultFilaPieza - 2)][((priColPieza + 2) / 8)] |= mascara1;

        // Ingresa 0s
        unsigned char mascara2 = (0x80 >> (priColPieza % 8));
        Tablero[(ultFilaPieza)][(priColPieza / 8)] &= (unsigned char)(~mascara2);
    }
}

void bajarPiezaJOrigin(){
    unsigned char mascara1 = (0x80 >> ((priColPieza + 1) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 2) % 8));

    if(ultFilaPieza == -1){
        if(((Tablero[0][((priColPieza + 1) / 8)] & mascara1) == 0x00) &&
           ((Tablero[0][((priColPieza + 2) / 8)] & mascara2) == 0x00)){
            Tablero[0][((priColPieza + 1) / 8)] |= mascara1;
            Tablero[0][((priColPieza + 2) / 8)] |= mascara2;
            ultFilaPieza += 1;
        }
        else fijarPieza = true;
    }
    else if(ultFilaPieza == 0){
        if(((Tablero[1][((priColPieza + 1) / 8)] & mascara1) == 0x00) &&
           ((Tablero[1][((priColPieza + 2) / 8)] & mascara2) == 0x00)){
            Tablero[1][((priColPieza + 1) / 8)] |= mascara1;
            Tablero[1][((priColPieza + 2) / 8)] |= mascara2;

            Tablero[0][((priColPieza + 1) / 8)] &= (unsigned char)(~mascara1);

            ultFilaPieza += 1;
        }
        else fijarPieza = true;
    }
    else if(ultFilaPieza == 1){
        if(((Tablero[2][((priColPieza + 1) / 8)] & mascara1) == 0x00) &&
           ((Tablero[2][((priColPieza + 2) / 8)] & mascara2) == 0x00)){
            Tablero[2][((priColPieza + 1) / 8)] |= mascara1;
            Tablero[2][((priColPieza + 2) / 8)] |= mascara2;

            Tablero[1][((priColPieza + 1) / 8)] &= (unsigned char)(~mascara1);

            ultFilaPieza += 1;
        }
        else fijarPieza = true;
    }
    else if(((Tablero[(ultFilaPieza + 1)][((priColPieza + 1) / 8)] & mascara1) == 0x00) &&
            ((Tablero[(ultFilaPieza + 1)][((priColPieza + 2) / 8)] & mascara2) == 0x00)){
        // Ingresa 1s
        Tablero[(ultFilaPieza + 1)][((priColPieza + 1) / 8)] |= mascara1;
        Tablero[(ultFilaPieza + 1)][((priColPieza + 2) / 8)] |= mascara2;

        // Ingresa 0s
        Tablero[(ultFilaPieza - 2)][((priColPieza + 2) / 8)] &= (unsigned char)(~mascara2);
        Tablero[(ultFilaPieza)][((priColPieza + 1) / 8)] &= (unsigned char)(~mascara1);

        ultFilaPieza += 1;
    }
    else fijarPieza = true;
}

void bajarPiezaJRot1(){
    unsigned char mascara1 = (0x80 >> ((priColPieza + 1) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 2) % 8));
    unsigned char mascara3 = (0x80 >> (priColPieza % 8));

    if(((Tablero[(ultFilaPieza)][((priColPieza + 1) / 8)] & mascara1) == 0x00) &&
       ((Tablero[(ultFilaPieza)][((priColPieza + 2) / 8)] & mascara2) == 0x00) &&
       ((Tablero[(ultFilaPieza + 1)][(priColPieza / 8)] & mascara3) == 0x00)){
        // Ingresa 1s
        Tablero[(ultFilaPieza)][((priColPieza + 1) / 8)] |= mascara1;
        Tablero[(ultFilaPieza)][((priColPieza + 2) / 8)] |= mascara2;
        Tablero[(ultFilaPieza + 1)][(priColPieza / 8)] |= mascara3;

        // Ingresa 0s
        unsigned char mascara4 = (0x80 >> (priColPieza % 8));
        unsigned char mascara5 = (0x80 >> ((priColPieza + 1) % 8));
        unsigned char mascara6 = (0x80 >> ((priColPieza + 2) % 8));
        Tablero[(ultFilaPieza - 1)][(priColPieza / 8)] &= (unsigned char)(~mascara4);
        Tablero[(ultFilaPieza - 1)][((priColPieza + 1) / 8)] &= (unsigned char)(~mascara5);
        Tablero[(ultFilaPieza - 1)][((priColPieza + 2) / 8)] &= (unsigned char)(~mascara6);

        ultFilaPieza += 1;
    }
    else fijarPieza = true;
}

void bajarPiezaJRot2(){
    unsigned char mascara1 = (0x80 >> ((priColPieza + 1) % 8));
    unsigned char mascara2 = (0x80 >> (priColPieza % 8));

    if(((Tablero[(ultFilaPieza - 1)][((priColPieza + 1) / 8)] & mascara1) == 0x00) &&
       ((Tablero[(ultFilaPieza + 1)][(priColPieza / 8)] & mascara2) == 0x00)){
        // Ingresa 1s
        Tablero[(ultFilaPieza - 1)][((priColPieza + 1) / 8)] |= mascara1;
        Tablero[(ultFilaPieza + 1)][(priColPieza / 8)] |= mascara2;

        // Ingresa 0s
        unsigned char mascara3 = (0x80 >> (priColPieza % 8));
        unsigned char mascara4 = (0x80 >> ((priColPieza + 1) % 8));
        Tablero[(ultFilaPieza - 2)][(priColPieza / 8)] &= (unsigned char)(~mascara3);
        Tablero[(ultFilaPieza - 2)][((priColPieza + 1) / 8)] &= (unsigned char)(~mascara4);

        ultFilaPieza += 1;
    }
    else fijarPieza = true;
}

void bajarPiezaJRot3(){
    unsigned char mascara1 = (0x80 >> (priColPieza % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 1) % 8));
    unsigned char mascara3 = (0x80 >> ((priColPieza + 2) % 8));

    if(((Tablero[(ultFilaPieza + 1)][(priColPieza / 8)] & mascara1) == 0x00) &&
       ((Tablero[(ultFilaPieza + 1)][((priColPieza + 1) / 8)] & mascara2) == 0x00) &&
       ((Tablero[(ultFilaPieza + 1)][((priColPieza + 2) / 8)] & mascara3) == 0x00)){
        // Ingresa 1s
        Tablero[(ultFilaPieza + 1)][(priColPieza / 8)] |= mascara1;
        Tablero[(ultFilaPieza + 1)][((priColPieza + 1) / 8)] |= mascara2;
        Tablero[(ultFilaPieza + 1)][((priColPieza + 2) / 8)] |= mascara3;

        // Ingresa 0s
        Tablero[(ultFilaPieza - 1)][((priColPieza + 2) / 8)] &= (unsigned char)(~mascara3);
        Tablero[(ultFilaPieza)][(priColPieza / 8)] &= (unsigned char)(~mascara1);
        Tablero[(ultFilaPieza)][((priColPieza + 1) / 8)] &= (unsigned char)(~mascara2);

        ultFilaPieza += 1;
    }
    else fijarPieza = true;
}

void moverDerechaPiezaJOrigin(const int &x){
    unsigned char mascara1 = (0x80 >> ((priColPieza + 3) % 8));

    if((priColPieza + 3) == x * 8){
        return;
    }
    else if(ultFilaPieza == 1){
        unsigned char mascara2 = (0x80 >> ((priColPieza + 2) % 8));

        if(((Tablero[0][((priColPieza + 3) / 8)] & mascara1) == 0x00) &&
           ((Tablero[1][((priColPieza + 3) / 8)] & mascara1) == 0x00)){
            // Ingresa 1s
            Tablero[0][((priColPieza + 3) / 8)] |= mascara1;
            Tablero[1][((priColPieza + 3) / 8)] |= mascara1;

            // Ingresa 0s
            Tablero[0][((priColPieza + 2) / 8)] &= (unsigned char)(~mascara2);
            Tablero[1][((priColPieza + 1) / 8)] &= (unsigned char)(~(0x80 >> ((priColPieza + 1) % 8)));

            priColPieza += 1;
        }
        else fijarPieza = true;
    }
    else{
        unsigned char mascara2 = (0x80 >> ((priColPieza + 2) % 8));

        if(((Tablero[(ultFilaPieza - 2)][((priColPieza + 3) / 8)] & mascara1) == 0x00) &&
           ((Tablero[(ultFilaPieza - 1)][((priColPieza + 3) / 8)] & mascara1) == 0x00) &&
           ((Tablero[(ultFilaPieza)][((priColPieza + 3) / 8)] & mascara1) == 0x00)){
            // Ingresa 1s
            Tablero[(ultFilaPieza - 2)][((priColPieza + 3) / 8)] |= mascara1;
            Tablero[(ultFilaPieza - 1)][((priColPieza + 3) / 8)] |= mascara1;
            Tablero[(ultFilaPieza)][((priColPieza + 3) / 8)] |= mascara1;

            // Ingresa 0s
            Tablero[(ultFilaPieza - 2)][((priColPieza + 2) / 8)] &= (unsigned char)(~mascara2);
            Tablero[(ultFilaPieza - 1)][((priColPieza + 2) / 8)] &= (unsigned char)(~mascara2);
            Tablero[(ultFilaPieza)][((priColPieza + 1) / 8)] &= (unsigned char)(~(0x80 >> ((priColPieza + 1) % 8)));

            priColPieza += 1;
        }
        else fijarPieza = true;
    }
}

void moverDerechaPiezaJRot1(const int &x){
    unsigned char mascara1 = (0x80 >> ((priColPieza + 3) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 1) % 8));

    if((priColPieza + 3) == x * 8){
        return;
    }
    else if(((Tablero[(ultFilaPieza - 1)][((priColPieza + 3) / 8)] & mascara1) == 0x00) &&
            ((Tablero[(ultFilaPieza)][((priColPieza + 1) / 8)] & mascara2) == 0x00)){
        // Ingresa 1s
        Tablero[(ultFilaPieza - 1)][((priColPieza + 3) / 8)] |= mascara1;
        Tablero[(ultFilaPieza)][((priColPieza + 1) / 8)] |= mascara2;

        // Ingresa 0s
        Tablero[(ultFilaPieza - 1)][(priColPieza / 8)] &= (unsigned char)(~(0x80 >> (priColPieza % 8)));
        Tablero[(ultFilaPieza)][(priColPieza / 8)] &= (unsigned char)(~(0x80 >> (priColPieza % 8)));

        priColPieza += 1;
    }
    else fijarPieza = true;
}

void moverDerechaPiezaJRot2(const int &x){
    unsigned char mascara1 = (0x80 >> ((priColPieza + 2) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 1) % 8));

    if((priColPieza + 2) == x * 8){
        return;
    }
    else if(((Tablero[(ultFilaPieza - 2)][((priColPieza + 2) / 8)] & mascara1) == 0x00) &&
            ((Tablero[(ultFilaPieza - 1)][((priColPieza + 1) / 8)] & mascara2) == 0x00) &&
            ((Tablero[(ultFilaPieza)][((priColPieza + 1) / 8)] & mascara2) == 0x00)){
        // Ingresa 1s
        Tablero[(ultFilaPieza - 2)][((priColPieza + 2) / 8)] |= mascara1;
        Tablero[(ultFilaPieza - 1)][((priColPieza + 1) / 8)] |= mascara2;
        Tablero[(ultFilaPieza)][((priColPieza + 1) / 8)] |= mascara2;

        // Ingresa 0s
        Tablero[(ultFilaPieza - 2)][(priColPieza / 8)] &= (unsigned char)(~(0x80 >> (priColPieza % 8)));
        Tablero[(ultFilaPieza - 1)][(priColPieza / 8)] &= (unsigned char)(~(0x80 >> (priColPieza % 8)));
        Tablero[(ultFilaPieza)][(priColPieza / 8)] &= (unsigned char)(~(0x80 >> (priColPieza % 8)));

        priColPieza += 1;
    }
    else fijarPieza = true;
}

void moverDerechaPiezaJRot3(const int &x){
    unsigned char mascara1 = (0x80 >> ((priColPieza + 3) % 8));

    if((priColPieza + 3) == x * 8){
        return;
    }
    else if(((Tablero[(ultFilaPieza - 1)][((priColPieza + 3) / 8)] & mascara1) == 0x00) &&
            ((Tablero[(ultFilaPieza)][((priColPieza + 3) / 8)] & mascara1) == 0x00)){
        // Ingresa 1s
        Tablero[(ultFilaPieza - 1)][((priColPieza + 3) / 8)] |= mascara1;
        Tablero[(ultFilaPieza)][((priColPieza + 3) / 8)] |= mascara1;

        // Ingresa 0s
        Tablero[(ultFilaPieza - 1)][((priColPieza + 2) / 8)] &= (unsigned char)(~(0x80 >> ((priColPieza + 2) % 8)));
        Tablero[(ultFilaPieza)][(priColPieza / 8)] &= (unsigned char)(~(0x80 >> (priColPieza % 8)));

        priColPieza += 1;
    }
    else fijarPieza = true;
}

void moverIzquierdaPiezaJOrigin(){
    unsigned char mascara1 = (0x80 >> ((priColPieza + 1) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 1) % 8));
    unsigned char mascara3 = (0x80 >> (priColPieza % 8));

    if(priColPieza == -1){
        return;
    }
    else if(ultFilaPieza == 1){
        if(((Tablero[0][((priColPieza + 1) / 8)] & mascara1) == 0x00) &&
           ((Tablero[1][(priColPieza / 8)] & mascara3) == 0x00)){
            // Ingresa 1s
            Tablero[0][((priColPieza + 1) / 8)] |= mascara1;
            Tablero[1][(priColPieza / 8)] |= mascara3;

            // Ingresa 0s
            Tablero[0][((priColPieza + 2) / 8)] &= (unsigned char)(~(0x80 >> ((priColPieza + 2) % 8)));
            Tablero[1][((priColPieza + 2) / 8)] &= (unsigned char)(~(0x80 >> ((priColPieza + 2) % 8)));

            priColPieza -= 1;
        }
        else fijarPieza = true;
    }
    else if(((Tablero[(ultFilaPieza - 2)][((priColPieza + 1) / 8)] & mascara1) == 0x00) &&
            ((Tablero[(ultFilaPieza - 1)][((priColPieza + 1) / 8)] & mascara2) == 0x00) &&
            ((Tablero[(ultFilaPieza)][(priColPieza / 8)] & mascara3) == 0x00)){
        // Ingresa 1s
        Tablero[(ultFilaPieza - 2)][((priColPieza + 1) / 8)] |= mascara1;
        Tablero[(ultFilaPieza - 1)][((priColPieza + 1) / 8)] |= mascara2;
        Tablero[(ultFilaPieza)][(priColPieza / 8)] |= mascara3;

        // Ingresa 0s
        Tablero[(ultFilaPieza - 2)][((priColPieza + 2) / 8)] &= (unsigned char)(~(0x80 >> ((priColPieza + 2) % 8)));
        Tablero[(ultFilaPieza - 1)][((priColPieza + 2) / 8)] &= (unsigned char)(~(0x80 >> ((priColPieza + 2) % 8)));
        Tablero[(ultFilaPieza)][((priColPieza + 2) / 8)] &= (unsigned char)(~(0x80 >> ((priColPieza + 2) % 8)));

        priColPieza -= 1;
    }
    else fijarPieza = true;
}

void moverIzquierdaPiezaJRot1(){
    unsigned char mascara1 = (0x80 >> ((priColPieza - 1) % 8));

    if(priColPieza == 0){
        return;
    }
    else if(((Tablero[(ultFilaPieza - 1)][((priColPieza - 1) / 8)] & mascara1) == 0x00) &&
            ((Tablero[(ultFilaPieza)][((priColPieza - 1) / 8)] & mascara1) == 0x00)){
        // Ingresa 1s
        Tablero[(ultFilaPieza - 1)][((priColPieza - 1) / 8)] |= mascara1;
        Tablero[(ultFilaPieza)][((priColPieza - 1) / 8)] |= mascara1;

        // Ingresa 0s
        Tablero[(ultFilaPieza - 1)][((priColPieza + 2) / 8)] &= (unsigned char)(~(0x80 >> ((priColPieza + 2) % 8)));
        Tablero[(ultFilaPieza)][(priColPieza / 8)] &= (unsigned char)(~(0x80 >> (priColPieza % 8)));

        priColPieza -= 1;
    }
    else fijarPieza = true;
}

void moverIzquierdaPiezaJRot2(){
    unsigned char mascara1 = (0x80 >> ((priColPieza - 1) % 8));

    if(priColPieza == 0){
        return;
    }
    else if(((Tablero[(ultFilaPieza - 2)][((priColPieza - 1) / 8)] & mascara1) == 0x00) &&
            ((Tablero[(ultFilaPieza - 1)][((priColPieza - 1) / 8)] & mascara1) == 0x00) &&
            ((Tablero[(ultFilaPieza)][((priColPieza - 1) / 8)] & mascara1) == 0x00)){
        // Ingresa 1s
        Tablero[(ultFilaPieza - 2)][((priColPieza - 1) / 8)] |= mascara1;
        Tablero[(ultFilaPieza - 1)][((priColPieza - 1) / 8)] |= mascara1;
        Tablero[(ultFilaPieza)][((priColPieza - 1) / 8)] |= mascara1;

        // Ingresa 0s
        Tablero[(ultFilaPieza - 2)][((priColPieza + 1) / 8)] &= (unsigned char)(~(0x80 >> ((priColPieza + 1) % 8)));
        Tablero[(ultFilaPieza - 1)][(priColPieza / 8)] &= (unsigned char)(~(0x80 >> (priColPieza % 8)));
        Tablero[(ultFilaPieza)][(priColPieza / 8)] &= (unsigned char)(~(0x80 >> (priColPieza % 8)));

        priColPieza -= 1;
    }
    else fijarPieza = true;
}

void moverIzquierdaPiezaJRot3(){
    unsigned char mascara1 = (0x80 >> ((priColPieza + 1) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza - 1) % 8));

    if(priColPieza == 0){
        return;
    }
    else if(((Tablero[(ultFilaPieza - 1)][((priColPieza + 1) / 8)] & mascara1) == 0x00) &&
            ((Tablero[(ultFilaPieza)][((priColPieza - 1) / 8)] & mascara2) == 0x00)){
        // Ingresa 1s
        Tablero[(ultFilaPieza - 1)][((priColPieza + 1) / 8)] |= mascara1;
        Tablero[(ultFilaPieza)][((priColPieza - 1) / 8)] |= mascara2;

        // Ingresa 0s
        Tablero[(ultFilaPieza - 1)][((priColPieza + 2) / 8)] &= (unsigned char)(~(0x80 >> ((priColPieza + 2) % 8)));
        Tablero[(ultFilaPieza)][((priColPieza + 2) / 8)] &= (unsigned char)(~(0x80 >> ((priColPieza + 2) % 8)));

        priColPieza -= 1;
    }
    else fijarPieza = true;
}
