#ifndef MODTABLERO_H
#define MODTABLERO_H

extern  int priColPieza;
extern  int ultFilaPieza;
extern unsigned char** Tablero;

void crearTablero(const int &x,const int &y);
void borrarTablero(const int &y);
void mostrarTablero(const int &x,const int &y);
unsigned int generarPiezaAlea();
void desplazarFilas(const int &x, int f);

#endif // MODTABLERO_H
