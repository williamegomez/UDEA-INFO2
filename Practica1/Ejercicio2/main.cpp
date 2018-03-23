#include <iostream>

using namespace std;

/*  Función main
 * Se pide un numero y se dice si es impar
 * Ejemplo:
 * Escriba un numero: 4
 * El numero es par
*/
int main()
{
    int numero;
    cout << "Escriba un numero: ";
    cin >> numero;  // Se pide numero por consola

    cout << "El numero que escribio es: " << numero<< endl;

    if(numero%2==0){  //Se mira si el residuo de divirlo por dos es cero
        cout << "El numero es par" << endl;
    }
    else{
        cout << "El numero es impar" << endl;
    }
}
