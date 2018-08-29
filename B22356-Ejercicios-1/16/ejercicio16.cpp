#include <iostream>
#include <string>
#include <math.h>
using namespace std;
void imprimirOpciones();
void b2d();
void d2b();
void b2h();
void h2b();
void d2h();
void h2d();
int main(int argc, char const *argv[]) {
    while (1) {
        string opcion;
        imprimirOpciones();
        cin >> opcion;
        cout << "Opcion recibida: " << opcion << endl;
        if (opcion == "7") {
            exit(0);
        }
        else if(opcion == "1"){
            b2d();
        }
        else if(opcion == "2"){

        }
        else if(opcion == "3"){

        }
        else if(opcion == "4"){

        }
        else if(opcion == "5"){

        }
        else if(opcion == "6"){

        }
    }
    return 0;
}

void imprimirOpciones() {
    cout << "Elija una de las siguientes opciones:" << endl;
    cout << "1- Convertir de binario a decimal" << endl;
    cout << "2- Convertir de decimal a binario" << endl;
    cout << "3- Convertir de binario a hexadecimal" << endl;
    cout << "4- Convertir hexadecimal a binario" << endl;
    cout << "5- Convertir decimal a hexadecimal" << endl;
    cout << "6- Convertir de hexadecimal a decimal" << endl;
    cout << "7- Salir" << endl;
}

void b2d(){
    string binario;
    while (1) {
        cout << "Ingrese un número binario: ";
        getline(cin, binario);
        for (int i = 0; i < binario.length(); i++) {
            if (binario[i] != '1' && binario[i] != '0') {
                break;
            }
        }
    }
    string temporal;
    int bits = binario.length();
    int decimal = 0;
    for (int i = 0; i < bits; i++) {
        temporal = binario[i];
        decimal += pow(2,(bits-1-i))*stoi(temporal);
    }
    cout << decimal << endl;
}
