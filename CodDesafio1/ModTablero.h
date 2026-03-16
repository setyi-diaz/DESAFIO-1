#ifndef MODTABLERO_H
#define MODTABLERO_H

extern  int priColPieza;
extern  int ultFilaPieza;
extern char* Tablero;

void crearTablero(const int &x,const int &y);
void borrarTablero();
void mostrarTablero(const int &x,const int &y);
unsigned int generarPiezaAlea();

#endif // MODTABLERO_H
