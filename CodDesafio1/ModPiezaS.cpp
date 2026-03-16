#include <iostream>

#include "ModPiezaS.h"
#include "ModTablero.h"


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
}
