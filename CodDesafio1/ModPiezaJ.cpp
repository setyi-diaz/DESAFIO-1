#include <iostream>

#include "ModPiezaJ.h"
#include "ModTablero.h"
#include "ModValidaciones.h"

int priColPiezaJ = (ancho / 2) - 1;
int ultFilaPiezaJ = alto - 1;



void rota1PiezaJ(const int &x){
    unsigned char mascara1 = (0x80 >> ((priColPiezaJ) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPiezaJ) % 8));

    if(((Tablero[((ultFilaPiezaJ - 1) * x) + ((priColPiezaJ) / 8)] & mascara1) == mascara1) &&
       ((Tablero[(ultFilaPiezaJ * x) + ((priColPiezaJ) / 8)] & mascara2) == mascara2)){
        // Ingresa 1s
        Tablero[((ultFilaPiezaJ - 1) * x) + ((priColPiezaJ) / 8)] |= mascara1;
        Tablero[(ultFilaPiezaJ * x) + ((priColPiezaJ) / 8)] |= mascara2;

        // Ingresa 0s
        unsigned char mascara3 = (0x80 >> ((priColPiezaJ + 2) % 8));
        unsigned char mascara4 = (0x80 >> ((priColPiezaJ + 2) % 8));
        Tablero[((ultFilaPiezaJ - 2) * x) + ((priColPiezaJ + 2) / 8)] &= ~mascara3;
        Tablero[((ultFilaPiezaJ - 1) * x) + ((priColPiezaJ + 2) / 8)] &= ~mascara4;
    }
}

void rota2PiezaJ(const int &x){
    unsigned char mascara1 = (0x80 >> ((priColPiezaJ) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPiezaJ + 1) % 8));

    if(((Tablero[((ultFilaPiezaJ - 2) * x) + ((priColPiezaJ) / 8)] & mascara1) == mascara1) &&
       ((Tablero[((ultFilaPiezaJ - 2) * x) + ((priColPiezaJ + 1) / 8)] & mascara2) == mascara2)){
        // Ingresa 1s
        Tablero[((ultFilaPiezaJ - 2) * x) + ((priColPiezaJ) / 8)] |= mascara1;
        Tablero[((ultFilaPiezaJ - 2) * x) + ((priColPiezaJ + 1) / 8)] |= mascara2;

        // Ingresa 0s
        unsigned char mascara3 = (0x80 >> ((priColPiezaJ + 1) % 8));
        unsigned char mascara4 = (0x80 >> ((priColPiezaJ + 2) % 8));
        Tablero[(ultFilaPiezaJ * x) + ((priColPiezaJ + 1) / 8)] &= ~mascara3;
        Tablero[(ultFilaPiezaJ * x) + ((priColPiezaJ + 2) / 8)] &= ~mascara4;
    }
}

void rota3PiezaJ(const int &x){
    unsigned char mascara1 = (0x80 >> ((priColPiezaJ + 2) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPiezaJ + 2) % 8));

    if(((Tablero[((ultFilaPiezaJ - 2) * x) + ((priColPiezaJ + 2) / 8)] & mascara1) == mascara1) &&
       ((Tablero[((ultFilaPiezaJ - 1) * x) + ((priColPiezaJ + 2) / 8)] & mascara2) == mascara2)){
        // Ingresa 1s
        Tablero[((ultFilaPiezaJ - 2) * x) + ((priColPiezaJ + 2) / 8)] |= mascara1;
        Tablero[((ultFilaPiezaJ - 1) * x) + ((priColPiezaJ + 2) / 8)] |= mascara2;

        // Ingresa 0s
        unsigned char mascara3 = (0x80 >> ((priColPiezaJ) % 8));
        unsigned char mascara4 = (0x80 >> ((priColPiezaJ) % 8));
        Tablero[((ultFilaPiezaJ - 1) * x) + ((priColPiezaJ) / 8)] &= ~mascara3;
        Tablero[(ultFilaPiezaJ * x) + ((priColPiezaJ) / 8)] &= ~mascara4;
    }
}

void rota4PiezaJ(const int &x){
    unsigned char mascara1 = (0x80 >> ((priColPiezaJ + 1) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPiezaJ + 2) % 8));

    if(((Tablero[(ultFilaPiezaJ * x) + ((priColPiezaJ + 1) / 8)] & mascara1) == mascara1) &&
       ((Tablero[(ultFilaPiezaJ * x) + ((priColPiezaJ + 2) / 8)] & mascara2) == mascara2)){
        // Ingresa 1s
        Tablero[(ultFilaPiezaJ * x) + ((priColPiezaJ + 1) / 8)] |= mascara1;
        Tablero[(ultFilaPiezaJ * x) + ((priColPiezaJ + 2) / 8)] |= mascara2;

        // Ingresa 0s
        unsigned char mascara3 = (0x80 >> ((priColPiezaJ) % 8));
        unsigned char mascara4 = (0x80 >> ((priColPiezaJ + 1) % 8));
        Tablero[((ultFilaPiezaJ - 2) * x) + ((priColPiezaJ) / 8)] &= ~mascara3;
        Tablero[((ultFilaPiezaJ - 2) * x) + ((priColPiezaJ + 1) / 8)] &= ~mascara4;
    }
}

void bajarPiezaJOrigin(const int &x){
    unsigned char mascara1 = (0x80 >> ((priColPiezaJ + 1) % 8));

    if((Tablero[((ultFilaPiezaJ + 1) * x) + ((priColPiezaJ + 1) / 8)] & mascara1) == mascara1){
        Tablero[((ultFilaPiezaJ + 1) * x) + ((priColPiezaJ + 1) / 8)] |= mascara1;

        unsigned char mascara2 = (0x80 >> ((priColPiezaJ + 2) % 8));
        Tablero[((ultFilaPiezaJ - 1) * x) + ((priColPiezaJ + 2) / 8)] &= ~mascara2;

        ultFilaPiezaJ += 1;
    }
    else fijarPieza = true;
}

void bajarPiezaJRot1(const int &x){
    unsigned char mascara1 = (0x80 >> ((priColPiezaJ) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPiezaJ + 1) % 8));
    unsigned char mascara3 = (0x80 >> ((priColPiezaJ + 2) % 8));

    if(((Tablero[((ultFilaPiezaJ + 1) * x) + ((priColPiezaJ) / 8)] & mascara1) == mascara1) &&
       ((Tablero[((ultFilaPiezaJ + 1) * x) + ((priColPiezaJ + 1) / 8)] & mascara2) == mascara2) &&
       ((Tablero[((ultFilaPiezaJ + 1) * x) + ((priColPiezaJ + 2) / 8)] & mascara3) == mascara3)){
        Tablero[((ultFilaPiezaJ + 1) * x) + ((priColPiezaJ) / 8)] |= mascara1;
        Tablero[((ultFilaPiezaJ + 1) * x) + ((priColPiezaJ + 1) / 8)] |= mascara2;
        Tablero[((ultFilaPiezaJ + 1) * x) + ((priColPiezaJ + 2) / 8)] |= mascara3;

        unsigned char mascara4 = (0x80 >> ((priColPiezaJ + 2) % 8));
        Tablero[((ultFilaPiezaJ - 2) * x) + ((priColPiezaJ + 2) / 8)] &= ~mascara4;

        ultFilaPiezaJ += 1;
    }
    else fijarPieza = true;
}

void bajarPiezaJRot2(const int &x){
    unsigned char mascara1 = (0x80 >> ((priColPiezaJ + 2) % 8));

    if((Tablero[((ultFilaPiezaJ + 1) * x) + ((priColPiezaJ + 2) / 8)] & mascara1) == mascara1){
        Tablero[((ultFilaPiezaJ + 1) * x) + ((priColPiezaJ + 2) / 8)] |= mascara1;

        unsigned char mascara2 = (0x80 >> ((priColPiezaJ) % 8));
        Tablero[((ultFilaPiezaJ - 1) * x) + ((priColPiezaJ) / 8)] &= ~mascara2;

        ultFilaPiezaJ += 1;
    }
    else fijarPieza = true;
}

void bajarPiezaJRot3(const int &x){
    unsigned char mascara1 = (0x80 >> ((priColPiezaJ) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPiezaJ + 1) % 8));

    if(((Tablero[((ultFilaPiezaJ + 1) * x) + ((priColPiezaJ) / 8)] & mascara1) == mascara1) &&
       ((Tablero[((ultFilaPiezaJ + 1) * x) + ((priColPiezaJ + 1) / 8)] & mascara2) == mascara2)){
        Tablero[((ultFilaPiezaJ + 1) * x) + ((priColPiezaJ) / 8)] |= mascara1;
        Tablero[((ultFilaPiezaJ + 1) * x) + ((priColPiezaJ + 1) / 8)] |= mascara2;

        unsigned char mascara3 = (0x80 >> ((priColPiezaJ) % 8));
        unsigned char mascara4 = (0x80 >> ((priColPiezaJ + 1) % 8));
        Tablero[((ultFilaPiezaJ - 2) * x) + ((priColPiezaJ) / 8)] &= ~mascara3;
        Tablero[((ultFilaPiezaJ - 2) * x) + ((priColPiezaJ + 1) / 8)] &= ~mascara4;

        ultFilaPiezaJ += 1;
    }
    else fijarPieza = true;
}

void moverDerechaPiezaJOrigin(const int &x){
    unsigned char mascara1 = (0x80 >> ((priColPiezaJ + 3) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPiezaJ + 2) % 8));

    if(((Tablero[((ultFilaPiezaJ - 1) * x) + ((priColPiezaJ + 3) / 8)] & mascara1) == mascara1) &&
       ((Tablero[(ultFilaPiezaJ * x) + ((priColPiezaJ + 2) / 8)] & mascara2) == mascara2)){
        Tablero[((ultFilaPiezaJ - 1) * x) + ((priColPiezaJ + 3) / 8)] |= mascara1;
        Tablero[(ultFilaPiezaJ * x) + ((priColPiezaJ + 2) / 8)] |= mascara2;

        unsigned char mascara3 = (0x80 >> ((priColPiezaJ + 1) % 8));
        unsigned char mascara4 = (0x80 >> ((priColPiezaJ + 1) % 8));
        Tablero[((ultFilaPiezaJ - 1) * x) + ((priColPiezaJ + 1) / 8)] &= ~mascara3;
        Tablero[(ultFilaPiezaJ * x) + ((priColPiezaJ + 1) / 8)] &= ~mascara4;

        priColPiezaJ += 1;
    }
}

void moverDerechaPiezaJRot1(const int &x){
    unsigned char mascara1 = (0x80 >> ((priColPiezaJ + 2) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPiezaJ + 1) % 8));
    unsigned char mascara3 = (0x80 >> ((priColPiezaJ + 1) % 8));

    if(((Tablero[((ultFilaPiezaJ - 2) * x) + ((priColPiezaJ + 2) / 8)] & mascara1) == mascara1) &&
       ((Tablero[((ultFilaPiezaJ - 1) * x) + ((priColPiezaJ + 1) / 8)] & mascara2) == mascara2) &&
       ((Tablero[(ultFilaPiezaJ * x) + ((priColPiezaJ + 1) / 8)] & mascara3) == mascara3)){
        Tablero[((ultFilaPiezaJ - 2) * x) + ((priColPiezaJ + 2) / 8)] |= mascara1;
        Tablero[((ultFilaPiezaJ - 1) * x) + ((priColPiezaJ + 1) / 8)] |= mascara2;
        Tablero[(ultFilaPiezaJ * x) + ((priColPiezaJ + 1) / 8)] |= mascara3;

        unsigned char mascara4 = (0x80 >> ((priColPiezaJ) % 8));
        unsigned char mascara5 = (0x80 >> ((priColPiezaJ) % 8));
        unsigned char mascara6 = (0x80 >> ((priColPiezaJ) % 8));
        Tablero[((ultFilaPiezaJ - 2) * x) + ((priColPiezaJ) / 8)] &= ~mascara4;
        Tablero[((ultFilaPiezaJ - 1) * x) + ((priColPiezaJ) / 8)] &= ~mascara5;
        Tablero[(ultFilaPiezaJ * x) + ((priColPiezaJ) / 8)] &= ~mascara6;

        priColPiezaJ += 1;
    }
}

void moverDerechaPiezaJRot2(const int &x){
    unsigned char mascara1 = (0x80 >> ((priColPiezaJ + 1) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPiezaJ + 3) % 8));

    if(((Tablero[((ultFilaPiezaJ - 1) * x) + ((priColPiezaJ + 1) / 8)] & mascara1) == mascara1) &&
       ((Tablero[(ultFilaPiezaJ * x) + ((priColPiezaJ + 3) / 8)] & mascara2) == mascara2)){
        Tablero[((ultFilaPiezaJ - 1) * x) + ((priColPiezaJ + 1) / 8)] |= mascara1;
        Tablero[(ultFilaPiezaJ * x) + ((priColPiezaJ + 3) / 8)] |= mascara2;

        unsigned char mascara3 = (0x80 >> ((priColPiezaJ) % 8));
        unsigned char mascara4 = (0x80 >> ((priColPiezaJ) % 8));
        Tablero[((ultFilaPiezaJ - 1) * x) + ((priColPiezaJ) / 8)] &= ~mascara3;
        Tablero[(ultFilaPiezaJ * x) + ((priColPiezaJ) / 8)] &= ~mascara4;

        priColPiezaJ += 1;
    }
}

void moverDerechaPiezaJRot3(const int &x){
    unsigned char mascara1 = (0x80 >> ((priColPiezaJ + 3) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPiezaJ + 1) % 8));

    if(((Tablero[((ultFilaPiezaJ - 1) * x) + ((priColPiezaJ + 3) / 8)] & mascara1) == mascara1) &&
       ((Tablero[(ultFilaPiezaJ * x) + ((priColPiezaJ + 1) / 8)] & mascara2) == mascara2)){
        Tablero[((ultFilaPiezaJ - 1) * x) + ((priColPiezaJ + 3) / 8)] |= mascara1;
        Tablero[(ultFilaPiezaJ * x) + ((priColPiezaJ + 1) / 8)] |= mascara2;

        unsigned char mascara3 = (0x80 >> ((priColPiezaJ) % 8));
        unsigned char mascara4 = (0x80 >> ((priColPiezaJ) % 8));
        Tablero[((ultFilaPiezaJ - 1) * x) + ((priColPiezaJ) / 8)] &= ~mascara3;
        Tablero[(ultFilaPiezaJ * x) + ((priColPiezaJ) / 8)] &= ~mascara4;

        priColPiezaJ += 1;
    }
}

void moverIzquierdaPiezaJOrigin(const int &x){
    unsigned char mascara1 = (0x80 >> ((priColPiezaJ) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPiezaJ) % 8));

    if(((Tablero[((ultFilaPiezaJ - 1) * x) + ((priColPiezaJ) / 8)] & mascara1) == mascara1) &&
       ((Tablero[(ultFilaPiezaJ * x) + ((priColPiezaJ) / 8)] & mascara2) == mascara2)){
        Tablero[((ultFilaPiezaJ - 1) * x) + ((priColPiezaJ) / 8)] |= mascara1;
        Tablero[(ultFilaPiezaJ * x) + ((priColPiezaJ) / 8)] |= mascara2;

        unsigned char mascara3 = (0x80 >> ((priColPiezaJ + 2) % 8));
        unsigned char mascara4 = (0x80 >> ((priColPiezaJ + 1) % 8));
        Tablero[((ultFilaPiezaJ - 1) * x) + ((priColPiezaJ + 2) / 8)] &= ~mascara3;
        Tablero[(ultFilaPiezaJ * x) + ((priColPiezaJ + 1) / 8)] &= ~mascara4;

        priColPiezaJ -= 1;
    }
}

void moverIzquierdaPiezaJRot1(const int &x){
    unsigned char mascara1 = (0x80 >> ((priColPiezaJ - 1) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPiezaJ - 1) % 8));
    unsigned char mascara3 = (0x80 >> ((priColPiezaJ - 1) % 8));

    if(((Tablero[((ultFilaPiezaJ - 2) * x) + ((priColPiezaJ - 1) / 8)] & mascara1) == mascara1) &&
       ((Tablero[((ultFilaPiezaJ - 1) * x) + ((priColPiezaJ - 1) / 8)] & mascara2) == mascara2) &&
       ((Tablero[(ultFilaPiezaJ * x) + ((priColPiezaJ - 1) / 8)] & mascara3) == mascara3)){
        Tablero[((ultFilaPiezaJ - 2) * x) + ((priColPiezaJ - 1) / 8)] |= mascara1;
        Tablero[((ultFilaPiezaJ - 1) * x) + ((priColPiezaJ - 1) / 8)] |= mascara2;
        Tablero[(ultFilaPiezaJ * x) + ((priColPiezaJ - 1) / 8)] |= mascara3;

        unsigned char mascara4 = (0x80 >> ((priColPiezaJ + 1) % 8));
        unsigned char mascara5 = (0x80 >> ((priColPiezaJ) % 8));
        unsigned char mascara6 = (0x80 >> ((priColPiezaJ) % 8));
        Tablero[((ultFilaPiezaJ - 2) * x) + ((priColPiezaJ + 1) / 8)] &= ~mascara4;
        Tablero[((ultFilaPiezaJ - 1) * x) + ((priColPiezaJ) / 8)] &= ~mascara5;
        Tablero[(ultFilaPiezaJ * x) + ((priColPiezaJ) / 8)] &= ~mascara6;

        priColPiezaJ -= 1;
    }
}

void moverIzquierdaPiezaJRot2(const int &x){
    unsigned char mascara1 = (0x80 >> ((priColPiezaJ - 1) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPiezaJ - 1) % 8));

    if(((Tablero[((ultFilaPiezaJ - 1) * x) + ((priColPiezaJ - 1) / 8)] & mascara1) == mascara1) &&
       ((Tablero[(ultFilaPiezaJ * x) + ((priColPiezaJ - 1) / 8)] & mascara2) == mascara2)){
        Tablero[((ultFilaPiezaJ - 1) * x) + ((priColPiezaJ - 1) / 8)] |= mascara1;
        Tablero[(ultFilaPiezaJ * x) + ((priColPiezaJ - 1) / 8)] |= mascara2;

        unsigned char mascara3 = (0x80 >> ((priColPiezaJ) % 8));
        unsigned char mascara4 = (0x80 >> ((priColPiezaJ + 2) % 8));
        Tablero[((ultFilaPiezaJ - 1) * x) + ((priColPiezaJ) / 8)] &= ~mascara3;
        Tablero[(ultFilaPiezaJ * x) + ((priColPiezaJ + 2) / 8)] &= ~mascara4;

        priColPiezaJ -= 1;
    }
}

void moverIzquierdaPiezaJRot3(const int &x){
    unsigned char mascara1 = (0x80 >> ((priColPiezaJ - 1) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPiezaJ + 1) % 8));

    if(((Tablero[((ultFilaPiezaJ - 1) * x) + ((priColPiezaJ - 1) / 8)] & mascara1) == mascara1) &&
       ((Tablero[(ultFilaPiezaJ * x) + ((priColPiezaJ + 1) / 8)] & mascara2) == mascara2)){
        Tablero[((ultFilaPiezaJ - 1) * x) + ((priColPiezaJ - 1) / 8)] |= mascara1;
        Tablero[(ultFilaPiezaJ * x) + ((priColPiezaJ + 1) / 8)] |= mascara2;

        unsigned char mascara3 = (0x80 >> ((priColPiezaJ + 2) % 8));
        unsigned char mascara4 = (0x80 >> ((priColPiezaJ + 1) % 8));
        Tablero[((ultFilaPiezaJ - 1) * x) + ((priColPiezaJ + 2) / 8)] &= ~mascara3;
        Tablero[(ultFilaPiezaJ * x) + ((priColPiezaJ + 1) / 8)] &= ~mascara4;

        priColPiezaJ -= 1;
    }
}
