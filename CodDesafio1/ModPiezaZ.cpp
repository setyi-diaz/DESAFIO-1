#include <iostream>

#include "ModPiezaZ.h"
#include "ModTablero.h"  // para acceder a las dimensiones del tablero, fila y columna de referencia a la pieza
#include "ModValidaciones.h"

void rota1PiezaZ(){
    unsigned char mascara1 = (0x80 >> (priColPieza % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 1) % 8));

    if(((Tablero[ultFilaPieza][(priColPieza / 8)] & mascara1)== 0x00) &&
        ((Tablero[(ultFilaPieza - 2)][((priColPieza + 1) / 8)] & mascara2) == 0x00)){
        // Ingresa 1s
        Tablero[(ultFilaPieza)][(priColPieza / 8)] |= mascara1;
        Tablero[(ultFilaPieza - 2)][((priColPieza + 1) / 8)] |= mascara2;
        // Ingresa 0s
        mascara1 = (0x80 >> ((priColPieza + 1) % 8));
        Tablero[(ultFilaPieza)][((priColPieza + 1) / 8)] ^= mascara1;

        mascara2 = (0x80 >> ((priColPieza + 2) % 8));
        Tablero[(ultFilaPieza)][((priColPieza + 2) / 8)] ^= mascara2;
    }
}
void rota2PiezaZ(){
    unsigned char mascara1 = (0x80 >> ((priColPieza + 1) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 2) % 8));

    if(((Tablero[(ultFilaPieza)][((priColPieza + 1) / 8)] & mascara1)== 0x00) &&
        ((Tablero[(ultFilaPieza)][((priColPieza + 2) / 8)] & mascara2) == 0x00)){
        // Ingresa 1s
        Tablero[(ultFilaPieza)][((priColPieza + 1) / 8)] |= mascara1;
        Tablero[(ultFilaPieza)][((priColPieza + 2) / 8)] |= mascara2;
        // Ingresa 0s
        mascara1 = (0x80 >> (priColPieza % 8));
        Tablero[(ultFilaPieza)][(priColPieza/ 8)] ^= mascara1;

        mascara2 = (0x80 >> ((priColPieza + 1) % 8));
        Tablero[(ultFilaPieza - 2)][((priColPieza + 1) / 8)] ^= mascara2;
    }
}
void bajarPiezaZOrigin(const int &y){
    unsigned char mascara1 = (0x80 >> (priColPieza % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 1) % 8));
    unsigned char mascara3 = (0x80 >> ((priColPieza + 2) % 8));
    char validacion = valBajarPiezaZOrigin();

    if(validacion == '1'){
        // Ingresa 1s
        Tablero[(ultFilaPieza + 1)][((priColPieza + 1) / 8)] |= mascara2;
        Tablero[(ultFilaPieza + 1)][((priColPieza + 2) / 8)] |= mascara3;
        // Actualizacion de la variable que refencia a la fila de la pieza
        ultFilaPieza += 1;
    }
    else if(validacion == '2'){
        // Ingresa 1s
        Tablero[(ultFilaPieza)][(priColPieza / 8)] |= mascara1;
        Tablero[(ultFilaPieza + 1)][((priColPieza + 1) / 8)] |= mascara2;
        Tablero[(ultFilaPieza + 1)][((priColPieza + 2) / 8)] |= mascara3;
        // Ingresa 0s
        Tablero[(ultFilaPieza)][((priColPieza + 2) / 8)] ^= mascara3;
        // Actualizacion de la variable que refencia a la fila de la pieza
        ultFilaPieza += 1;
    }
    else if(validacion == '3'){
        // Ingresa 1s
        Tablero[(ultFilaPieza)][(priColPieza / 8)] |= mascara1;
        Tablero[(ultFilaPieza + 1)][((priColPieza + 1) / 8)] |= mascara2;
        Tablero[(ultFilaPieza + 1)][((priColPieza + 2) / 8)] |= mascara3;
        // Ingresa 0s
        Tablero[(ultFilaPieza - 1)][(priColPieza / 8)] ^= mascara1;
        Tablero[(ultFilaPieza - 1)][((priColPieza + 1) / 8)] ^= mascara2;
        Tablero[(ultFilaPieza)][((priColPieza + 2) / 8)] ^= mascara3;
        // Actualizacion de la variable que refencia a la fila de la pieza
        ultFilaPieza += 1;
        if(ultFilaPieza == (y - 1)){
            fijarPieza = true;
        }
    }
    else if (validacion == '4'){
        gameOver = true;
    }
    else if (validacion == '0'){
        fijarPieza = true;
    }
}
void bajarPiezaZRot1(const int &y){
    unsigned char mascara1 = (0x80 >> (priColPieza % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 1) % 8));

    if(((Tablero[(ultFilaPieza + 1)][priColPieza / 8] & mascara1)== 0x00) &&
        ((Tablero[(ultFilaPieza)][((priColPieza + 1) / 8)] & mascara2) == 0x00)){
        // Ingresa 1s
        Tablero[(ultFilaPieza + 1)][priColPieza / 8] |= mascara1;
        Tablero[(ultFilaPieza)][((priColPieza + 1) / 8)] |= mascara2;
        // Ingresa 0s
        Tablero[(ultFilaPieza - 1)][priColPieza / 8] ^= mascara1;

        Tablero[(ultFilaPieza - 2)][((priColPieza + 1) / 8)] ^= mascara2;
        // Actualizacion de la variable que refencia a la fila de la pieza
        ultFilaPieza += 1;
        if(ultFilaPieza == (y - 1)){
            fijarPieza = true;
        }
    }
    else {
        fijarPieza = true;
    }
}
void desplazarIzqZorigin(){
    unsigned char mascara1 = (0x80 >> (priColPieza % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza - 1) % 8));

    if(priColPieza == 0){
        return;
    }
    else if(((Tablero[(ultFilaPieza)][(priColPieza / 8)] & mascara1)== 0x00) &&
        ((Tablero[(ultFilaPieza - 1)][((priColPieza - 1) / 8)] & mascara2) == 0x00)){
        // Ingresa 1s
        Tablero[(ultFilaPieza)][(priColPieza / 8)] |= mascara1;
        Tablero[(ultFilaPieza - 1)][((priColPieza - 1) / 8)] |= mascara2;
        // Ingresa 0s
        mascara1 = (0x80 >> ((priColPieza + 2) % 8));
        Tablero[(ultFilaPieza)][((priColPieza + 2) / 8)] ^= mascara1;

        mascara2 = (0x80 >> ((priColPieza + 1) % 8));
        Tablero[(ultFilaPieza - 1)][((priColPieza + 1) / 8)] ^= mascara2;
        // Actualizacion de la variable que referencia a la columna de la pieza
        priColPieza -= 1;
    }
    else {
        fijarPieza = true;
    }
}
void desplazarIzqZRot1(){
    unsigned char mascara1 = (0x80 >> ((priColPieza - 1) % 8));
    unsigned char mascara2 = (0x80 >> (priColPieza % 8));

    if(priColPieza == 0){
        return;
    }
    else if(((Tablero[(ultFilaPieza)][((priColPieza - 1) / 8)] & mascara1)== 0x00) &&
        ((Tablero[(ultFilaPieza - 1)][((priColPieza - 1) / 8)] & mascara1) == 0x00) &&
        ((Tablero[(ultFilaPieza - 2)][(priColPieza / 8)] & mascara2) == 0x00)){
        // Ingresa 1s
        Tablero[(ultFilaPieza)][((priColPieza - 1) / 8)] |= mascara1;
        Tablero[(ultFilaPieza - 1)][((priColPieza - 1) / 8)] |= mascara1;
        Tablero[(ultFilaPieza - 2)][(priColPieza / 8)] |= mascara2;
        // Ingresa 0s
        mascara1 = (0x80 >> (priColPieza % 8));
        Tablero[(ultFilaPieza)][(priColPieza / 8)] ^= mascara1;

        mascara2 = (0x80 >> ((priColPieza + 1) % 8));
        Tablero[(ultFilaPieza - 1)][((priColPieza + 1) / 8)] ^= mascara2;

        Tablero[(ultFilaPieza - 2)][((priColPieza + 1) / 8)] ^= mascara2;
        // Actualizacion de la variable que referencia a la columna de la pieza
        priColPieza -= 1;
    }
    else {
        fijarPieza = true;
    }
}
void desplazarDerZOrigin(const int &x){
    unsigned char mascara1 = (0x80 >> ((priColPieza + 3) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 2) % 8));

    if((priColPieza + 3) == x*8){
        return;
    }
    else if(((Tablero[(ultFilaPieza)][((priColPieza + 3) / 8)] & mascara1)== 0x00) &&
               ((Tablero[(ultFilaPieza - 1)][((priColPieza + 2) / 8)] & mascara2) == 0x00)){
        // Ingresa 1s
        Tablero[(ultFilaPieza)][((priColPieza + 3) / 8)] |= mascara1;
        Tablero[(ultFilaPieza - 1)][((priColPieza + 2) / 8)] |= mascara2;
        // Ingresa 0s
        mascara1 = (0x80 >> ((priColPieza + 1) % 8));
        Tablero[(ultFilaPieza)][((priColPieza + 1) / 8)] ^= mascara1;

        mascara2 = (0x80 >> (priColPieza % 8));
        Tablero[(ultFilaPieza - 1)][(priColPieza / 8)] ^= mascara2;
        // Actualizacion de la variable que referencia a la columna de la pieza
        priColPieza += 1;
    }
    else {
        fijarPieza = true;
    }
}
void desplazarDerZRot1(const int &x){
    unsigned char mascara1 = (0x80 >> ((priColPieza + 1) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 2) % 8));

    if((priColPieza + 2) == x*8){
        return;
    }
    else if(((Tablero[(ultFilaPieza)][((priColPieza + 1) / 8)] & mascara1)== 0x00) &&
        ((Tablero[(ultFilaPieza - 1)][((priColPieza + 2) / 8)] & mascara2) == 0x00) &&
        ((Tablero[(ultFilaPieza - 2)][((priColPieza + 2) / 8)] & mascara2) == 0x00)){
        // Ingresa 1s
        Tablero[(ultFilaPieza)][((priColPieza + 1) / 8)] |= mascara1;
        Tablero[(ultFilaPieza - 1)][((priColPieza + 2) / 8)] |= mascara2;
        Tablero[(ultFilaPieza - 2)][((priColPieza + 2) / 8)] |= mascara2;
        // Ingresa 0s
        mascara1 = (0x80 >> (priColPieza % 8));
        Tablero[(ultFilaPieza)][(priColPieza / 8)] ^= mascara1;
        Tablero[(ultFilaPieza - 1)][(priColPieza / 8)] ^= mascara1;

        mascara2 = (0x80 >> ((priColPieza + 1) % 8));
        Tablero[(ultFilaPieza - 2)][((priColPieza + 1) / 8)] ^= mascara2;
        // Actualizacion de la variable que referencia a la columna de la pieza
        priColPieza += 1;
    }
    else {
        fijarPieza = true;
    }
}
