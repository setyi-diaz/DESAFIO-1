#ifndef MODVALIDACIONES_H
#define MODVALIDACIONES_H

extern bool fijarPieza;
extern bool gameOver;

bool valAnchoTablero(const int &x);
char valBajarPiezaTOrigin();
char valBajarPiezaZOrigin();
char valBajarPiezaCuadrado();
int valEliminarFila(const int &x);

#endif // MODVALIDACIONES_H
