/*
este programa pone un menu de conversiones de base
y convierte acorde a lo seleccionado el numero ingrasado a la base solicitada
luego de haberlo verificado
*/
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

//esta funcion se encarga de imprimir el menu
void imprimirOpciones();

//convierte de binario a decimal
string b2d(string);

//convierte de decimal a binario
string d2b(string);

//convierte de decimal a hexadecimal
string d2h(string);

//convierte de hexadecimal a decimal
string h2d(string);
//las conversiones restantes se calculan como una combinacion de las anteriores

//estas funciones comprueban que los numeros ingresados concuerden con lo solicitado
bool comprobarHexadecimal(string);
bool comprobarBinario(string);
bool comprobarDecimal(string);

int main(int argc, char const *argv[]) {
    while (1) {
        string opcion;

        //se imprime el menu
        imprimirOpciones();
        cin >> opcion;
        cout << "Opcion recibida: " << opcion << endl;

        //si digito 7, se termina el programa
        if (opcion == "7") {
            exit(0);
        }

        //luego se llama la funcion necesaria de acuerdo a lo ingresado
        else if(opcion == "1"){
            string binario;
            while (1) {
                cout << "Ingrese un número binario:" << endl;
                cin >> binario;
                if (comprobarBinario(binario)) {
                    cout << "El numero binario ingresado en decimal es: " << b2d(binario) << endl;
                    break;
                }
            }
        }
        else if(opcion == "2"){
            string decimal;
            while (1) {
                cout << "Ingrese un número decimal:" << endl;
                cin >> decimal;
                if (comprobarDecimal(decimal)) {
                    cout << "El numero decimal ingresado en binario es: " << d2b(decimal) << endl;
                    break;
                }
            }
        }
        else if(opcion == "3"){
            string binario;
            while (1) {
                cout << "Ingrese un número binario:" << endl;
                cin >> binario;
                if (comprobarBinario(binario)) {
                    cout << "El binario ingresado en hexadecimal es: " << d2h(b2d(binario)) << endl;
                    break;
                }
            }
        }
        else if(opcion == "4"){
            string hexadecimal;
            while (1) {
                cout << "Ingrese un número hexadecimal:" << endl;
                cin >> hexadecimal;
                if (comprobarHexadecimal(hexadecimal)) {
                    cout << "El hexadecimal ingresado en binario es: " << d2b(h2d(hexadecimal)) << endl;
                    break;
                }
            }
        }
        else if(opcion == "5"){
            string decimal;
            while (1) {
                cout << "Ingrese un número decimal:" << endl;
                cin >> decimal;
                if (comprobarDecimal(decimal)) {
                    cout << "El numero decimal ingresado en hexadecimal es: " << d2h(decimal) << endl;
                    break;
                }
            }
        }
        else if(opcion == "6"){
            string hexadecimal;
            while (1) {
                cout << "Ingrese un número hexadecimal:" << endl;
                cin >> hexadecimal;
                if (comprobarHexadecimal(hexadecimal)) {
                    cout << "El numero hexdecimal ingresado en decimal es: " << h2d(hexadecimal) << endl;
                    break;
                }
            }
        }
    }
    return 0;
}

void imprimirOpciones() {
    cout << "Elija una de las siguientes opciones:" << endl;
    cout << "1- Convertir de binario a decimal" << endl;
    cout << "2- Convertir de decimal a binario" << endl;
    cout << "3- Convertir de binario a hexadecimal" << endl;
    cout << "4- Convertir de hexadecimal a binario" << endl;
    cout << "5- Convertir de decimal a hexadecimal" << endl;
    cout << "6- Convertir de hexadecimal a decimal" << endl;
    cout << "7- Salir" << endl;
}


//se toma el algoritmo del ejercicio 15
string b2d(string binario){
    string temporal;
    int decimal = 0;
    for (int i = 0; i < binario.length(); i++) {
        temporal = binario[i];
        decimal += pow(2,(binario.length()-1-i))*stoi(temporal);
    }
    return to_string(decimal);
}

bool comprobarBinario(string binario){
    //se recorre digito a digito para comprobar que solo sean ceros o unos
    for (int i = 0; i < binario.length(); i++) {
        if (binario[i] != '1' && binario[i] != '0') {
            return false;
        }
    }
    return true;
}


//se repite el algoritmo del ejercicio 14
string d2b(string decimal){
    int divisor = 2;
    int modulo;
    int dividendo;
    string binarioInverso = "";
    string binario = "";
    string temporal;
    dividendo = stoi(decimal);
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
    return binario;
}

bool comprobarDecimal(string decimal){
    //se recorre digito a digito para comprobar valores validos
    for (int i = 0; i < decimal.length(); i++) {
        if (decimal[i] != '0' && decimal[i] != '1' && decimal[i] != '2' &&
            decimal[i] != '3' && decimal[i] != '4' && decimal[i] != '5' &&
            decimal[i] != '6' && decimal[i] != '7' && decimal[i] != '8' && decimal[i] != '9'){
            return false;
        }
    }
    return true;
}

//el algoritmo es el mismo que el de d2b, tomando en cuenta que ahora
//se convierte a hexadecimal, por lo que se divide por 16
//tambien se toman en cuenta los valores del 10 al 15 para sustituirlos por sus
//letras correspondientes
string d2h(string decimal){
    int divisor = 16;
    int modulo;
    int dividendo;
    string hexadecimalInverso = "";
    string hexadecimal = "";
    string temporal;
    dividendo = stoi(decimal);
    if (dividendo != 0) {
        while (dividendo >= divisor) {
            modulo = dividendo%divisor;
            if (modulo > 9 && modulo == 10) {
                hexadecimalInverso.append("A");
            }
            else if (modulo > 9 && modulo == 11) {
                hexadecimalInverso.append("B");
            }
            else if (modulo > 9 && modulo == 12) {
                hexadecimalInverso.append("C");
            }
            else if (modulo > 9 && modulo == 13) {
                hexadecimalInverso.append("D");
            }
            else if (modulo > 9 && modulo == 14) {
                hexadecimalInverso.append("E");
            }
            else if (modulo > 9 && modulo == 15) {
                hexadecimalInverso.append("F");
            }
            else{
                hexadecimalInverso.append(to_string(modulo));
            }
            dividendo = dividendo/divisor;
        }
        if (dividendo > 9 && dividendo == 10) {
            hexadecimalInverso.append("A");
        }
        else if (dividendo > 9 && dividendo == 11) {
            hexadecimalInverso.append("B");
        }
        else if (dividendo > 9 && dividendo == 12) {
            hexadecimalInverso.append("C");
        }
        else if (dividendo > 9 && dividendo == 13) {
            hexadecimalInverso.append("D");
        }
        else if (dividendo > 9 && dividendo == 14) {
            hexadecimalInverso.append("E");
        }
        else if (dividendo > 9 && dividendo == 15) {
            hexadecimalInverso.append("F");
        }
        else{
            hexadecimalInverso.append(to_string(dividendo));
        }
        for (int i = hexadecimalInverso.length() - 1; i >= 0; i--) {
            temporal = hexadecimalInverso[i];
            hexadecimal.append(temporal);
        }
    }
    else{
        hexadecimal = "0";
    }
    return hexadecimal;
}


//este algoritmo es igual que el de b2d solo que antes se cambian
//los valodes A-F por sus numeros correspondientes y el peso de cada digito
//es de 16 a su potencia
string h2d(string hexadecimal){
    int temporal;
    string stringTemporal;
    int decimal = 0;
    for (int i = 0; i < hexadecimal.length(); i++) {
        stringTemporal = hexadecimal[i];
        if (stringTemporal == "A" || stringTemporal == "a") {
            temporal = 10;
        }
        else if (stringTemporal == "B" || stringTemporal == "b") {
            temporal = 11;
        }
        else if (stringTemporal == "C" || stringTemporal == "c") {
            temporal = 12;
        }
        else if (stringTemporal == "D" || stringTemporal == "d") {
            temporal = 13;
        }
        else if (stringTemporal == "E" || stringTemporal == "e") {
            temporal = 14;
        }
        else if (stringTemporal == "F" || stringTemporal == "f") {
            temporal = 15;
        }
        else{
            temporal = stoi(stringTemporal);
        }
        decimal += pow(16,(hexadecimal.length()-1-i))*temporal;
    }
    return to_string(decimal);
}

bool comprobarHexadecimal(string hexadecimal){
    //se recorre digito a digito para comprobar valores validos
    for (int i = 0; i < hexadecimal.length(); i++) {
        if (hexadecimal[i] != '0' && hexadecimal[i] != '1' && hexadecimal[i] != '2' &&
            hexadecimal[i] != '3' && hexadecimal[i] != '4' && hexadecimal[i] != '5' &&
            hexadecimal[i] != '6' && hexadecimal[i] != '7' && hexadecimal[i] != '8' && hexadecimal[i] != '9' &&
            hexadecimal[i] != 'A' && hexadecimal[i] != 'B' && hexadecimal[i] != 'C' && hexadecimal[i] != 'D' &&
            hexadecimal[i] != 'E' && hexadecimal[i] != 'F' && hexadecimal[i] != 'a' && hexadecimal[i] != 'b' &&
            hexadecimal[i] != 'c' && hexadecimal[i] != 'd' && hexadecimal[i] != 'e' && hexadecimal[i] != 'f'){
            return false;
        }
    }
    return true;
}
