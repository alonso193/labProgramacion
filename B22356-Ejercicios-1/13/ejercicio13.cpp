/*
El siguiente programa detecta si una cadena de caracteres ingresada es un palindromo
*/

#include <iostream>
#include <string>
using namespace std;

//esta funcion arrojara verdadero de encontrar un palindromo
bool detectaPalindromo(string);
int main(int argc, char const *argv[]) {
    string palabra;

    cout << "\n\n\nEl detector de palindromos tiene case sensitivity..." << endl;
    cout << "asi que sea congruente con las mayusculas y minusculas";
    cout << " o no detectara un posible palindromo" << endl;

    while (1) {
        cout << "\n\n\nIngrese la palabra o 0 para salir: ";
        //el motivo de usar getline, es para detectar palindromos
        //que incluyen espacios como:
        //Ali tomo tila... o:
        //A mama Roma le aviva el amor a papa y a papa Roma le aviva el amor a mama.
        getline(cin, palabra);
        if (palabra == "0") {
            //opcion de salida
            cout << "Hasta luego" << endl;
            exit(0);
        }
        //se manda linea a comprobar
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
    //primero se eliminan los espacios de la palabra original
    for (int i = 0; i < palabra.length(); i++) {
        palabraTemporal = palabra[i];
        if (palabra[i] != ' ') {
            palabraSinEspacios.append(palabraTemporal);
        }
    }
    //luego se comprueba letra a letra que concuerde con un palindromo
    for (int i = 0; i < (palabraSinEspacios.length()/2); i++) {
        if(palabraSinEspacios[i] != palabraSinEspacios[palabraSinEspacios.length() - 1 - i]){
            return false;
        }
    }
    return true;
}
