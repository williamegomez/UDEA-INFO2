#include <fstream>
#include <iostream>
#include <exception>
using namespace std;

int main()
{

    //Ejemplo de escritura

    char str[] = "Hola";
    ofstream escritura;

    escritura.open("datos.txt");

    //escritura.open("datos.txt", ios::app);

    //escritura.open("datos.txt", ios::trunc);

    if(!escritura.fail()){
        escritura << "Hola Mundo\n";

        escritura.write("linea",3);

        escritura.write(str,3);

        escritura.put('5');

        escritura.seekp(2,ios::beg);
        escritura << "L";
    }

    escritura.close();


    //Ejemplo de lectura

    ifstream lectura;

    lectura.open("datos.txt");

    string line;
    char character;
    char array[100];

    if(!lectura.fail()){
        getline(lectura,line);

        lectura.seekg(3,ios::beg);
        character = lectura.get();

        cout << line << endl;
        cout << character << endl;


        lectura.seekg(0,ios::beg);
        lectura.getline(array,100); //Diferente propio de ifstream
        cout << lectura.gcount() << " characters read: " << array << '\n';
    }

    lectura.close();


    // Ejemplo archivo binario
    // sha256sum

    ofstream escritura2("imagencopia.png",ios::binary| ios::trunc);
    int n,indice;

    cout << "Ingrese tamaño del bloque:" << endl;
    cin >> n;

    ifstream lectura2("imagen.png", ios::binary ); // escritura a leer en binario

    if(!lectura2.fail()){
        lectura2.seekg(0,ios::end); //Ubicarnos en el final del escritura

        int final = lectura2.tellg(); //Cual es el final?
        cout << "El tamaño del escritura en bytes es: " << final << endl;

        lectura2.seekg(0,ios::beg); //Nos volvemos a ubicar en el inicio

        char linea[100];

        while(1){

                indice = lectura2.tellg(); //Indice que nos dice en que posicion estamos
                cout << indice << endl;
                if(indice+n<final){ //El indice más el tamaño del bloque se salen del escritura
                    lectura2.read(linea,n); //Si no, se lee el tamaño del bloque
                    escritura2.write(linea,n); //Se escribe en el nuevo escritura
                }
                else{
                    lectura2.read(linea,final-indice);  //Se lee entonces lo que falta que e s  menos del tamaño del bloque
                    escritura2.write(linea,final-indice); //Se escribe lo que falta
                    break;
                }

                if(lectura2.fail()){ // Si hay error se indica
                    cout << "Lectura erronea" << endl;

                }

        }
    }
    else{
        cout << "Error al abrir el archivo" << endl;
    }


    lectura2.close(); //Se cierran los escrituras
    escritura2.close(); //Se cierra

}
