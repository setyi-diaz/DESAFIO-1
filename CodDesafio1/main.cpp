#include <iostream>

#include "ModPiezaT.h"
#include "ModTablero.h"
#include "ModPiezaZ.h"

using namespace std;

int main()
{

    delete[] Tablero;  //investigar si se puede liberar desde la region static!!

    return 0;
}
