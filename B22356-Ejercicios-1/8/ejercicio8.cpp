/*
El siguiente programa se encarga de imprimir un patron de letras
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
    int repeticiones = atoi(argv[1]);
    if (verificarString(string(argv[1])) && repeticiones > 0) {
        //un for descendente y otro ascendente cada uno con la cantidad de niveles
        //que fueron ingresados por linea de comandos
        for (int i = 0; i < repeticiones - 1; i++) {
            for (int k = repeticiones - i; k > 0; k--) {
                cout << "A";
            }
            cout << endl;
        }
        for (int i = 0; i < repeticiones; i++) {
            for (int k = 0; k <= i; k++) {
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
