/*
Este programa se encarga de imprimir las soluciones de la ecuacion
cuadratica. Los parametros de la ecuacion son ingresados por linea de comandos
*/
#include <iostream>
#include <math.h>
using namespace std;

//Calcula el discriminante de la ecuacion
double calculoDiscriminante(double, double, double);

//realiza el calculo de las soluciones
void solucionesCuadraticas(double, double, double);

int main(int argc, char* argv[])
{
    double a = stod(argv[1]);
    double b = stod(argv[2]);
    double c = stod(argv[3]);
    solucionesCuadraticas(a,b,c);
    return 0;
}

double calculoDiscriminante(double a, double b, double c){
    return ((b*b) - (4*a*c));
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
    else{//en caso de que el discriminante sea negativo, se procede a hacer el calculo con
         //sos raices imaginarias
        double x1a = (-b)/(2*a);
        double x1b = sqrt(-discriminante)/(2*a);
        double x2a = (-b)/(2*a);
        double x2b = (sqrt(-discriminante))/(2*a);
        cout << "(" << x1a << " + j" << x1b << ", " << x2a << " - j" << x2b << ")" << endl;
    }
}
