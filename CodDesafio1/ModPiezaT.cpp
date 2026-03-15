#include <iostream>

#include "ModPiezaT.h"
#include "ModTablero.h"  // para acceder a las dimensiones del tablero, fila y columna de referencia a la pieza

void rota1PiezaT(){
    int filaAux = ultFilaPieza - 2;
    int colAux = (priColPieza + 1) / 8;
    unsigned char mascara = (priColPieza + 1) % 8;
    // Ingresa 1s
    Tablero[(filaAux * ancho) + colAux] |= mascara;
    // Ingresa 0s
    filaAux = ultFilaPieza - 1;
    colAux = (priColPieza + 2)/8;
    mascara = (0x80 >> (priColPieza + 2) % 8);

    Tablero[(filaAux * ancho) + colAux] ^= mascara;
}
void rota2PiezaT(){
    int filaAux = ultFilaPieza;
    int colAux1 = priColPieza / 8;
    int colAux2 = (priColPieza + 2) / 8;
    unsigned char mascara1 = (0x80 >> (priColPieza % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 2) % 8));

    if(((Tablero[(filaAux * ancho) + colAux1] & mascara1)==mascara1) &&
        ((Tablero[(filaAux * ancho) + colAux2] & mascara2)==mascara2)){
        // Ingresa 1s
        Tablero[(filaAux * ancho) + colAux1] |= mascara1;
        Tablero[(filaAux * ancho) + colAux2] |= mascara2;
        // Ingresa 0s
        filaAux = ultFilaPieza - 1;
        Tablero[(filaAux * ancho) + colAux1] ^= mascara1;
        filaAux = ultFilaPieza - 2;
        colAux2 = (priColPieza + 1) / 8;
        mascara2 = (0x80 >> ((priColPieza + 1) % 8));
        Tablero[(filaAux * ancho) + colAux2] ^= mascara2;
    }
}
void rota3PiezaT(){
    int filaAux1 = ultFilaPieza - 1;
    int filaAux2 = ultFilaPieza - 2;
    int colAux = priColPieza / 8;
    unsigned char mascara = (0x80 >> (priColPieza % 8));

    if((Tablero[(filaAux1 * ancho) + colAux]== mascara) && (Tablero[(filaAux2 * ancho) + colAux] == mascara)){
        // Ingresa 1s
        Tablero[(filaAux1 * ancho) + colAux] |= mascara;
        Tablero[(filaAux1 * ancho) + colAux] |= mascara;
        // Ingresa 0s
        filaAux1 = ultFilaPieza;
        colAux = (priColPieza + 1) / 8;
        mascara = (0x80 >> ((priColPieza + 1) % 8));
        Tablero[(filaAux1 * ancho) + colAux] ^= mascara;

        colAux = (priColPieza + 2) / 8;
        mascara = (0x80 >> ((priColPieza + 2) % 8));
        Tablero[(filaAux1 * ancho) + colAux] ^= mascara;
    }
}
void rota4PiezaT(){
    int filaAux1 = ultFilaPieza;
    int filaAux2 = ultFilaPieza - 1;
    int colAux1 = (priColPieza + 1) / 8;
    int colAux2 = (priColPieza + 2) / 8;
    unsigned char mascara1 = (0x80 >> ((priColPieza + 1) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 2) % 8));

    if((Tablero[(filaAux1 * ancho) + colAux1]== mascara1) && (Tablero[(filaAux2 * ancho) + colAux2] == mascara2)){
        // Ingresa 1s
        Tablero[(filaAux1 * ancho) + colAux1] |= mascara1;
        Tablero[(filaAux1 * ancho) + colAux2] |= mascara2;
        // Ingresa 0s
        filaAux1 = ultFilaPieza;
        colAux1 = priColPieza / 8;
        mascara1 = (0x80 >> (priColPieza % 8));
        Tablero[(filaAux1 * ancho) + colAux1] ^= mascara1;

        filaAux2 = ultFilaPieza - 2;
        Tablero[(filaAux2 * ancho) + colAux1] ^= mascara1;
    }
}
