#include "ModPiezaZ.h"
#include "ModTablero.h"  // para acceder a las dimensiones del tablero, fila y columna de referencia a la pieza
#include "ModValidaciones.h"

#include <iostream>

void rota1PiezaZ(const int &x){
    unsigned char mascara1 = (0x80 >> (priColPieza % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 1) % 8));

    if(((Tablero[(ultFilaPieza * x) + (priColPieza / 8)] & mascara1)== mascara1) &&
        ((Tablero[((ultFilaPieza - 2) * x) + ((priColPieza + 1) / 8)] & mascara2) == mascara2)){
        // Ingresa 1s
        Tablero[(ultFilaPieza * x) + (priColPieza / 8)] |= mascara1;
        Tablero[(ultFilaPieza * x) + ((priColPieza + 1) / 8)] |= mascara2;
        // Ingresa 0s
        mascara1 = (0x80 >> ((priColPieza + 2) % 8));
        Tablero[(ultFilaPieza * x) + ((priColPieza + 2) / 8)] ^= mascara1;

        mascara2 = (0x80 >> ((priColPieza + 3) % 8));
        Tablero[(ultFilaPieza * x) + ((priColPieza + 3) / 8)] |= mascara2;
    }
}
void rota2PiezaZ(const int &x){
    unsigned char mascara1 = (0x80 >> ((priColPieza + 2) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 3) % 8));

    if(((Tablero[(ultFilaPieza * x) + ((priColPieza + 2) / 8)] & mascara1)== mascara1) &&
        ((Tablero[(ultFilaPieza * x) + ((priColPieza + 3) / 8)] & mascara2) == mascara2)){
        // Ingresa 1s
        Tablero[(ultFilaPieza * x) + ((priColPieza + 2) / 8)] |= mascara1;
        Tablero[(ultFilaPieza * x) + ((priColPieza + 3) / 8)] |= mascara2;
        // Ingresa 0s
        mascara1 = (0x80 >> (priColPieza % 8));
        Tablero[(ultFilaPieza * x) + (priColPieza/ 8)] ^= mascara1;

        mascara2 = (0x80 >> ((priColPieza + 1) % 8));
        Tablero[((ultFilaPieza - 2) * x) + ((priColPieza + 1) / 8)] ^= mascara2;
    }
}
void bajarPiezaZOrigin(const int &x){
    unsigned char mascara1 = (0x80 >> (priColPieza % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 1) % 8));
    unsigned char mascara3 = (0x80 >> ((priColPieza + 2) % 8));

    if(valBajarPiezaTOrigin(x) == '1'){
        // Ingresa 1s
        Tablero[((ultFilaPieza + 1) * x) + ((priColPieza + 1) / 8)] |= mascara2;
        Tablero[((ultFilaPieza + 1) * x) + ((priColPieza + 2) / 8)] |= mascara3;
        // Actualizacion de la variable que refencia a la fila de la pieza
        ultFilaPieza += 1;
    }
    else if(valBajarPiezaTOrigin(x) == '2'){
        // Ingresa 1s
        Tablero[(ultFilaPieza * x) + (priColPieza / 8)] |= mascara1;
        Tablero[((ultFilaPieza + 1) * x) + ((priColPieza + 1) / 8)] |= mascara2;
        Tablero[((ultFilaPieza + 1) * x) + ((priColPieza + 2) / 8)] |= mascara3;
        // Actualizacion de la variable que refencia a la fila de la pieza
        ultFilaPieza += 1;
    }
    else if(valBajarPiezaTOrigin(x) == '3'){
        // Ingresa 1s
        Tablero[(ultFilaPieza * x) + (priColPieza / 8)] |= mascara1;
        Tablero[((ultFilaPieza + 1) * x) + ((priColPieza + 1) / 8)] |= mascara2;
        Tablero[((ultFilaPieza + 1) * x) + ((priColPieza + 2) / 8)] |= mascara3;
        // Ingresa 0s
        Tablero[((ultFilaPieza - 1) * x) + (priColPieza / 8)] ^= mascara1;
        Tablero[((ultFilaPieza - 1) * x) + ((priColPieza + 1) / 8)] ^= mascara2;
        Tablero[(ultFilaPieza * x) + ((priColPieza + 2) / 8)] ^= mascara3;
        // Actualizacion de la variable que refencia a la fila de la pieza
        ultFilaPieza += 1;
    }
    else if (valBajarPiezaTOrigin(x) == '0'){
        fijarPieza = true;
    }
}
void bajarPiezaZRot1(const int &x){
    unsigned char mascara1 = (0x80 >> (priColPieza % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 1) % 8));

    if(((Tablero[((ultFilaPieza + 1) * x) + priColPieza / 8] & mascara1)== mascara1) &&
        ((Tablero[(ultFilaPieza * x) + ((priColPieza + 1) / 8)] & mascara2) == mascara2)){
        // Ingresa 1s
        Tablero[((ultFilaPieza + 1) * x) + priColPieza / 8] |= mascara1;
        Tablero[(ultFilaPieza * x) + ((priColPieza + 1) / 8)] |= mascara2;
        // Ingresa 0s
        Tablero[((ultFilaPieza - 1) * x) + priColPieza / 8] ^= mascara1;

        Tablero[((ultFilaPieza - 2) * x) + ((priColPieza + 1) / 8)] ^= mascara2;
        // Actualizacion de la variable que refencia a la fila de la pieza
        ultFilaPieza += 1;
    }
    else fijarPieza = true;
}
void desplazarIzqZorigin(const int &x){
    unsigned char mascara1 = (0x80 >> (priColPieza % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza - 1) % 8));

    if(((Tablero[(ultFilaPieza * x) + (priColPieza / 8)] & mascara1)== mascara1) &&
        ((Tablero[((ultFilaPieza - 1) * x) + ((priColPieza - 1) / 8)] & mascara2) == mascara2)){
        // Ingresa 1s
        Tablero[(ultFilaPieza * x) + (priColPieza / 8)] |= mascara1;
        Tablero[((ultFilaPieza - 1) * x) + ((priColPieza - 1) / 8)] |= mascara2;
        // Ingresa 0s
        mascara1 = (0x80 >> ((priColPieza + 2) % 8));
        Tablero[(ultFilaPieza * x) + ((priColPieza + 2) / 8)] ^= mascara1;

        mascara2 = (0x80 >> ((priColPieza + 1) % 8));
        Tablero[((ultFilaPieza - 1) * x) + ((priColPieza + 1) / 8)] ^= mascara2;
        // Actualizacion de la variable que referencia a la columna de la pieza
        priColPieza -= 1;
    }
}
void desplazarIzqZRot1(const int &x){
    unsigned char mascara1 = (0x80 >> ((priColPieza - 1) % 8));
    unsigned char mascara2 = (0x80 >> (priColPieza % 8));

    if(((Tablero[(ultFilaPieza * x) + ((priColPieza - 1) / 8)] & mascara1)== mascara1) &&
        ((Tablero[((ultFilaPieza - 1) * x) + ((priColPieza - 1) / 8)] & mascara1) == mascara1) &&
        ((Tablero[((ultFilaPieza - 2) * x) + (priColPieza / 8)] & mascara2) == mascara2)){
        // Ingresa 1s
        Tablero[(ultFilaPieza * x) + ((priColPieza - 1) / 8)] |= mascara1;
        Tablero[((ultFilaPieza - 1) * x) + ((priColPieza - 1) / 8)] |= mascara1;
        Tablero[((ultFilaPieza - 2) * x) + (priColPieza / 8)] |= mascara2;
        // Ingresa 0s
        mascara1 = (0x80 >> (priColPieza % 8));
        Tablero[(ultFilaPieza * x) + (priColPieza / 8)] ^= mascara1;

        mascara2 = (0x80 >> ((priColPieza + 1) % 8));
        Tablero[((ultFilaPieza - 1) * x) + ((priColPieza + 1) / 8)] ^= mascara2;

        Tablero[((ultFilaPieza - 2) * x) + ((priColPieza + 1) / 8)] ^= mascara2;
        // Actualizacion de la variable que referencia a la columna de la pieza
        priColPieza -= 1;
    }
}
void desplazarDerZOrigin(const int &x){
    unsigned char mascara1 = (0x80 >> ((priColPieza + 3) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 2) % 8));

    if(((Tablero[(ultFilaPieza * x) + ((priColPieza + 3) / 8)] & mascara1)== mascara1) &&
        ((Tablero[(ultFilaPieza - 1 * x) + ((priColPieza + 2) / 8)] & mascara2) == mascara2)){
        // Ingresa 1s
        Tablero[(ultFilaPieza * x) + ((priColPieza + 3) / 8)] |= mascara1;
        Tablero[(ultFilaPieza - 1 * x) + ((priColPieza + 2) / 8)] |= mascara2;
        // Ingresa 0s
        mascara1 = (0x80 >> ((priColPieza + 1) % 8));
        Tablero[(ultFilaPieza * x) + ((priColPieza + 1) / 8)] ^= mascara1;

        mascara2 = (0x80 >> (priColPieza % 8));
        Tablero[(ultFilaPieza - 1 * x) + (priColPieza / 8)] ^= mascara2;
        // Actualizacion de la variable que referencia a la columna de la pieza
        priColPieza += 1;
    }
}
void desplazarDerZRot1(const int &x){
    unsigned char mascara1 = (0x80 >> ((priColPieza + 1) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 2) % 8));

    if(((Tablero[(ultFilaPieza * x) + ((priColPieza + 1) / 8)] & mascara1)== mascara1) &&
        ((Tablero[((ultFilaPieza - 1) * x) + ((priColPieza + 2) / 8)] & mascara1) == mascara2) &&
        ((Tablero[((ultFilaPieza - 2) * x) + ((priColPieza + 2) / 8)] & mascara2) == mascara2)){
        // Ingresa 1s
        Tablero[(ultFilaPieza * x) + ((priColPieza + 1) / 8)] |= mascara1;
        Tablero[((ultFilaPieza - 1) * x) + ((priColPieza + 2) / 8)] |= mascara2;
        Tablero[((ultFilaPieza - 2) * x) + ((priColPieza + 2) / 8)] |= mascara2;
        // Ingresa 0s
        mascara1 = (0x80 >> (priColPieza % 8));
        Tablero[(ultFilaPieza * x) + (priColPieza / 8)] ^= mascara1;
        Tablero[((ultFilaPieza - 1) * x) + (priColPieza / 8)] ^= mascara1;

        mascara2 = (0x80 >> ((priColPieza + 1) % 8));
        Tablero[((ultFilaPieza - 2) * x) + ((priColPieza + 1) / 8)] ^= mascara2;
        // Actualizacion de la variable que referencia a la columna de la pieza
        priColPieza += 1;
    }
}











