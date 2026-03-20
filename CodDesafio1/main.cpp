#include <iostream>

#include "ModTablero.h"
#include "ModPiezaT.h"
#include "ModPiezaZ.h"
#include "ModPiezaS.h"
#include "ModValidaciones.h"
#include "ModPiezaCuadrado.h"

using namespace std;

int main()
{
    int alto;
    int ancho;
    unsigned char accion;
    short int piezaEnJuego;
    short int rotEnJuego = 0;
    char Piezas[4] = {'T','Z','C','S'};
    char rotacionPieza[4] = {'0','1','2','3'};

    cout<<"Ingrese el alto del tablero: ";
    cin >> alto;
    cout << "Ingrese el ancho del tablero: ";
    cin >> ancho;
    while(valAnchoTablero(ancho)){
        cout<<"Ingrese un multiplo de 8 para el ancho del tablero: ";
        cin>>ancho;
    }
    cout<<endl;
    ancho /= 8;
    crearTablero(ancho,alto);
    //parte iterativa
    do{
        piezaEnJuego = generarPiezaAlea();
        do{
            mostrarTablero(ancho,alto);
            cout<<"Accion: [A]Izq [D]Der [S]Bajar [W]Rotar [Q]Salir: ";
            cin>>accion;

            switch (accion) {
            case 'A':
                if(Piezas[piezaEnJuego] == 'T'){
                    if(rotacionPieza[rotEnJuego] == '0'){
                        desplazarIzqTOrigin();
                    }
                    else if (rotacionPieza[rotEnJuego] == '1'){
                        desplazarIzqTRot1();
                    }
                    else if (rotacionPieza[rotEnJuego] == '2'){
                        desplazarIzqTRot2();
                    }
                    else if (rotacionPieza[rotEnJuego] == '3'){
                        desplazarIzqTRot3();
                    }
                }
                else if(Piezas[piezaEnJuego] == 'Z'){
                    if(rotacionPieza[rotEnJuego] == '0'){
                        desplazarIzqZorigin();
                    }
                    else if (rotacionPieza[rotEnJuego] == '1'){
                        desplazarIzqZRot1();
                    }
                }
                else if(Piezas[piezaEnJuego] == 'C'){
                    desplazarIzqCuadrado();
                }
                break;
            case 'D':
                    if(Piezas[piezaEnJuego] == 'T'){
                        if(rotacionPieza[rotEnJuego] == '0'){
                            desplazarDerTOrigin(ancho);
                        }
                        else if (rotacionPieza[rotEnJuego] == '1'){
                            desplazarDerTRot1(ancho);
                        }
                        else if (rotacionPieza[rotEnJuego] == '2'){
                            desplazarDerTRot2(ancho);
                        }
                        else if (rotacionPieza[rotEnJuego] == '3'){
                            desplazarDerTRot3(ancho);
                        }
                    }
                    else if(Piezas[piezaEnJuego] == 'Z'){
                        if(rotacionPieza[rotEnJuego] == '0'){
                            desplazarDerZOrigin(ancho);
                        }
                        else if (rotacionPieza[rotEnJuego] == '1'){
                            desplazarDerZRot1(ancho);
                        }
                    }
                    else if(Piezas[piezaEnJuego] == 'C'){
                        desplazarDerCuadrado(ancho);
                    }
                break;
            case 'S':
                    if(Piezas[piezaEnJuego] == 'T'){
                        if(rotacionPieza[rotEnJuego] == '0'){
                            bajarPiezaTOrigin();
                        }
                        else if (rotacionPieza[rotEnJuego] == '1'){
                            bajarPiezaTRot1();
                        }
                        else if (rotacionPieza[rotEnJuego] == '2'){
                            bajarPiezaTRot2();
                        }
                        else if (rotacionPieza[rotEnJuego] == '3'){
                            bajarPiezaTRot3();
                        }
                    }
                    else if(Piezas[piezaEnJuego] == 'Z'){
                        if(rotacionPieza[rotEnJuego] == '0'){
                            bajarPiezaZOrigin();
                        }
                        else if (rotacionPieza[rotEnJuego] == '1'){
                            bajarPiezaZRot1();
                        }
                    }
                    else if(Piezas[piezaEnJuego] == 'C'){
                        bajarPiezaCuadrado();
                    }
                break;
            case 'W':
                if(Piezas[piezaEnJuego] == 'T'){
                    if(rotacionPieza[rotEnJuego] == '0'){
                        rota1PiezaT();
                        rotEnJuego = 1;
                    }
                    else if (rotacionPieza[rotEnJuego] == '1'){
                        rota2PiezaT();
                        rotEnJuego = 2;
                    }
                    else if (rotacionPieza[rotEnJuego] == '2'){
                        rota3PiezaT();
                        rotEnJuego = 3;
                    }
                    else if (rotacionPieza[rotEnJuego] == '3'){
                        rota4PiezaT();
                        rotEnJuego = 0;
                    }
                }
                else if(Piezas[piezaEnJuego] == 'Z'){
                    if(rotacionPieza[rotEnJuego] == '0'){
                        rota1PiezaZ();
                        rotEnJuego = 1;
                    }
                    else if (rotacionPieza[rotEnJuego] == '1'){
                        rota2PiezaZ();
                        rotEnJuego = 0;
                    }
                }
                break;
            case 'Q':
                ultFilaPieza = alto;
                break;
            default:
                cout<<"Opcion envalida!!";
                break;
            }
        }while(fijarPieza == false && (ultFilaPieza + 1) < alto );
        fijarPieza = false;
        rotEnJuego = 0;
        ultFilaPieza = -1;
        priColPieza = ((ancho * 8 ) / 2) - 2;

    }while(accion != 'Q');
    borrarTablero(alto);
    return 0;
}
