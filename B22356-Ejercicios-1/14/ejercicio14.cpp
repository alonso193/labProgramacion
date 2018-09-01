/*
este programa convierte un argumento decimal a binario
el argumento lo toma de la linea de comandos
*/
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
    int dividendo = atoi(argv[1]);
    int divisor = 2;
    int modulo;
    string binarioInverso = "";
    string binario = "";
    string temporal;

    //se detecta si el numero ingresado fue cero
    if (dividendo != 0) {
        //sin no, se hace el algoritmo de conversion hasta que el dividendo sea
        //menor al divisor que en este caso es 2
        while (dividendo >= divisor) {
            //el modulo será lo que forme parte del numero binario
            modulo = dividendo%divisor;
            binarioInverso.append(to_string(modulo));
            dividendo = dividendo/divisor;
        }
        //cuando el dividendo es menor a 2, se agrega un uno
        binarioInverso.append("1");

        //luego se le debe dar vuelta a los modulos obtenidos para obtener
        //el binario final
        for (int i = binarioInverso.length() - 1; i >= 0; i--) {
            temporal = binarioInverso[i];
            binario.append(temporal);
        }
    }
    else{
        binario = "0";
    }

    cout << binario << endl;
    return 0;
}
