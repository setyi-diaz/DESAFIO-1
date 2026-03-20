#ifndef MODPIEZAJ_H
#define MODPIEZAJ_H

extern bool fijarPieza;

void rota1PiezaJ();
void rota2PiezaJ();
void rota3PiezaJ();
void rota4PiezaJ();

void bajarPiezaJOrigin();
void bajarPiezaJRot1();
void bajarPiezaJRot2();
void bajarPiezaJRot3();

void moverDerechaPiezaJOrigin(const int &x);
void moverDerechaPiezaJRot1(const int &x);
void moverDerechaPiezaJRot2(const int &x);
void moverDerechaPiezaJRot3(const int &x);

void moverIzquierdaPiezaJOrigin();
void moverIzquierdaPiezaJRot1();
void moverIzquierdaPiezaJRot2();
void moverIzquierdaPiezaJRot3();

#endif // MODPIEZAJ_H
