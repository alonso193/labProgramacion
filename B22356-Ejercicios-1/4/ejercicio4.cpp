/*
El siguiente programa se encarga de imprimir un triangulo
del tamaño ingresado por la linea de comandos
*/

#include <iostream>
#include <string>
using namespace std;

//Esta funcion se encargara de que el valor ingresado como parametro a la funcion
//main, sea un numero entero
bool verificarString(string);

int main(int argc, char* argv[])
{
    //se obtiene el parametro ingresado y se convierte a entero
    int repeticiones = atoi(argv[1]);

    if (verificarString(string(argv[1])) && repeticiones > 0) {
        //luego de verificar que el parametro se un numero entero positivo mayor a 0
        //se pasa a imprimir las letras para que formen el triangulo solicitado
        for (int i = 0; i < repeticiones; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cout << "A";
            }
            cout << endl;
        }
    }
    else{//en caso de que el parametro ingresado no sea un numero entero mayor a cero
        cout << "\"" << string(argv[1]) << "\"" << " no es un numero entero mayor a cero" << endl;
    }
    return 0;
}

bool verificarString(string repeticiones){

    //se recorre todo el parametro recibido para corroborar que solo lo conformen numeros
    for (int i = 0; i < repeticiones.length(); i++) {
        switch (repeticiones[i]) {
            case '1':
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                break;
            case '5':
                break;
            case '6':
                break;
            case '7':
                break;
            case '8':
                break;
            case '9':
                break;
            case '0':
                break;
            default:
                return false;
        }
    }
    return true;
}
