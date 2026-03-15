#include <iostream>

#include "ModPiezaT.h"
#include "ModTablero.h"  // para acceder a las dimensiones del tablero

int priColPieza = (ancho/2)-2;
int ultFilaPieza = alto;

void rota1PiezaT(){
    int filaAux = ultFilaPieza - 2;
    int colAux = priColPieza / 8;
    unsigned char mascara = (0x80 >> ((priColPieza%8)+1));

    Tablero[(filaAux * ancho) + colAux] |= mascara;
}
void rota2PiezaT(){
    int filaAux = ultFilaPieza;
    int colAux = priColPieza / 8;
    unsigned char mascara1 = (0x80 >> (priColPieza % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza % 8) + 2));

    if(((Tablero[(filaAux * ancho) + colAux] & mascara1)==mascara1) &&
        ((Tablero[(filaAux * ancho) + colAux] & mascara2)==mascara2)){
        Tablero[(filaAux * ancho) + colAux] |= mascara1;
        Tablero[(filaAux * ancho) + colAux] |= mascara2;
    }
}
void rota3PiezaT(){
    int filaAux1 = ultFilaPieza - 1;
    int filaAux2 = ultFilaPieza - 2;
    int colAux = priColPieza / 8;
    unsigned char mascara = (0x80 >> (priColPieza % 8));

    if((Tablero[(filaAux1 * ancho) + colAux]== mascara) && (Tablero[(filaAux2 * ancho) + colAux] == mascara)){
        Tablero[(filaAux1 * ancho) + colAux] |= mascara;
        Tablero[(filaAux1 * ancho) + colAux] |= mascara;
    }
}
