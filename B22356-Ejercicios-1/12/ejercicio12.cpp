/*
el siguiennte programa calcula las soluciones de una ecuacion cuadratica con
base en los parametros leidos de un archivo de entrada. las soluciones las pone
en un archivo de salida
*/

#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
using namespace std;

//verifica que lo ingresado sea un numero valido
bool verificarString(string);
//lleva el control de parametros ingresados
bool verificarIngreso(string);
//calculan discriminante y soluciones
double calculoDiscriminante(double, double, double);
void solucionesCuadraticas(double, double, double);

//archivos de entrada y salida
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
    //se lee el archivo completo hasta la bandera de final
    while (!archivoEntrada.eof()) {
        //se obtiene una linea del archivo
        getline(archivoEntrada, entrada, '\0');
        for (int i = 0; i < entrada.length(); i++) {
            temporal = entrada[i];

            //cuando se obtiene una coma o un final de linea, significara
            //que se ha recibido un argumento completo
            if (temporal == "," || temporal == "\n") {
                //en caso de que el argumento sea valido
                //se agrega al parametro correspondiente de acuerdo a la cuenta
                //que lleve el contador
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
                    //cuando se han obtenido los tres parametros, se calculan
                    //las soluciones de la ecuacion
                    solucionesCuadraticas(a,b,c);
                }
                //se renueva la variable para calcular una nueva solucion
                variable = "";
            }
            else{
                //se hace append de los caracteres que no sean coma o final de linea
                variable.append(temporal);
            }
        }
    }
    archivoSalida.close();
    return 0;
}

void solucionesCuadraticas(double a, double b, double c) {
    double discriminante = calculoDiscriminante(a,b,c);
    //si el discriminante es mayor o igua a cero, se calcula normalmente
    //las soluciones con la formula dada
    if (discriminante >= 0){
        double x1 = (-b + sqrt(discriminante))/(2*a);
        double x2 = (-b - sqrt(discriminante))/(2*a);
        //aca en lugar de imprimir, se mandan los datos al archivo de salida
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
