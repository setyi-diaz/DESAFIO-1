#ifndef MODPIEZAS_H
#define MODPIEZAS_H

extern bool fijarPieza;

void rota1PiezaS();
void rota2PiezaS();

void bajarPiezaSOrigin(const int &y);
void bajarPiezaSRot1(const int &y);

void moverDerechaPiezaSOrigin(const int &x);
void moverDerechaPiezaSRot1(const int &x);

void moverIzquierdaPiezaSOrigin();
void moverIzquierdaPiezaSRot1();

#endif // MODPIEZAS_H
