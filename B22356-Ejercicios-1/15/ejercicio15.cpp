/*
el siguiente programa convierte un argumento binario a decimal
el argumento se recibe por linea de comandos
*/

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main(int argc, char const *argv[]) {
    string binario = string(argv[1]);
    string temporal;

    //es necesario conocer la cantidad de bits del binario
    int bits = string(argv[1]).length();

    //inicialmente se establece el decimal en cero
    int decimal = 0;
    for (int i = 0; i < bits; i++) {
        temporal = binario[i];
        //se multiplican los pesos de cada bit de acuerdo a su posicion y se van
        //sumando al decimal final
        decimal += pow(2,(bits-1-i))*stoi(temporal);
    }
    cout << decimal << endl;
    return 0;
}
