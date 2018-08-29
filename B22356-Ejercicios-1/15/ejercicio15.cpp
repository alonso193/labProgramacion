#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main(int argc, char const *argv[]) {
    string binario = string(argv[1]);
    string temporal;
    int bits = string(argv[1]).length();
    int decimal = 0;
    for (int i = 0; i < bits; i++) {
        temporal = binario[i];
        decimal += pow(2,(bits-1-i))*stoi(temporal);
    }
    cout << decimal << endl;
    return 0;
}
