#include <iostream>

#include "ModPiezaT.h"
#include "ModTablero.h"  // para acceder a las dimensiones del tablero, fila y columna de referencia a la pieza
#include "ModValidaciones.h"

bool fijarPieza = false;

void rota1PiezaT(const int &x){
    unsigned char mascara = (priColPieza + 1) % 8;
    // Ingresa 1s
    Tablero[((ultFilaPieza - 2) * x) + ((priColPieza + 1) / 8)] |= mascara;
    // Ingresa 0s
    mascara = (0x80 >> (priColPieza + 2) % 8);
    Tablero[((ultFilaPieza - 1) * x) + ((priColPieza + 2)/8)] ^= mascara;
}
void rota2PiezaT(const int &x){
    unsigned char mascara1 = (0x80 >> (priColPieza % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 2) % 8));

    if(((Tablero[(ultFilaPieza * x) + (priColPieza / 8)] & mascara1)==mascara1) &&
        ((Tablero[(ultFilaPieza * x) + ((priColPieza + 2) / 8)] & mascara2)==mascara2)){
        // Ingresa 1s
        Tablero[(ultFilaPieza * x) + (priColPieza / 8)] |= mascara1;
        Tablero[(ultFilaPieza * x) + ((priColPieza + 2) / 8)] |= mascara2;
        // Ingresa 0s
        Tablero[((ultFilaPieza - 1) * x) + (priColPieza / 8)] ^= mascara1;

        mascara2 = (0x80 >> ((priColPieza + 1) % 8));
        Tablero[((ultFilaPieza - 2) * x) + ((priColPieza + 1) / 8)] ^= mascara2;
    }
}
void rota3PiezaT(const int &x){
    unsigned char mascara = (0x80 >> (priColPieza % 8));

    if(((Tablero[((ultFilaPieza - 1) * x) + (priColPieza / 8)] & mascara) == mascara) &&
        ((Tablero[((ultFilaPieza - 2) * x) + (priColPieza / 8)] & mascara) == mascara)){
        // Ingresa 1s
        Tablero[((ultFilaPieza - 1) * x) + (priColPieza / 8)] |= mascara;
        Tablero[((ultFilaPieza - 1) * x) + (priColPieza / 8)] |= mascara;
        // Ingresa 0s
        mascara = (0x80 >> ((priColPieza + 1) % 8));
        Tablero[(ultFilaPieza * x) + ((priColPieza + 1) / 8)] ^= mascara;

        mascara = (0x80 >> ((priColPieza + 2) % 8));
        Tablero[(ultFilaPieza * x) + ((priColPieza + 2) / 8)] ^= mascara;
    }
}
void rota4PiezaT(const int &x){
    int filaAux1 = ultFilaPieza;
    int filaAux2 = ultFilaPieza - 1;
    int colAux1 = (priColPieza + 1) / 8;
    int colAux2 = (priColPieza + 2) / 8;
    unsigned char mascara1 = (0x80 >> ((priColPieza + 1) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 2) % 8));

    if(((Tablero[(filaAux1 * x) + colAux1] & mascara1)== mascara1) &&
        ((Tablero[(filaAux2 * x) + colAux2] & mascara2) == mascara2)){
        // Ingresa 1s
        Tablero[(filaAux1 * x) + colAux1] |= mascara1;
        Tablero[(filaAux1 * x) + colAux2] |= mascara2;
        // Ingresa 0s
        filaAux1 = ultFilaPieza;
        colAux1 = priColPieza / 8;
        mascara1 = (0x80 >> (priColPieza % 8));
        Tablero[(filaAux1 * x) + colAux1] ^= mascara1;

        filaAux2 = ultFilaPieza - 2;
        Tablero[(filaAux2 * x) + colAux1] ^= mascara1;
    }
}

void bajarPiezaTOrigin(const int &x){
    unsigned char mascara1 = (0x80 >> (priColPieza % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 1) % 8));
    unsigned char mascara3 = (0x80 >> ((priColPieza + 2) % 8));

    if(valBajarPiezaTOrigin(x) == '1'){
        Tablero[((ultFilaPieza - 1) * x) + ((priColPieza + 1) / 8)] |= mascara1;
        // Actualizacion de la variable que refencia a la fila de la pieza
        ultFilaPieza += 1;
    }
    else if(valBajarPiezaTOrigin(x) == '2'){
        // Ingresa 1s
        Tablero[(ultFilaPieza * x) + (priColPieza / 8)] |= mascara1;
        Tablero[((ultFilaPieza + 1) * x) + ((priColPieza + 1) / 8)] |= mascara2;
        Tablero[(ultFilaPieza * x) + ((priColPieza + 2) / 8)] |= mascara3;
        // Actualizacion de la variable que refencia a la fila de la pieza
        ultFilaPieza += 1;
    }
    else if(valBajarPiezaTOrigin(x) == '3'){
        // Ingresa 1s
        Tablero[(ultFilaPieza * x) + (priColPieza / 8)] |= mascara1;
        Tablero[((ultFilaPieza + 1) * x) + ((priColPieza + 1) / 8)] |= mascara2;
        Tablero[(ultFilaPieza * x) + ((priColPieza + 2) / 8)] |= mascara3;
        // Ingresa 0s
        Tablero[((ultFilaPieza - 1) * x) + (priColPieza / 8)] ^= mascara1;
        Tablero[((ultFilaPieza - 1) * x) + ((priColPieza + 1) / 8)] ^= mascara2;
        Tablero[((ultFilaPieza - 1) * x) + ((priColPieza + 2) / 8)] ^= mascara3;
        // Actualizacion de la variable que refencia a la fila de la pieza
        ultFilaPieza += 1;
    }
    else if (valBajarPiezaTOrigin(x) == '0'){
        fijarPieza = true;
    }
}
void bajarPiezaTRot1(const int &x){
    int filaAux1 = ultFilaPieza;
    int filaAux2 = ultFilaPieza + 1;
    int colAux1 = priColPieza / 8;
    int colAux2 = (priColPieza + 1) / 8;
    unsigned char mascara1 = (0x80 >> (priColPieza % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 1) % 8));

    if(((Tablero[(filaAux1 * x) + colAux1] & mascara1)== mascara1) &&
        ((Tablero[(filaAux2 * x) + colAux2] & mascara2) == mascara2)){
        // Ingresa 1s
        Tablero[(filaAux1 * x) + colAux1] |= mascara1;
        Tablero[(filaAux2 * x) + colAux2] |= mascara2;
        // Ingresa 0s
        filaAux1 = ultFilaPieza - 1;
        Tablero[(filaAux1 * x) + colAux1] ^= mascara1;

        filaAux2 = ultFilaPieza - 2;
        Tablero[(filaAux2 * x) + colAux2] |= mascara2;
        // Actualizacion de la variable que refencia a la fila de la pieza
        ultFilaPieza += 1;
    }
    else fijarPieza = true;
}
void bajarPiezaTRot2(const int &x){
    int filaAux = ultFilaPieza + 1;
    int colAux1 = priColPieza / 8;
    int colAux2 = (priColPieza + 1) / 8;
    int colAux3 = (priColPieza + 2) / 8;
    unsigned char mascara1 = (0x80 >> (priColPieza % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 1) % 8));
    unsigned char mascara3 = (0x80 >> ((priColPieza + 2) % 8));

    if(((Tablero[(filaAux * x) + colAux1] & mascara1)== mascara1) &&
        ((Tablero[(filaAux * x) + colAux2] & mascara2) == mascara2) &&
        ((Tablero[(filaAux * x) + colAux3] & mascara3)== mascara3)){
        // Ingresa 1s
        Tablero[(filaAux * x) + colAux1] |= mascara1;
        Tablero[(filaAux * x) + colAux2] |= mascara2;
        Tablero[(filaAux * x) + colAux3] |= mascara3;
        // Ingresa 0s
        filaAux = ultFilaPieza;
        Tablero[(filaAux * x) + colAux1] ^= mascara1;

        filaAux = ultFilaPieza - 1;
        Tablero[(filaAux * x) + colAux2] ^= mascara2;

        filaAux = ultFilaPieza;
        Tablero[(filaAux * x) + colAux3] ^= mascara3;
        // Actualizacion de la variable que refencia a la fila de la pieza
        ultFilaPieza += 1;
    }
    else fijarPieza = true;
}
void bajarPiezaTRot3(const int &x){
    int filaAux1 = ultFilaPieza + 1;
    int filaAux2 = ultFilaPieza;
    int colAux1 = priColPieza / 8;
    int colAux2 = (priColPieza + 1) / 8;
    unsigned char mascara1 = (0x80 >> (priColPieza % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 1) % 8));

    if(((Tablero[(filaAux1 * x) + colAux1] & mascara1)== mascara1) &&
        ((Tablero[(filaAux2 * x) + colAux2] & mascara2) == mascara2)){
        // Ingresa 1s
        Tablero[(filaAux1 * x) + colAux1] |= mascara1;
        Tablero[(filaAux2 * x) + colAux2] |= mascara2;
        // Ingresa 0s
        filaAux1 = ultFilaPieza - 2;
        Tablero[(filaAux1 * x) + colAux1] ^= mascara1;

        filaAux2 = ultFilaPieza - 1;
        Tablero[(filaAux2 * x) + colAux2] ^= mascara2;
        // Actualizacion de la variable que refencia a la fila de la pieza
        ultFilaPieza += 1;
    }
    else fijarPieza = true;
}
void desplazarIzqTOrigin(const int &x){
    int filaAux1 = ultFilaPieza;
    int filaAux2 = ultFilaPieza - 1;
    int colAux1 = priColPieza / 8;
    int colAux2 = (priColPieza - 1) / 8;
    unsigned char mascara1 = (0x80 >> (priColPieza % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza - 1) % 8));

    if(((Tablero[(filaAux1 * x) + colAux1] & mascara1)== mascara1) &&
        ((Tablero[(filaAux2 * x) + colAux2] & mascara2) == mascara2)){
        // Ingresa 1s
        Tablero[(filaAux1 * x) + colAux1] |= mascara1;
        Tablero[(filaAux2 * x) + colAux2] |= mascara2;
        // Ingresa 0s
        colAux1 = (priColPieza + 1) / 8;
        mascara1 = (0x80 >> ((priColPieza + 1) % 8));
        Tablero[(filaAux1 * x) + colAux1] ^= mascara1;

        colAux2 = (priColPieza + 2) / 8;
        mascara2 = (0x80 >> ((priColPieza + 2) % 8));
        Tablero[(filaAux2 * x) + colAux2] ^= mascara2;
        // Actualizacion de la variable que referencia a la columna de la pieza
        priColPieza -= 1;
    }
}
void desplazarIzqTRot1(const int &x){
    int filaAux1 = ultFilaPieza;
    int filaAux2 = ultFilaPieza - 1;
    int filaAux3 = ultFilaPieza - 2;
    int colAux1 = priColPieza / 8;
    int colAux2 = (priColPieza - 1) / 8;
    unsigned char mascara1 = (0x80 >> (priColPieza % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza - 1) % 8));

    if(((Tablero[(filaAux1 * x) + colAux1] & mascara1)== mascara1) &&
        ((Tablero[(filaAux2 * x) + colAux2] & mascara2) == mascara2) &&
        ((Tablero[(filaAux3 * x) + colAux1] & mascara1)== mascara1)){
        // Ingresa 1s
        Tablero[(filaAux1 * x) + colAux1] |= mascara1;
        Tablero[(filaAux2 * x) + colAux2] |= mascara2;
        Tablero[(filaAux3 * x) + colAux1] |= mascara1;
        // Ingresa 0s
        colAux1 = (priColPieza + 1) / 8;
        mascara1 = (0x80 >> ((priColPieza + 1) % 8));
        Tablero[(filaAux1 * x) + colAux1] ^= mascara1;
        Tablero[(filaAux2 * x) + colAux1] ^= mascara1;
        Tablero[(filaAux3 * x) + colAux1] ^= mascara1;
        // Actualizacion de la variable que referencia a la columna de la pieza
        priColPieza -= 1;
    }
}
void desplazarIzqTRot2(const int &x){
    int filaAux1 = ultFilaPieza;
    int filaAux2 = ultFilaPieza - 1;
    int colAux1 = (priColPieza - 1) / 8;
    int colAux2 = priColPieza / 8;
    unsigned char mascara1 = (0x80 >> ((priColPieza - 1) % 8));
    unsigned char mascara2 = (0x80 >> (priColPieza % 8));

    if(((Tablero[(filaAux1 * x) + colAux1] & mascara1)== mascara1) &&
        ((Tablero[(filaAux2 * x) + colAux2] & mascara2) == mascara2)){
        // Ingresa 1s
        Tablero[(filaAux1 * x) + colAux1] |= mascara1;
        Tablero[(filaAux2 * x) + colAux2] |= mascara2;
        // Ingresa 0s
        colAux1 = (priColPieza + 2) / 8;
        mascara1 = (0x80 >> ((priColPieza + 2) % 8));
        Tablero[(filaAux1 * x) + colAux1] ^= mascara1;

        colAux2 = (priColPieza + 1) / 8;
        mascara2 = (0x80 >> ((priColPieza + 1) % 8));
        Tablero[(filaAux2 * x) + colAux2] ^= mascara2;
        // Actualizacion de la variable que referencia a la columna de la pieza
        priColPieza -= 1;
    }
}
void desplazarIzqTRot3(const int &x){
    int filaAux1 = ultFilaPieza;
    int filaAux2 = ultFilaPieza - 1;
    int filaAux3 = ultFilaPieza - 2;
    int colAux1 = (priColPieza - 1) / 8;
    unsigned char mascara1 = (0x80 >> ((priColPieza - 1) % 8));

    if(((Tablero[(filaAux1 * x) + colAux1] & mascara1)== mascara1) &&
        ((Tablero[(filaAux2 * x) + colAux1] & mascara1) == mascara1) &&
        ((Tablero[(filaAux3 * x) + colAux1] & mascara1)== mascara1)){
        // Ingresa 1s
        Tablero[(filaAux1 * x) + colAux1] |= mascara1;
        Tablero[(filaAux2 * x) + colAux1] |= mascara1;
        Tablero[(filaAux3 * x) + colAux1] |= mascara1;
        // Ingresa 0s
        colAux1 = priColPieza / 8;
        mascara1 = (0x80 >> (priColPieza % 8));
        Tablero[(filaAux1 * x) + colAux1] ^= mascara1;

        colAux1 = (priColPieza + 1) / 8;
        mascara1 = (0x80 >> ((priColPieza + 1) % 8));
        Tablero[(filaAux2 * x) + colAux1] ^= mascara1;

        colAux1 = priColPieza / 8;
        mascara1 = (0x80 >> (priColPieza % 8));
        Tablero[(filaAux3 * x) + colAux1] ^= mascara1;
        // Actualizacion de la variable que referencia a la columna de la pieza
        priColPieza -= 1;
    }
}
void desplazarDerTOrigin(const int &x){
    int filaAux1 = ultFilaPieza;
    int filaAux2 = ultFilaPieza - 1;
    int colAux1 = (priColPieza + 2) / 8;
    int colAux2 = (priColPieza + 3) / 8;
    unsigned char mascara1 = (0x80 >> ((priColPieza + 2) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 3) % 8));

    if(((Tablero[(filaAux1 * x) + colAux1] & mascara1)== mascara1) &&
        ((Tablero[(filaAux2 * x) + colAux2] & mascara2) == mascara2)){
        // Ingresa 1s
        Tablero[(filaAux1 * x) + colAux1] |= mascara1;
        Tablero[(filaAux2 * x) + colAux2] |= mascara2;
        // Ingresa 0s
        colAux1 = (priColPieza + 1) / 8;
        mascara1 = (0x80 >> ((priColPieza + 1) % 8));
        Tablero[(filaAux1 * x) + colAux1] ^= mascara1;

        colAux2 = priColPieza / 8;
        mascara2 = (0x80 >> (priColPieza % 8));
        Tablero[(filaAux2 * x) + colAux2] ^= mascara2;
        // Actualizacion de la variable que referencia a la columna de la pieza
        priColPieza += 1;
    }
}
void desplazarDerTRot1(const int &x){
    int filaAux1 = ultFilaPieza;
    int filaAux2 = ultFilaPieza - 1;
    int filaAux3 = ultFilaPieza - 2;
    int colAux1 = (priColPieza + 2) / 8;
    unsigned char mascara1 = (0x80 >> ((priColPieza + 2) % 8));

    if(((Tablero[(filaAux1 * x) + colAux1] & mascara1)== mascara1) &&
        ((Tablero[(filaAux2 * x) + colAux1] & mascara1) == mascara1) &&
        ((Tablero[(filaAux3 * x) + colAux1] & mascara1)== mascara1)){
        // Ingresa 1s
        Tablero[(filaAux1 * x) + colAux1] |= mascara1;
        Tablero[(filaAux2 * x) + colAux1] |= mascara1;
        Tablero[(filaAux3 * x) + colAux1] |= mascara1;
        // Ingresa 0s
        colAux1 = (priColPieza + 1) / 8;
        mascara1 = (0x80 >> ((priColPieza + 1) % 8));
        Tablero[(filaAux1 * x) + colAux1] ^= mascara1;

        colAux1 = priColPieza / 8;
        mascara1 = (0x80 >> (priColPieza % 8));
        Tablero[(filaAux2 * x) + colAux1] ^= mascara1;

        colAux1 = (priColPieza + 1) / 8;
        mascara1 = (0x80 >> ((priColPieza + 1) % 8));
        Tablero[(filaAux3 * x) + colAux1] ^= mascara1;
        // Actualizacion de la variable que referencia a la columna de la pieza
        priColPieza += 1;
    }
}
void desplazarDerTRot2(const int &x){
    int filaAux1 = ultFilaPieza;
    int filaAux2 = ultFilaPieza - 1;
    int colAux1 = (priColPieza + 3) / 8;
    int colAux2 = (priColPieza + 2) / 8;
    unsigned char mascara1 = (0x80 >> ((priColPieza + 3) % 8));
    unsigned char mascara2 = (0x80 >> ((priColPieza + 2) % 8));

    if(((Tablero[(filaAux1 * x) + colAux1] & mascara1)== mascara1) &&
        ((Tablero[(filaAux2 * x) + colAux2] & mascara2) == mascara2)){
        // Ingresa 1s
        Tablero[(filaAux1 * x) + colAux1] |= mascara1;
        Tablero[(filaAux2 * x) + colAux2] |= mascara2;
        // Ingresa 0s
        colAux1 = priColPieza/ 8;
        mascara1 = (0x80 >> (priColPieza % 8));
        Tablero[(filaAux1 * x) + colAux1] ^= mascara1;

        colAux2 = (priColPieza + 1) / 8;
        mascara2 = (0x80 >> ((priColPieza + 1) % 8));
        Tablero[(filaAux2 * x) + colAux2] ^= mascara2;
        // Actualizacion de la variable que referencia a la columna de la pieza
        priColPieza += 1;
    }
}
void desplazarDerTRot3(const int &x){
    int filaAux1 = ultFilaPieza;
    int filaAux2 = ultFilaPieza - 1;
    int filaAux3 = ultFilaPieza - 2;
    int colAux1 = (priColPieza + 1) / 8;
    unsigned char mascara1 = (0x80 >> ((priColPieza + 1) % 8));
    int colAux2 = (priColPieza + 2)/ 8;
    unsigned char mascara2 = (0x80 >> ((priColPieza + 2) % 8));

    if(((Tablero[(filaAux1 * x) + colAux1] & mascara1)== mascara1) &&
        ((Tablero[(filaAux2 * x) + colAux2] & mascara2) == mascara2) &&
        ((Tablero[(filaAux3 * x) + colAux1] & mascara1)== mascara1)){
        // Ingresa 1s
        Tablero[(filaAux1 * x) + colAux1] |= mascara1;
        Tablero[(filaAux2 * x) + colAux2] |= mascara2;
        Tablero[(filaAux3 * x) + colAux1] |= mascara1;
        // Ingresa 0s
        colAux1 = priColPieza / 8;
        mascara1 = (0x80 >> (priColPieza % 8));

        Tablero[(filaAux1 * x) + colAux1] ^= mascara1;
        Tablero[(filaAux2 * x) + colAux1] ^= mascara1;
        Tablero[(filaAux3 * x) + colAux1] ^= mascara1;
        // Actualizacion de la variable que referencia a la columna de la pieza
        priColPieza += 1;
    }
}


