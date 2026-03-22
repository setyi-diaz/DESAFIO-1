#include <iostream>

#include "ModPiezaCuadrado.h"
#include "ModTablero.h"
#include "ModValidaciones.h"

void bajarPiezaCuadrado(const int &y){
    unsigned char mascara1 = (0x80 >> (priColPieza % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 1) % 8));
    char validar = valBajarPiezaCuadrado();

    if(validar == '1'){
        Tablero[ultFilaPieza + 1][priColPieza / 8] |= mascara1;
        Tablero[ultFilaPieza + 1][(priColPieza + 1) / 8] |= mascara2;
        // Actualizacion de la variable que refencia a la fila de la pieza
        ultFilaPieza += 1;
    }
    else if(validar == '2'){
        // Ingresa 1s
        Tablero[ultFilaPieza + 1][(priColPieza / 8)] |= mascara1;
        Tablero[ultFilaPieza + 1][((priColPieza + 1) / 8)] |= mascara2;
        // Ingresa 0s
        Tablero[(ultFilaPieza - 1)][(priColPieza / 8)] ^= mascara1;
        Tablero[(ultFilaPieza - 1)][((priColPieza + 1) / 8)] ^= mascara2;
        // Actualizacion de la variable que refencia a la fila de la pieza
        ultFilaPieza += 1;
        if(ultFilaPieza == (y - 1)){
            fijarPieza = true;
        }
    }
    else if (validar == '3'){
        gameOver = true;
    }
    else if (validar == '0'){
        fijarPieza = true;
    }
}
void desplazarIzqCuadrado(){
    unsigned char mascara = (0x80 >> ((priColPieza - 1) % 8));

    if(priColPieza == 0){
        std::cout<<"No se puede desplazar por fuera del tablero\n";
    }
    else if(((Tablero[(ultFilaPieza)][((priColPieza - 1) / 8)] & mascara)== 0x00) &&
             ((Tablero[(ultFilaPieza - 1)][((priColPieza - 1) / 8)] & mascara) == 0x00)){
        // Ingresa 1s
        Tablero[(ultFilaPieza)][((priColPieza - 1) / 8)] |= mascara;
        Tablero[(ultFilaPieza - 1)][((priColPieza - 1) / 8)] |= mascara;
        // Ingresa 0s
        mascara = (0x80 >> ((priColPieza + 1) % 8));
        Tablero[(ultFilaPieza)][((priColPieza + 1) / 8)] ^= mascara;
        Tablero[(ultFilaPieza - 1)][((priColPieza + 1) / 8)] ^= mascara;
        // Actualizacion de la variable que referencia a la columna de la pieza
        priColPieza -= 1;
    }
    //else fijarPieza = true;
}
void desplazarDerCuadrado(const int &x){
    unsigned char mascara = (0x80 >> ((priColPieza + 2) % 8));

    if((priColPieza + 2) == x*8){
        std::cout<<"No se puede desplazar por fuera del tablero\n";
        //fijarPieza = true;
    }
    else if(((Tablero[(ultFilaPieza)][((priColPieza + 2) / 8)] & mascara)== 0x00) &&
             ((Tablero[(ultFilaPieza - 1)][((priColPieza + 2) / 8)] & mascara) == 0x00)){
        // Ingresa 1s
        Tablero[(ultFilaPieza)][((priColPieza + 2) / 8)] |= mascara;
        Tablero[(ultFilaPieza - 1)][((priColPieza + 2) / 8)] |= mascara;
        // Ingresa 0s
        mascara = (0x80 >> ((priColPieza) % 8));
        Tablero[(ultFilaPieza)][((priColPieza) / 8)] ^= mascara;
        Tablero[(ultFilaPieza - 1)][((priColPieza) / 8)] ^= mascara;
        // Actualizacion de la variable que referencia a la columna de la pieza
        priColPieza += 1;
    }
    //else fijarPieza = true;
}
