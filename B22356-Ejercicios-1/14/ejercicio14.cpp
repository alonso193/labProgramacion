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
    if (dividendo != 0) {
        while (dividendo >= divisor) {
            modulo = dividendo%divisor;
            binarioInverso.append(to_string(modulo));
            dividendo = dividendo/divisor;
        }
        binarioInverso.append("1");
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
