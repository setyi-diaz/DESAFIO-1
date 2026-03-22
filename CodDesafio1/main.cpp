#include <iostream>

#include "ModTablero.h"
#include "ModPiezaT.h"
#include "ModPiezaZ.h"
#include "ModPiezaS.h"
#include "ModPiezaJ.h"
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
    char Piezas[5] = {'T','Z','S','J','C'};
    char rotacionPieza[4] = {'0','1','2','3'};

    cout << "Ingrese el alto del tablero: ";
    cin >> alto;
    cout << "Ingrese el ancho del tablero: ";
    cin >> ancho;

    while(valAnchoTablero(ancho)){
        cout << "Ingrese un multiplo de 8 para el ancho del tablero: ";
        cin >> ancho;
    }

    cout << endl;

    ancho /= 8;
    crearTablero(ancho, alto);

    do{
        piezaEnJuego = generarPiezaAlea();
        fijarPieza = false;
        gameOver = false;
        rotEnJuego = 0;
        ultFilaPieza = -1;
        priColPieza = ((ancho * 8) / 2) - 2;

        do{
            mostrarTablero(ancho, alto);
            cout<<ultFilaPieza<<endl;
            cout<<priColPieza<<endl;
            cout << "Accion: [A]Izq [D]Der [S]Bajar [W]Rotar [I]Salir: ";
            cin >> accion;

            bool bloqueaLateralOrigin = (ultFilaPieza == -1 || ultFilaPieza == 0);
            bool bloqueaLateralRotada = (ultFilaPieza == -1 || ultFilaPieza == 0 || ultFilaPieza == 1);
            bool bloqueaRotacion = (ultFilaPieza == -1 || ultFilaPieza == 0 || ultFilaPieza == 1
                                    || (priColPieza + 2) == ancho*8);
            cout << Piezas[piezaEnJuego]<< endl;
            switch (accion) {

            case 'A':
                if(Piezas[piezaEnJuego] == 'T'){
                    if(rotacionPieza[rotEnJuego] == '0'){
                        if(!bloqueaLateralOrigin){
                            desplazarIzqTOrigin();
                        }
                    }
                    else if(rotacionPieza[rotEnJuego] == '1'){
                        if(!bloqueaLateralRotada){
                            desplazarIzqTRot1();
                        }
                    }
                    else if(rotacionPieza[rotEnJuego] == '2'){
                        if(!bloqueaLateralRotada){
                            desplazarIzqTRot2();
                        }
                    }
                    else if(rotacionPieza[rotEnJuego] == '3'){
                        if(!bloqueaLateralRotada){
                            desplazarIzqTRot3();
                        }
                    }
                }
                else if(Piezas[piezaEnJuego] == 'Z'){
                    if(rotacionPieza[rotEnJuego] == '0'){
                        if(!bloqueaLateralOrigin){
                            desplazarIzqZorigin();
                        }
                    }
                    else if(rotacionPieza[rotEnJuego] == '1'){
                        if(!bloqueaLateralRotada){
                            desplazarIzqZRot1();
                        }
                    }
                }
                else if(Piezas[piezaEnJuego] == 'S'){
                    if(rotacionPieza[rotEnJuego] == '0'){
                        if(!bloqueaLateralOrigin){
                            moverIzquierdaPiezaSOrigin();
                        }
                    }
                    else if(rotacionPieza[rotEnJuego] == '1'){
                        if(!bloqueaLateralRotada){
                            moverIzquierdaPiezaSRot1();
                        }
                    }
                }
                else if(Piezas[piezaEnJuego] == 'J'){
                    if(rotacionPieza[rotEnJuego] == '0'){
                        if(!bloqueaLateralOrigin){
                            moverIzquierdaPiezaJOrigin();
                        }
                    }
                    else if(rotacionPieza[rotEnJuego] == '1'){
                        if(!bloqueaLateralRotada){
                            moverIzquierdaPiezaJRot1();
                        }
                    }
                    else if(rotacionPieza[rotEnJuego] == '2'){
                        if(!bloqueaLateralRotada){
                            moverIzquierdaPiezaJRot2();
                        }
                    }
                    else if(rotacionPieza[rotEnJuego] == '3'){
                        if(!bloqueaLateralRotada){
                            moverIzquierdaPiezaJRot3();
                        }
                    }
                }
                else if(Piezas[piezaEnJuego] == 'C'){
                    desplazarIzqCuadrado();
                }
                break;

            case 'D':
                if(Piezas[piezaEnJuego] == 'T'){
                    if(rotacionPieza[rotEnJuego] == '0'){
                        if(!bloqueaLateralOrigin){
                            desplazarDerTOrigin(ancho);
                        }
                    }
                    else if(rotacionPieza[rotEnJuego] == '1'){
                        if(!bloqueaLateralRotada){
                            desplazarDerTRot1(ancho);
                        }
                    }
                    else if(rotacionPieza[rotEnJuego] == '2'){
                        if(!bloqueaLateralRotada){
                            desplazarDerTRot2(ancho);
                        }
                    }
                    else if(rotacionPieza[rotEnJuego] == '3'){
                        if(!bloqueaLateralRotada){
                            desplazarDerTRot3(ancho);
                        }
                    }
                }
                else if(Piezas[piezaEnJuego] == 'Z'){
                    if(rotacionPieza[rotEnJuego] == '0'){
                        if(!bloqueaLateralOrigin){
                            desplazarDerZOrigin(ancho);
                        }
                    }
                    else if(rotacionPieza[rotEnJuego] == '1'){
                        if(!bloqueaLateralRotada){
                            desplazarDerZRot1(ancho);
                        }
                    }
                }
                else if(Piezas[piezaEnJuego] == 'S'){
                    if(rotacionPieza[rotEnJuego] == '0'){
                        if(!bloqueaLateralOrigin){
                            moverDerechaPiezaSOrigin(ancho);
                        }
                    }
                    else if(rotacionPieza[rotEnJuego] == '1'){
                        if(!bloqueaLateralRotada){
                            moverDerechaPiezaSRot1(ancho);
                        }
                    }
                }
                else if(Piezas[piezaEnJuego] == 'J'){
                    if(rotacionPieza[rotEnJuego] == '0'){
                        if(!bloqueaLateralOrigin){
                            moverDerechaPiezaJOrigin(ancho);
                        }
                    }
                    else if(rotacionPieza[rotEnJuego] == '1'){
                        if(!bloqueaLateralRotada){
                            moverDerechaPiezaJRot1(ancho);
                        }
                    }
                    else if(rotacionPieza[rotEnJuego] == '2'){
                        if(!bloqueaLateralRotada){
                            moverDerechaPiezaJRot2(ancho);
                        }
                    }
                    else if(rotacionPieza[rotEnJuego] == '3'){
                        if(!bloqueaLateralRotada){
                            moverDerechaPiezaJRot3(ancho);
                        }
                    }
                }
                else if(Piezas[piezaEnJuego] == 'C'){
                    desplazarDerCuadrado(ancho);
                }
                break;

            case 'S':
                if(ultFilaPieza < alto - 1){
                    if(Piezas[piezaEnJuego] == 'T'){
                        if(rotacionPieza[rotEnJuego] == '0'){
                            bajarPiezaTOrigin(alto);
                        }
                        else if(rotacionPieza[rotEnJuego] == '1'){
                            bajarPiezaTRot1(alto);
                        }
                        else if(rotacionPieza[rotEnJuego] == '2'){
                            bajarPiezaTRot2(alto);
                        }
                        else if(rotacionPieza[rotEnJuego] == '3'){
                            bajarPiezaTRot3(alto);
                        }
                    }
                    else if(Piezas[piezaEnJuego] == 'Z'){
                        if(rotacionPieza[rotEnJuego] == '0'){
                            bajarPiezaZOrigin(alto);
                        }
                        else if(rotacionPieza[rotEnJuego] == '1'){
                            bajarPiezaZRot1(alto);
                        }
                    }
                    else if(Piezas[piezaEnJuego] == 'S'){
                        if(rotacionPieza[rotEnJuego] == '0'){
                            bajarPiezaSOrigin(alto);
                        }
                        else if(rotacionPieza[rotEnJuego] == '1'){
                            bajarPiezaSRot1(alto);
                        }
                    }
                    else if(Piezas[piezaEnJuego] == 'J'){
                        if(rotacionPieza[rotEnJuego] == '0'){
                            bajarPiezaJOrigin(alto);
                        }
                        else if(rotacionPieza[rotEnJuego] == '1'){
                            bajarPiezaJRot1(alto);
                        }
                        else if(rotacionPieza[rotEnJuego] == '2'){
                            bajarPiezaJRot2(alto);
                        }
                        else if(rotacionPieza[rotEnJuego] == '3'){
                            bajarPiezaJRot3(alto);
                        }
                    }
                    else if(Piezas[piezaEnJuego] == 'C'){
                        bajarPiezaCuadrado(alto);
                    }
                }
                else{
                    fijarPieza = true;
                }
                break;

            case 'W':
                if(!bloqueaRotacion){
                    if(Piezas[piezaEnJuego] == 'T'){
                        if(rotEnJuego == 0){
                            rota1PiezaT();
                            rotEnJuego = 1;
                        }
                        else if(rotEnJuego == 1){
                            rota2PiezaT();
                            rotEnJuego = 2;
                        }
                        else if(rotEnJuego == 2){
                            rota3PiezaT();
                            rotEnJuego = 3;
                        }
                        else if(rotEnJuego == 3){
                            rota4PiezaT();
                            rotEnJuego = 0;
                        }
                    }
                    else if(Piezas[piezaEnJuego] == 'Z'){
                        if(rotEnJuego == 0){
                            rota1PiezaZ();
                            rotEnJuego = 1;
                        }
                        else if(rotEnJuego == 1){
                            rota2PiezaZ();
                            rotEnJuego = 0;
                        }
                    }
                    else if(Piezas[piezaEnJuego] == 'S'){
                        if(rotEnJuego == 0){
                            rota1PiezaS();
                            rotEnJuego = 1;
                        }
                        else if(rotEnJuego == 1){
                            rota2PiezaS();
                            rotEnJuego = 0;
                        }
                    }
                    else if(Piezas[piezaEnJuego] == 'J'){
                        if(rotEnJuego == 0){
                            rota1PiezaJ();
                            rotEnJuego = 1;
                        }
                        else if(rotEnJuego == 1){
                            rota2PiezaJ();
                            rotEnJuego = 2;
                        }
                        else if(rotEnJuego == 2){
                            rota3PiezaJ();
                            rotEnJuego = 3;
                        }
                        else if(rotEnJuego == 3){
                            rota4PiezaJ();
                            rotEnJuego = 0;
                        }
                    }
                }
                break;

            case 'I':
                ultFilaPieza = alto;
                break;

            default:
                cout << "Opcion invalida!!\n";
                break;
            }
            if (gameOver == true){
                cout<<"No hay espacio en el tablero para generar la pieza\n";
                cout<<"********************GAME OVER**********************\n\n";
                accion = 'N';
                while(accion == 'N'){
                    cout<<"Para volver a jugar, ingresa: 1\n";
                    cout<<"Para salir del juego, ingresa: 0\n ";
                    cin>>accion;
                    if(accion == '0'){
                        fijarPieza = true;
                        accion = 'Q';
                    }
                    else if(accion == '1'){
                        reiniciarTablero(ancho,alto);
                        fijarPieza = true;
                    }
                    else{
                        cout<<"Opcion invalida\n";
                        accion = 'N';
                    }
                }
            }
            if(accion != 'I' && ultFilaPieza != -1 && fijarPieza == true){
                cout<<"se cumplio if para valEliminarFila\n";
                for(short int cont = 0; cont < 4; cont++){
                    int f = valEliminarFila(ancho);
                    if(f != -1){
                        cout<<"se ejecuto eliminar fila\n";
                        desplazarFilas(ancho, f);
                    }
                }
            }

        }while(fijarPieza == false && (ultFilaPieza + 1) < alto);
        cout<<"salio del while 1\n";
    }while(accion != 'I');

    borrarTablero(alto);
    return 0;
}
