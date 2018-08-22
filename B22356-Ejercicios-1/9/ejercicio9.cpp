#include <iostream>
#include <string>
using namespace std;

bool verificarString(string);

int main(int argc, char* argv[])
{
    int repeticiones = atoi(argv[1]);
    if (verificarString(string(argv[1])) && repeticiones > 0) {
        for (int i = 0; i < repeticiones - 1; i++) {
            for (int j = 0; j < i; j++) {
                cout << " ";
            }
            for (int k = repeticiones - i; k > 0; k--) {
                cout << "A";
            }
            cout << endl;
        }
        for (int i = 0; i < repeticiones; i++) {
            for (int j = repeticiones - 1 - i; j > 0; j--) {
                cout << " ";
            }
            for (int k = 0; k <= i; k++) {
                cout << "A";
            }
            cout << endl;
        }
    }
    else{
        cout << "\"" << string(argv[1]) << "\"" << " no es un numero entero mayor a cero" << endl;
    }
    return 0;
}

bool verificarString(string repeticiones){
    for (int i = 0; i < repeticiones.length(); i++) {
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
            default:
                return false;
        }
    }
    return true;
}
