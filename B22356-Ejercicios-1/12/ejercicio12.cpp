#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
using namespace std;

bool verificarString(string);
bool verificarIngreso(string);
double calculoDiscriminante(double, double, double);
void solucionesCuadraticas(double, double, double);

fstream archivoSalida("salida.txt", fstream::out);
fstream archivoEntrada("entrada.txt");

double a;
double b;
double c;
int contadorParametros = 0;

int main(int argc, char* argv[])
{
    string entrada;
    string variable = "";
    string temporal;
    int contador = 0;
    while (!archivoEntrada.eof()) {
        getline(archivoEntrada, entrada, '\0');
        for (int i = 0; i < entrada.length(); i++) {
            temporal = entrada[i];
            if (temporal == "," || temporal == "\n") {
                if (verificarString(variable) && contador == 0) {
                    a = stod(variable);
                    contador++;
                }
                else if (verificarString(variable) && contador == 1) {
                    b = stod(variable);
                    contador++;
                }
                else if ((verificarString(variable) && contador == 2)) {
                    c = stod(variable);
                    contador = 0;
                    solucionesCuadraticas(a,b,c);
                }
                variable = "";
            }
            else{
                variable.append(temporal);
            }
        }
    }
    archivoSalida.close();
    return 0;
}

void solucionesCuadraticas(double a, double b, double c) {
    double discriminante = calculoDiscriminante(a,b,c);
    if (discriminante >= 0){
        double x1 = (-b + sqrt(discriminante))/(2*a);
        double x2 = (-b - sqrt(discriminante))/(2*a);
        archivoSalida << "(" << x1 << "," << x2 << ")" << endl;
    }
    else{
        double x1a = (-b)/(2*a);
        double x1b = sqrt(-discriminante)/(2*a);
        double x2a = (-b)/(2*a);
        double x2b = (sqrt(-discriminante))/(2*a);
        archivoSalida << "(" << x1a << " + j" << x1b << ", " << x2a << " - j" << x2b << ")" << endl;
    }
}

double calculoDiscriminante(double a, double b, double c){
    return ((b*b) - (4*a*c));
}

bool verificarString(string repeticiones){
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
                break;
            default:
                return false;
        }
    }
    return true;
}
