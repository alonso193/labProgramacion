#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    int repeticiones;
    cout << "Ingrese un numero entero positivo: ";
    cin >> repeticiones;
    for (int i = 0; i < repeticiones; i++)
    {
        cout << "Hola mundo" << endl;
    }
    return 0;
}
