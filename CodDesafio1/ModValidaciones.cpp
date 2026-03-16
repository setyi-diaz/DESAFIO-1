#include "ModValidaciones.h"
#include "ModTablero.h"
#include <iostream>

char valBajarPiezaTOrigin(const int &x){
    unsigned char mascara1 = (0x80 >> (priColPieza % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 1) % 8));
    unsigned char mascara3 = (0x80 >> ((priColPieza + 2) % 8));
    if(ultFilaPieza == -1){
        if((Tablero[(ultFilaPieza * x) + (priColPieza / 8)] & mascara1)== mascara1){
            return '1';
        }
        return '0';
    }
    else if(ultFilaPieza == 0){
        if (((Tablero[(ultFilaPieza * x) + (priColPieza / 8)] & mascara1)== mascara1) &&
            ((Tablero[((ultFilaPieza + 1) * x) + ((priColPieza + 1) / 8)] & mascara2) == mascara2) &&
            ((Tablero[(ultFilaPieza * x) + ((priColPieza + 2) / 8)] & mascara3)== mascara3)){
            return '2';
        }
        return '0';
    }
    else return '3';
}
char valBajarPiezaZOrigin(const int &x){
    unsigned char mascara1 = (0x80 >> (priColPieza % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 1) % 8));
    unsigned char mascara3 = (0x80 >> ((priColPieza + 2) % 8));

    if(ultFilaPieza == -1){
        if(((Tablero[((ultFilaPieza + 1) * x) + ((priColPieza + 1) / 8)] & mascara2) == mascara2) &&
            ((Tablero[((ultFilaPieza + 1) * x) + ((priColPieza + 2) / 8)] & mascara3) == mascara3)){
            return '1';
        }
        return '0';
    }
    else if(ultFilaPieza == 0){
        if(((Tablero[(ultFilaPieza * x) + (priColPieza / 8)] & mascara1)== mascara1) &&
            ((Tablero[((ultFilaPieza + 1) * x) + ((priColPieza + 1) / 8)] & mascara2) == mascara2) &&
            ((Tablero[((ultFilaPieza + 1) * x) + ((priColPieza + 2) / 8)] & mascara3) == mascara3)){
            return '2';
        }
        return '0';
    }
    else return '3';
}
bool valAnchoTablero(const int &x){
    if(x % 8 != 0){
        return true;
    }
    else return false;
}






