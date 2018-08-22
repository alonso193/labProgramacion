#include <iostream>
#include <math.h>
using namespace std;


double calculoDiscriminante(double, double, double);

void solucionesCuadraticas(double, double, double);

int main(int argc, char* argv[])
{
    string entrada;
    double a;
    double b;
    double c;
    cout << "Ingrese A, o \"S\" para salir: ";
    cin >> entrada;

    while () {
        /* code */
    }
    solucionesCuadraticas(a,b,c);
    return 0;
}

void solucionesCuadraticas(double a, double b, double c) {
    double discriminante = calculoDiscriminante(a,b,c);
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
