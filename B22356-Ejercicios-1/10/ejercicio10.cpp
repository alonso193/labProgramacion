#include <iostream>
#include <math.h>
using namespace std;

double calculoDiscriminante(double, double, double);

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
