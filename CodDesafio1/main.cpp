#include <iostream>

#include "ModTablero.h"
#include "ModPiezaT.h"
#include "ModPiezaZ.h"
#include "ModPiezaS.h"
#include "ModPiezaJ.h"
#include "ModValidaciones.h"

using namespace std;

int main()
{
    int alto;
    int ancho;
    unsigned char accion;
    short int piezaEnJuego;
    short int rotEnJuego = 0;
    char Piezas[4] = {'T','Z','S','J'};
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
            cout<<ultFilaPieza<<endl;
            cout<<priColPieza<<endl;
            cout<<alto<<endl;
            switch (accion) {
            case 'A':
                if(Piezas[piezaEnJuego] == 'T'){
                    if(rotacionPieza[rotEnJuego] == '0'){
                        desplazarIzqTOrigin(ancho);
                    }
                    else if (rotacionPieza[rotEnJuego] == '1'){
                        desplazarIzqTRot1(ancho);
                    }
                    else if (rotacionPieza[rotEnJuego] == '2'){
                        desplazarIzqTRot2(ancho);
                    }
                    else if (rotacionPieza[rotEnJuego] == '3'){
                        desplazarIzqTRot3(ancho);
                    }
                }
                else if(Piezas[piezaEnJuego] == 'Z'){
                    if(rotacionPieza[rotEnJuego] == '0'){
                        desplazarIzqZorigin(ancho);
                    }
                    else if (rotacionPieza[rotEnJuego] == '1'){
                        desplazarIzqZRot1(ancho);
                    }
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
                break;
            case 'S':
                if(ultFilaPieza < alto){

                    cout<<piezaEnJuego<<endl;
                    cout<<Piezas[piezaEnJuego]<<endl;
                    if(Piezas[piezaEnJuego] == 'T'){
                        cout<<"entro\n";

                        if(rotacionPieza[rotEnJuego] == '0'){
                            cout<<"entro\n";
                            bajarPiezaTOrigin(ancho);
                        }
                        else if (rotacionPieza[rotEnJuego] == '1'){
                            bajarPiezaTRot1(ancho);
                        }
                        else if (rotacionPieza[rotEnJuego] == '2'){
                            bajarPiezaTRot2(ancho);
                        }
                        else if (rotacionPieza[rotEnJuego] == '3'){
                            bajarPiezaTRot3(ancho);
                        }
                    }
                    else if(Piezas[piezaEnJuego] == 'Z'){
                        cout<<"entro\n";
                        if(rotacionPieza[rotEnJuego] == '0'){
                            cout<<"entro\n";
                            bajarPiezaZOrigin(ancho);
                        }
                        else if (rotacionPieza[rotEnJuego] == '1'){
                            bajarPiezaZRot1(ancho);
                        }
                    }
                }
                break;
            case 'W':
                if(Piezas[piezaEnJuego] == 'T'){
                    if(rotacionPieza[rotEnJuego] == '0'){
                        rota1PiezaT(ancho);
                        rotEnJuego = '1';
                    }
                    else if (rotacionPieza[rotEnJuego] == '1'){
                        rota2PiezaT(ancho);
                        rotEnJuego = '2';
                    }
                    else if (rotacionPieza[rotEnJuego] == '2'){
                        rota3PiezaT(ancho);
                        rotEnJuego = '3';
                    }
                    else if (rotacionPieza[rotEnJuego] == '3'){
                        rota4PiezaT(ancho);
                        rotEnJuego = '0';
                    }
                }
                else if(Piezas[piezaEnJuego] == 'Z'){
                    if(rotacionPieza[rotEnJuego] == '0'){
                        rota1PiezaS(ancho);
                        rotEnJuego = '1';
                    }
                    else if (rotacionPieza[rotEnJuego] == '1'){
                        rota2PiezaZ(ancho);
                        rotEnJuego = '0';
                    }
                }
                break;
            case 'Q':
                fijarPieza = true;
                break;
            default:
                cout<<"Opcion envalida!!";
                break;
            }
        }while(fijarPieza == false);
        fijarPieza = false;
    }while(accion != 'Q');
    borrarTablero();
    return 0;
}
