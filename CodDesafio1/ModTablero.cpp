#include <iostream>
#include <random>
#include "ModTablero.h"

 int priColPieza = 0;
 int ultFilaPieza = -1;
char* Tablero = nullptr;

void crearTablero(const int &x, const int &y){
    priColPieza = ((x * 8 ) / 2) - 2;
    Tablero = new char[y * x]; //reserva de memoria en el heap, ptrTablero en el stack
    for (int i = 0; i < (y * x); i++) {
        Tablero[i] = 0;
    }
}
void borrarTablero(){
    delete[] Tablero;
    Tablero = nullptr;
    std::cout<<"Memoria liberada"<<std::endl;
}
void mostrarTablero(const int &x,const int &y){
    const char DESP = 8*sizeof(unsigned char) - 1;
    const unsigned masc = 1<<DESP;

    for(int byte = 0; byte < (y * x); byte++){
        for(int i=1;i <= DESP + 1;i++){
            std::cout<<(Tablero[byte] & masc?'1':'0');
            Tablero[byte]<<=1;
        }
        if((byte+1) % x == 0)
            std::cout<<std::endl;
    }
}
unsigned int generarPiezaAlea(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<unsigned int> dist(0, 1);

    return dist(gen);
}
