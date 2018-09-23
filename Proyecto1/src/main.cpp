#include "../include/AVL.hpp"
#include <ctime>

int main(){


    fstream outputFile("../misc/outputs/running_times.txt", fstream::out);
    double ts;//time start
    double te;//time end

    cout << "[INFO] Running program..." << endl << endl;

    AVL* palo1 = new AVL();
    ts = clock();
    palo1->avl_tree_create("../misc/inputs/lista_10.txt");
    te = clock();
    outputFile << ((te-ts)/CLOCKS_PER_SEC) << endl;
    delete palo1;

    AVL* palo2 = new AVL();
    ts = clock();
    palo2->avl_tree_create("../misc/inputs/lista_100.txt");
    te = clock();
    outputFile << ((te-ts)/CLOCKS_PER_SEC) << endl;
    delete palo2;

    AVL* palo3 = new AVL();
    ts = clock();
    palo3->avl_tree_create("../misc/inputs/lista_1000.txt");
    te = clock();
    outputFile << ((te-ts)/CLOCKS_PER_SEC) << endl;
    delete palo3;

    AVL* palo4 = new AVL();
    ts = clock();
    palo4->avl_tree_create("../misc/inputs/lista_5000.txt");
    te = clock();
    outputFile << ((te-ts)/CLOCKS_PER_SEC) << endl;
    delete palo4;

    AVL* palo5 = new AVL();
    ts = clock();
    palo5->avl_tree_create("../misc/inputs/lista_10000.txt");
    te = clock();
    outputFile << ((te-ts)/CLOCKS_PER_SEC) << endl;
    delete palo5;

    cout << "[INFO] Program done." << endl;

    return 0;
}
