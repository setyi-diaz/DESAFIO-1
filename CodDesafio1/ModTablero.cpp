#include <iostream>
#include <random>
#include "ModTablero.h"

 int priColPieza = 0;
 int ultFilaPieza = -1;
unsigned char** Tablero = nullptr;

void crearTablero(const int &x, const int &y){
    priColPieza = ((x * 8 ) / 2) - 2;
    Tablero = new unsigned char*[y];

    for (int i = 0; i < y; i++) {
        Tablero[i] = new unsigned char [x]{0};
    }
}
void borrarTablero(const int &y){
    if (Tablero == nullptr) return;
    for (int i = 0; i < y; i++) {
        delete[] Tablero[i];
    }
    delete[] Tablero;
    Tablero = nullptr;
    std::cout<<"Memoria liberada"<<std::endl;
}
void mostrarTablero(const int &x,const int &y){
    const char DESP = 8*sizeof(unsigned char) - 1;
    const unsigned masc = 1<<DESP;
    unsigned char temp;

    for(int fila = 0; fila < y; fila++){
        std::cout<<'|';
        for(int col = 0; col < x; col++){
            temp = Tablero[fila][col];
            for(int i=1;i <= DESP + 1;i++){
                std::cout<<(temp & masc?"[] ":" . ");
                temp<<=1;
            }
        }
        std::cout<<'|'<<std::endl;
    }
}
unsigned int generarPiezaAlea(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<unsigned int> dist(0, 3);

    return dist(gen);
}
void desplazarFilas(const int &x){
    for (int i = ultFilaPieza; i >= 0; i--){
        if(i == 0){
            Tablero[0] = &Tablero[ultFilaPieza][0];
            for(int j = 0; j < x; j++){
                Tablero[0][j] &= 0x00;
            }
        }
        else Tablero[i] = &Tablero[i-1][0];
    }
}
