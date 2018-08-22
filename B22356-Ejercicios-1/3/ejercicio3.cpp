#include <iostream>
#include <string>
using namespace std;

bool verificarString(string);

int main(int argc, char* argv[])
{
    string repeticiones;
    cout << "Ingrese un numero entero positivo: ";
    cin >> repeticiones;
    if (verificarString(repeticiones)) {
        for (int i = 0; i < stoi(repeticiones); i++)
        {
            cout << "Hola mundo" << endl;
        }
    }
    else{
        cout << "\"" << repeticiones << "\"" << " no es un numero entero positivo" << endl;
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
