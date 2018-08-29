#include <iostream>
#include <string>
using namespace std;
bool detectaPalindromo(string);
int main(int argc, char const *argv[]) {
    string palabra;
    while (1) {
        cout << "Ingrese la palabra o 0 para salir: ";
        getline(cin, palabra);
        if (palabra == "0") {
            cout << "Hasta luego" << endl;
            exit(0);
        }
        if (detectaPalindromo(palabra)) {
            cout << "Es palindromo" << endl;
        }
        else{
            cout << "No es palindromo" << endl;
        }
    }
    return 0;
}

bool detectaPalindromo(string palabra){
    string palabraSinEspacios = "";
    string palabraTemporal;
    for (int i = 0; i < palabra.length(); i++) {
        palabraTemporal = palabra[i];
        if (palabra[i] != ' ') {
            palabraSinEspacios.append(palabraTemporal);
        }
    }
    for (int i = 0; i < (palabraSinEspacios.length()/2); i++) {
        if(palabraSinEspacios[i] != palabraSinEspacios[palabraSinEspacios.length() - 1 - i]){
            return false;
        }
    }
    return true;
}
