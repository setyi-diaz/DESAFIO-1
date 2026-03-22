#include "ModValidaciones.h"
#include "ModTablero.h"
#include <iostream>

bool fijarPieza = false;
bool gameOver = false;

char valBajarPiezaCuadrado(){
    unsigned char mascara1 = (0x80 >> (priColPieza % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 1) % 8));
    if(ultFilaPieza == -1){
        if((Tablero[(ultFilaPieza + 2)][(priColPieza / 8)] & mascara1)== 0x00 &&
            (Tablero[(ultFilaPieza + 2)][((priColPieza + 1) / 8)] & mascara2)== 0x00){
            return '1';
        }
        return '3';
    }
    else if(ultFilaPieza == 0){
        if((Tablero[(ultFilaPieza + 1)][(priColPieza / 8)] & mascara1)== 0x00 &&
            (Tablero[(ultFilaPieza + 1)][((priColPieza + 1) / 8)] & mascara2)== 0x00){
            return '1';
        }
        return '0';
    }
    else if(((Tablero[(ultFilaPieza + 1)][(priColPieza / 8)] & mascara1)== 0x00) &&
             ((Tablero[(ultFilaPieza + 1)][((priColPieza + 1) / 8)] & mascara2) == 0x00)){
        return '2';
    }
    else return '0';
}

char valBajarPiezaTOrigin(){
    unsigned char mascara1 = (0x80 >> (priColPieza % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 1) % 8));
    unsigned char mascara3 = (0x80 >> ((priColPieza + 2) % 8));

    if(ultFilaPieza == -1){
        if((Tablero[(ultFilaPieza + 2)][((priColPieza + 1) / 8)] & mascara2)== 0x00){
            return '1';
        }
        return '4';
    }
    else if(ultFilaPieza == 0){
        if (((Tablero[(ultFilaPieza)][(priColPieza / 8)] & mascara1)== 0x00) &&
            ((Tablero[(ultFilaPieza + 1)][((priColPieza + 1) / 8)] & mascara2) == 0x00) &&
            ((Tablero[(ultFilaPieza)][((priColPieza + 2) / 8)] & mascara3)== 0x00)){
            return '2';
        }
        return '0';
    }
    else if(((Tablero[(ultFilaPieza)][(priColPieza / 8)] & mascara1)== 0x00) &&
               ((Tablero[(ultFilaPieza + 1)][((priColPieza + 1) / 8)] & mascara2) == 0x00) &&
               ((Tablero[(ultFilaPieza)][((priColPieza + 2) / 8)] & mascara3)== 0x00)){
        return '3';
    }
    else return '0';
}
char valBajarPiezaZOrigin(){
    unsigned char mascara1 = (0x80 >> (priColPieza % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 1) % 8));
    unsigned char mascara3 = (0x80 >> ((priColPieza + 2) % 8));

    if(ultFilaPieza == -1){
        if(((Tablero[(ultFilaPieza + 2)][((priColPieza + 1) / 8)] & mascara2) == 0x00) &&
            ((Tablero[(ultFilaPieza + 2)][((priColPieza + 2) / 8)] & mascara3) == 0x00)){
            return '1';
        }
        return '4';
    }
    else if(ultFilaPieza == 0){        
        if(((Tablero[(ultFilaPieza)][(priColPieza / 8)] & mascara1)== 0x00) &&
            ((Tablero[(ultFilaPieza + 1)][((priColPieza + 1) / 8)] & mascara2) == 0x00) &&
            ((Tablero[(ultFilaPieza + 1)][((priColPieza + 2) / 8)] & mascara3) == 0x00)){
            return '2';
        }
        return '0';
    }
    else if(((Tablero[(ultFilaPieza)][(priColPieza / 8)] & mascara1)== 0x00) &&
               ((Tablero[(ultFilaPieza + 1)][((priColPieza + 1) / 8)] & mascara2) == 0x00) &&
               ((Tablero[(ultFilaPieza + 1)][((priColPieza + 2) / 8)] & mascara3) == 0x00)){
        return '3';
    }
    else return '0';
}
bool valAnchoTablero(const int &x){
    if(x % 8 != 0){
        return true;
    }
    else return false;
}
int valEliminarFila(const int &x){
    unsigned char mascara = 0xFF;
    bool ban = true;

    int filaMin = ultFilaPieza - 2;
    if(filaMin < 0){
        filaMin = 0;
    }

    for (int fila = ultFilaPieza; fila >= filaMin; fila--){
        for (int i = 0; i < x; i++){
            if((mascara & Tablero[fila][i]) != mascara){
                ban = false;
                break;
            }
        }
        if(ban == true){
            return fila;
        }
        ban = true;
    }
    return -1;
}




