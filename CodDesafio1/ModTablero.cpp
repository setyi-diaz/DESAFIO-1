#include "ModTablero.h"

#include <iostream>

int ancho = 0;
int alto = 0;
int priColPieza = 0;
int ultFilaPieza = 0;

void crearTablero(){
    cout<<"Ingrese el alto del tablero: "<<endl;
    cin >> alto;
    cout<<"Ingrese el ancho del tablero: "<<endl;
    cin >> ancho;
    ancho /= 8;

    char* Tablero = new char[alto * ancho];
}

