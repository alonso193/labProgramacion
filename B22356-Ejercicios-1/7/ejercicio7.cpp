/*
El siguiente programa se encarga de imprimir un triangulo invertido con letras y espacios
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
        //el primer for es para los niveles del triangulo
        for (int i = 0; i < repeticiones; i++) {
            //en este caso se tienen dos for anidados, uno para que imprima los espacios
            //y el otro para que imprima las letras
            for (int k = 0; k < i; k++) {
                cout << " ";
            }
            for (int j = repeticiones - i; j > 0; j--) {
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
