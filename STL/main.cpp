#include <iostream>
#include "enrutador.h"

int main()
{
    Enrutador primer("A");
    Enrutador segundo("B");
    Enrutador tercero("C");
    Enrutador cuarto("D");

    primer.agregarNodoCercano(segundo, 4);
    primer.agregarNodoCercano(tercero, 5);

    primer.imprimirNodosCercano();

    primer.agregarNodoCercano(cuarto, 10);
    primer.imprimirNodosCercano();

    return 0;
}
