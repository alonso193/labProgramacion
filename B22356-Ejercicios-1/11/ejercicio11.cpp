#include <iostream>
#include <math.h>
#include <string>
using namespace std;

//se encarga de verificar que lo ingresado sea un numero
bool verificarString(string);
//lleva el control de los parametros ingresados y control de salida
bool verificarIngreso(string);
//calculo del discriminante
double calculoDiscriminante(double, double, double);
//calcula soluciones de la ecuacion cuadratica
void solucionesCuadraticas(double, double, double);

double a;
double b;
double c;
int contadorParametros = 0;

int main(int argc, char* argv[])
{
    //el programa se ejecutara siempre que no se pida salir de el
    while(1){
        string entrada;

        //se solicita cada uno de los parametros de la ecuacion
        //y se verifica
        cout << "Ingrese A, o \"S\" para salir: ";
        cin >> entrada;
        while (!verificarIngreso(entrada)) {
            cout << "Ingrese A, o \"S\" para salir: ";
            cin >> entrada;
        }
        contadorParametros++;
        cout << "Ingrese B, o \"S\" para salir: ";
        cin >> entrada;
        while (!verificarIngreso(entrada)) {
            cout << "Ingrese B, o \"S\" para salir: ";
            cin >> entrada;
        }
        contadorParametros++;
        cout << "Ingrese C, o \"S\" para salir: ";
        cin >> entrada;
        while (!verificarIngreso(entrada)) {
            cout << "Ingrese C, o \"S\" para salir: ";
            cin >> entrada;
        }
        // se calcula las soluciones cuadradicas y se reinicia el contador de parametros
        solucionesCuadraticas(a,b,c);
        contadorParametros = 0;
    }
    return 0;
}

void solucionesCuadraticas(double a, double b, double c) {
    double discriminante = calculoDiscriminante(a,b,c);
    //si el discriminante es mayor o igua a cero, se calcula normalmente
    //las soluciones con la formula dada
    if (discriminante >= 0){
        double x1 = (-b + sqrt(discriminante))/(2*a);
        double x2 = (-b - sqrt(discriminante))/(2*a);
        cout << "(" << x1 << "," << x2 << ")" << endl;
    }
    else{
        double x1a = (-b)/(2*a);
        double x1b = sqrt(-discriminante)/(2*a);
        double x2a = (-b)/(2*a);
        double x2b = (sqrt(-discriminante))/(2*a);
        cout << "(" << x1a << " + j" << x1b << ", " << x2a << " - j" << x2b << ")" << endl;
    }
}

double calculoDiscriminante(double a, double b, double c){
    return ((b*b) - (4*a*c));
}

bool verificarString(string repeticiones){
    int banderaPunto = 0;
    for (int i = 0; i < repeticiones.length(); i++) {
        if (i == 0 && repeticiones[i] == '.') {
            return false;
        }
        if (i == 0 && repeticiones[i] == '-') {
            break;
        }
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
            case '.':
                //esta bandera indica si se ingresaron mas de un punto, lo cual no
                //corresponde a un numero valido
                if (banderaPunto != 0) {
                    return false;
                }
                else{
                    banderaPunto = 1;
                    break;
                }

            default:
                return false;
        }
    }
    return true;
}

bool verificarIngreso(string entrada){
    if ((entrada == "s") || (entrada == "S")) {
        //si se ingresa "s" se despide y termina el programa
        cout << "Hasta luego" << endl;
        exit(0);
    }
    else{
        //aca se controla el parametro ingresado con el contador
        if (verificarString(entrada) && contadorParametros == 0) {
            a = stod(entrada);
            return true;
        }
        else if (verificarString(entrada) && contadorParametros == 1) {
            b = stod(entrada);
            return true;
        }
        else if (verificarString(entrada) && contadorParametros == 2) {
            c = stod(entrada);
            return true;
        }
        else{
            return false;
        }
    }
}
