#include "ModPiezaZ.h"
#include "ModTablero.h"  // para acceder a las dimensiones del tablero, fila y columna de referencia a la pieza

#include <iostream>

void rota1PiezaZ(){
    int filaAux1 = ultFilaPieza;
    int filaAux2 = ultFilaPieza - 2;
    int colAux1 = priColPieza / 8;
    int colAux2 = (priColPieza + 1) / 8;
    unsigned char mascara1 = (0x80 >> (priColPieza % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 1) % 8));

    if(((Tablero[(filaAux1 * ancho) + colAux1] & mascara1)== mascara1) &&
        ((Tablero[(filaAux2 * ancho) + colAux2] & mascara2) == mascara2)){
        // Ingresa 1s
        Tablero[(filaAux1 * ancho) + colAux1] |= mascara1;
        Tablero[(filaAux1 * ancho) + colAux2] |= mascara2;
        // Ingresa 0s
        colAux1 = (priColPieza + 2) / 8;
        mascara1 = (0x80 >> ((priColPieza + 2) % 8));
        Tablero[(filaAux1 * ancho) + colAux1] ^= mascara1;

        colAux2 = (priColPieza + 3) / 8;
        mascara2 = (0x80 >> ((priColPieza + 3) % 8));
        Tablero[(filaAux1 * ancho) + colAux2] |= mascara2;
    }
}
void rota2PiezaZ(){
    int filaAux = ultFilaPieza;
    int colAux1 = (priColPieza + 2) / 8;
    int colAux2 = (priColPieza + 3) / 8;
    unsigned char mascara1 = (0x80 >> ((priColPieza + 2) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 3) % 8));

    if(((Tablero[(filaAux * ancho) + colAux1] & mascara1)== mascara1) &&
        ((Tablero[(filaAux2 * ancho) + colAux2] & mascara2) == mascara2)){
        // Ingresa 1s
        Tablero[(filaAux * ancho) + colAux1] |= mascara1;
        Tablero[(filaAux * ancho) + colAux2] |= mascara2;
        // Ingresa 0s
        filaAux = ultFilaPieza;
        colAux1 = priColPieza/ 8;
        mascara1 = (0x80 >> (priColPieza % 8));
        Tablero[(filaAux * ancho) + colAux1] ^= mascara1;

        filaAux = ultFilaPieza - 2;
        colAux2 = (priColPieza + 1) / 8;
        mascara2 = (0x80 >> ((priColPieza + 1) % 8));
        Tablero[(filaAux * ancho) + colAux2] ^= mascara2;
    }
}
void bajarPiezaZOrigin(){
    int filaAux1 = ultFilaPieza;
    int filaAux2 = ultFilaPieza + 1;
    int filaAux3 = ultFilaPieza + 1;
    int colAux1 = priColPieza / 8;
    int colAux2 = (priColPieza + 1) / 8;
    int colAux3 = (priColPieza + 2) / 8;
    unsigned char mascara1 = (0x80 >> (priColPieza % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 1) % 8));
    unsigned char mascara3 = (0x80 >> ((priColPieza + 2) % 8));

    if(((Tablero[(filaAux1 * ancho) + colAux1] & mascara1)== mascara1) &&
        ((Tablero[(filaAux2 * ancho) + colAux2] & mascara2) == mascara2) &&
        ((Tablero[(filaAux3 * ancho) + colAux3] & mascara3) == mascara3)){
        // Ingresa 1s
        Tablero[(filaAux1 * ancho) + colAux1] |= mascara1;
        Tablero[(filaAux2 * ancho) + colAux2] |= mascara2;
        Tablero[(filaAux3 * ancho) + colAux3] |= mascara3;
        // Ingresa 0s
        filaAux1 = ultFilaPieza - 1;
        Tablero[(filaAux1 * ancho) + colAux1] ^= mascara1;
        Tablero[(filaAux1 * ancho) + colAux2] ^= mascara2;
        filaAux1 = ultFilaPieza;
        Tablero[(filaAux1 * ancho) + colAux3] ^= mascara3;
        // Actualizacion de la variable a la fila de la pieza
        ultFilaPieza += 1;
    }
}
void bajarPiezaZRot1(){
    int filaAux1 = ultFilaPieza + 1;
    int filaAux2 = ultFilaPieza;
    int colAux1 = priColPieza / 8;
    int colAux2 = (priColPieza + 1) / 8;
    unsigned char mascara1 = (0x80 >> (priColPieza % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 1) % 8));

    if(((Tablero[(filaAux1 * ancho) + colAux1] & mascara1)== mascara1) &&
        ((Tablero[(filaAux2 * ancho) + colAux2] & mascara2) == mascara2)){
        // Ingresa 1s
        Tablero[(filaAux1 * ancho) + colAux1] |= mascara1;
        Tablero[(filaAux2 * ancho) + colAux2] |= mascara2;
        // Ingresa 0s
        filaAux1 = ultFilaPieza - 1;
        Tablero[(filaAux1 * ancho) + colAux1] ^= mascara1;

        filaAux2 = ultFilaPieza - 2;
        Tablero[(filaAux2 * ancho) + colAux2] ^= mascara2;
        // Actualizacion de la variable a la fila de la pieza
        ultFilaPieza += 1;
    }
}













