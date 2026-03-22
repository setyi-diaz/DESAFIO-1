#ifndef MODPIEZAJ_H
#define MODPIEZAJ_H

extern bool fijarPieza;

bool rota1PiezaJ();
void rota2PiezaJ();
void rota3PiezaJ();
void rota4PiezaJ();

void bajarPiezaJOrigin(const int &y);
void bajarPiezaJRot1(const int &y);
void bajarPiezaJRot2(const int &y);
void bajarPiezaJRot3(const int &y);

void moverDerechaPiezaJOrigin(const int &x);
void moverDerechaPiezaJRot1(const int &x);
void moverDerechaPiezaJRot2(const int &x);
void moverDerechaPiezaJRot3(const int &x);

void moverIzquierdaPiezaJOrigin();
void moverIzquierdaPiezaJRot1();
void moverIzquierdaPiezaJRot2();
void moverIzquierdaPiezaJRot3();

#endif // MODPIEZAJ_H
