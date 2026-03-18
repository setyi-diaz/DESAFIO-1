#include <iostream>

#include "ModPiezaS.h"
#include "ModTablero.h"  // para acceder a las dimensiones del tablero, fila y columna de referencia a la pieza
#include "ModValidaciones.h"


<<<<<<< Updated upstream
void rota1PiezaS(const int &x)
{
    int bytesPorFila = x / 8;

    int filaApaga1 = ultFilaPieza - 1;
    int colApaga1 = priColPieza + 2;

    int filaApaga2 = ultFilaPieza;
    int colApaga2 = priColPieza;

    int filaEnciende1 = ultFilaPieza - 2;
    int colEnciende1 = priColPieza + 1;

    int filaEnciende2 = ultFilaPieza;
    int colEnciende2 = priColPieza + 2;

    int byteApaga1 = colApaga1 / 8;
    int byteApaga2 = colApaga2 / 8;
    int byteEnciende1 = colEnciende1 / 8;
    int byteEnciende2 = colEnciende2 / 8;

    unsigned char mascaraApaga1 = (0x80 >> (colApaga1 % 8));
    unsigned char mascaraApaga2 = (0x80 >> (colApaga2 % 8));
    unsigned char mascaraEnciende1 = (0x80 >> (colEnciende1 % 8));
    unsigned char mascaraEnciende2 = (0x80 >> (colEnciende2 % 8));

    Tablero[(filaApaga1 * bytesPorFila) + byteApaga1] &= (unsigned char)(~mascaraApaga1);
    Tablero[(filaApaga2 * bytesPorFila) + byteApaga2] &= (unsigned char)(~mascaraApaga2);

    Tablero[(filaEnciende1 * bytesPorFila) + byteEnciende1] |= mascaraEnciende1;
    Tablero[(filaEnciende2 * bytesPorFila) + byteEnciende2] |= mascaraEnciende2;
}

void rota2PiezaS(const int &x)
{
    int bytesPorFila = x / 8;


    int filaApaga1 = ultFilaPieza - 2;
    int colApaga1 = priColPieza + 1;

    int filaApaga2 = ultFilaPieza;
    int colApaga2 = priColPieza + 2;

    int filaEnciende1 = ultFilaPieza - 1;
    int colEnciende1 = priColPieza + 2;

    int filaEnciende2 = ultFilaPieza;
    int colEnciende2 = priColPieza;

    int byteApaga1 = colApaga1 / 8;
    int byteApaga2 = colApaga2 / 8;
    int byteEnciende1 = colEnciende1 / 8;
    int byteEnciende2 = colEnciende2 / 8;

    unsigned char mascaraApaga1 = (0x80 >> (colApaga1 % 8));
    unsigned char mascaraApaga2 = (0x80 >> (colApaga2 % 8));
    unsigned char mascaraEnciende1 = (0x80 >> (colEnciende1 % 8));
    unsigned char mascaraEnciende2 = (0x80 >> (colEnciende2 % 8));

    Tablero[(filaApaga1 * bytesPorFila) + byteApaga1] &= (unsigned char)(~mascaraApaga1);
    Tablero[(filaApaga2 * bytesPorFila) + byteApaga2] &= (unsigned char)(~mascaraApaga2);

    Tablero[(filaEnciende1 * bytesPorFila) + byteEnciende1] |= mascaraEnciende1;
    Tablero[(filaEnciende2 * bytesPorFila) + byteEnciende2] |= mascaraEnciende2;
=======

void rota1PiezaS(){
    int x = ancho / 8;
    unsigned char mascara1 = (0x80 >> ((priColPiezaS) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPiezaS) % 8));

    if(((Tablero[((ultFilaPiezaS - 2) * x) + ((priColPiezaS) / 8)] & mascara1) == mascara1) &&
        ((Tablero[((ultFilaPiezaS - 1) * x) + ((priColPiezaS) / 8)] & mascara2) == mascara2)){
        // Ingresa 1s
        Tablero[((ultFilaPiezaS - 2) * x) + ((priColPiezaS) / 8)] |= mascara1;
        Tablero[((ultFilaPiezaS - 1) * x) + ((priColPiezaS) / 8)] |= mascara2;
        // Ingresa 0s
        unsigned char mascara1 = (0x80 >> ((priColPiezaS + 2) % 8));
        Tablero[((ultFilaPiezaS - 1) * x) + ((priColPiezaS + 2) / 8)] &= ~mascara1;
        unsigned char mascara2 = (0x80 >> ((priColPiezaS) % 8));
        Tablero[((ultFilaPiezaS) * x) + ((priColPiezaS) / 8)] &= ~mascara2;
    }
}

void rota2PiezaS(){
    int x = ancho / 8;
    unsigned char mascara1 = (0x80 >> ((priColPiezaS + 2) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPiezaS) % 8));

    if(((Tablero[((ultFilaPiezaS - 1) * x) + ((priColPiezaS + 2) / 8)] & mascara1) == mascara1) &&
        ((Tablero[((ultFilaPiezaS) * x) + ((priColPiezaS) / 8)] & mascara2) == mascara2)){
        // Ingresa 1s
        Tablero[((ultFilaPiezaS - 1) * x) + ((priColPiezaS + 2) / 8)] |= mascara1;
        Tablero[((ultFilaPiezaS) * x) + ((priColPiezaS) / 8)] |= mascara2;
        // Ingresa 0s
        unsigned char mascara1 = (0x80 >> ((priColPiezaS) % 8));
        Tablero[((ultFilaPiezaS - 2) * x) + ((priColPiezaS) / 8)] &= ~mascara1;
        unsigned char mascara2 = (0x80 >> ((priColPiezaS) % 8));
        Tablero[((ultFilaPiezaS - 1) * x) + ((priColPiezaS) / 8)] &= ~mascara2;
    }
}

void bajarPiezaSOrigin(){
    int x = ancho / 8;
    unsigned char mascara1 = (0x80 >> ((priColPiezaS + 2) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPiezaS) % 8));
    unsigned char mascara3 = (0x80 >> ((priColPiezaS + 1) % 8));

    if(((Tablero[((ultFilaPiezaS) * x) + ((priColPiezaS + 2) / 8)] & mascara1) == mascara1) &&
        ((Tablero[((ultFilaPiezaS + 1) * x) + ((priColPiezaS) / 8)] & mascara2) == mascara2) &&
        ((Tablero[((ultFilaPiezaS + 1) * x) + ((priColPiezaS + 1) / 8)] & mascara3) == mascara3)){
        // Ingresa 1s
        Tablero[((ultFilaPiezaS) * x) + ((priColPiezaS + 2) / 8)] |= mascara1;
        Tablero[((ultFilaPiezaS + 1) * x) + ((priColPiezaS) / 8)] |= mascara2;
        Tablero[((ultFilaPiezaS + 1) * x) + ((priColPiezaS + 1) / 8)] |= mascara3;
        // Ingresa 0s
        unsigned char mascara1 = (0x80 >> ((priColPiezaS + 1) % 8));
        Tablero[((ultFilaPiezaS - 1) * x) + ((priColPiezaS + 1) / 8)] &= ~mascara1;
        unsigned char mascara2 = (0x80 >> ((priColPiezaS + 2) % 8));
        Tablero[((ultFilaPiezaS - 1) * x) + ((priColPiezaS + 2) / 8)] &= ~mascara2;
        unsigned char mascara3 = (0x80 >> ((priColPiezaS) % 8));
        Tablero[((ultFilaPiezaS) * x) + ((priColPiezaS) / 8)] &= ~mascara3;
        ultFilaPiezaS += 1;
    }
    else fijarPieza = true;
}

void bajarPiezaSRot1(){
    int x = ancho / 8;
    unsigned char mascara1 = (0x80 >> ((priColPiezaS) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPiezaS + 1) % 8));

    if(((Tablero[((ultFilaPiezaS) * x) + ((priColPiezaS) / 8)] & mascara1) == mascara1) &&
        ((Tablero[((ultFilaPiezaS + 1) * x) + ((priColPiezaS + 1) / 8)] & mascara2) == mascara2)){
        // Ingresa 1s
        Tablero[((ultFilaPiezaS) * x) + ((priColPiezaS) / 8)] |= mascara1;
        Tablero[((ultFilaPiezaS + 1) * x) + ((priColPiezaS + 1) / 8)] |= mascara2;
        // Ingresa 0s
        unsigned char mascara1 = (0x80 >> ((priColPiezaS) % 8));
        Tablero[((ultFilaPiezaS - 2) * x) + ((priColPiezaS) / 8)] &= ~mascara1;
        unsigned char mascara2 = (0x80 >> ((priColPiezaS + 1) % 8));
        Tablero[((ultFilaPiezaS - 1) * x) + ((priColPiezaS + 1) / 8)] &= ~mascara2;
        ultFilaPiezaS += 1;
    }
    else fijarPieza = true;
}

void moverDerechaPiezaSOrigin(){
    int x = ancho / 8;
    unsigned char mascara1 = (0x80 >> ((priColPiezaS + 3) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPiezaS + 2) % 8));

    if(((Tablero[((ultFilaPiezaS - 1) * x) + ((priColPiezaS + 3) / 8)] & mascara1) == mascara1) &&
        ((Tablero[((ultFilaPiezaS) * x) + ((priColPiezaS + 2) / 8)] & mascara2) == mascara2)){
        // Ingresa 1s
        Tablero[((ultFilaPiezaS - 1) * x) + ((priColPiezaS + 3) / 8)] |= mascara1;
        Tablero[((ultFilaPiezaS) * x) + ((priColPiezaS + 2) / 8)] |= mascara2;
        // Ingresa 0s
        unsigned char mascara1 = (0x80 >> ((priColPiezaS + 1) % 8));
        Tablero[((ultFilaPiezaS - 1) * x) + ((priColPiezaS + 1) / 8)] &= ~mascara1;
        unsigned char mascara2 = (0x80 >> ((priColPiezaS) % 8));
        Tablero[((ultFilaPiezaS) * x) + ((priColPiezaS) / 8)] &= ~mascara2;
        priColPiezaS += 1;
    }
}

void moverDerechaPiezaSRot1(){
    int x = ancho / 8;
    unsigned char mascara1 = (0x80 >> ((priColPiezaS + 1) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPiezaS + 2) % 8));
    unsigned char mascara3 = (0x80 >> ((priColPiezaS + 2) % 8));

    if(((Tablero[((ultFilaPiezaS - 2) * x) + ((priColPiezaS + 1) / 8)] & mascara1) == mascara1) &&
        ((Tablero[((ultFilaPiezaS - 1) * x) + ((priColPiezaS + 2) / 8)] & mascara2) == mascara2) &&
        ((Tablero[((ultFilaPiezaS) * x) + ((priColPiezaS + 2) / 8)] & mascara3) == mascara3)){
        // Ingresa 1s
        Tablero[((ultFilaPiezaS - 2) * x) + ((priColPiezaS + 1) / 8)] |= mascara1;
        Tablero[((ultFilaPiezaS - 1) * x) + ((priColPiezaS + 2) / 8)] |= mascara2;
        Tablero[((ultFilaPiezaS) * x) + ((priColPiezaS + 2) / 8)] |= mascara3;
        // Ingresa 0s
        unsigned char mascara1 = (0x80 >> ((priColPiezaS) % 8));
        Tablero[((ultFilaPiezaS - 2) * x) + ((priColPiezaS) / 8)] &= ~mascara1;
        unsigned char mascara2 = (0x80 >> ((priColPiezaS) % 8));
        Tablero[((ultFilaPiezaS - 1) * x) + ((priColPiezaS) / 8)] &= ~mascara2;
        unsigned char mascara3 = (0x80 >> ((priColPiezaS + 1) % 8));
        Tablero[((ultFilaPiezaS) * x) + ((priColPiezaS + 1) / 8)] &= ~mascara3;
        priColPiezaS += 1;
    }
}

void moverIzquierdaPiezaSOrigin(){
    int x = ancho / 8;

    unsigned char mascara1 = (0x80 >> ((priColPiezaS) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPiezaS - 1) % 8));

    if(((Tablero[((ultFilaPiezaS - 1) * x) + ((priColPiezaS) / 8)] & mascara1) == mascara1) &&
       ((Tablero[(ultFilaPiezaS * x) + ((priColPiezaS - 1) / 8)] & mascara2) == mascara2)){
        // Ingresa 1s
        Tablero[((ultFilaPiezaS - 1) * x) + ((priColPiezaS) / 8)] |= mascara1;
        Tablero[(ultFilaPiezaS * x) + ((priColPiezaS - 1) / 8)] |= mascara2;
        // Ingresa 0s
        unsigned char mascara3 = (0x80 >> ((priColPiezaS + 2) % 8));
        unsigned char mascara4 = (0x80 >> ((priColPiezaS + 1) % 8));
        Tablero[((ultFilaPiezaS - 1) * x) + ((priColPiezaS + 2) / 8)] &= ~mascara3;
        Tablero[(ultFilaPiezaS * x) + ((priColPiezaS + 1) / 8)] &= ~mascara4;
        priColPiezaS -= 1;
    }
}

void moverIzquierdaPiezaSRot1(){
    int x = ancho / 8;
    unsigned char mascara1 = (0x80 >> ((priColPiezaS - 1) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPiezaS - 1) % 8));
    unsigned char mascara3 = (0x80 >> ((priColPiezaS) % 8));

    if(((Tablero[((ultFilaPiezaS - 2) * x) + ((priColPiezaS - 1) / 8)] & mascara1) == mascara1) &&
        ((Tablero[((ultFilaPiezaS - 1) * x) + ((priColPiezaS - 1) / 8)] & mascara2) == mascara2) &&
        ((Tablero[((ultFilaPiezaS) * x) + ((priColPiezaS) / 8)] & mascara3) == mascara3)){
        // Ingresa 1s
        Tablero[((ultFilaPiezaS - 2) * x) + ((priColPiezaS - 1) / 8)] |= mascara1;
        Tablero[((ultFilaPiezaS - 1) * x) + ((priColPiezaS - 1) / 8)] |= mascara2;
        Tablero[((ultFilaPiezaS) * x) + ((priColPiezaS) / 8)] |= mascara3;
        // Ingresa 0s
        unsigned char mascara4 = (0x80 >> ((priColPiezaS) % 8));
        unsigned char mascara5 = (0x80 >> ((priColPiezaS + 1) % 8));
        unsigned char mascara6 = (0x80 >> ((priColPiezaS + 1) % 8));
        Tablero[((ultFilaPiezaS - 2) * x) + ((priColPiezaS) / 8)] &= ~mascara4;
        Tablero[((ultFilaPiezaS - 1) * x) + ((priColPiezaS + 1) / 8)] &= ~mascara5;
        Tablero[((ultFilaPiezaS) * x) + ((priColPiezaS + 1) / 8)] &= ~mascara6;
        priColPiezaS -= 1;
    }
>>>>>>> Stashed changes
}
