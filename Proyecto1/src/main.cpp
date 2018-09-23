#include "../include/AVL.hpp"
#include <ctime>

int main(){

    //create the files to put the outputs of the program
    fstream outputFile("../misc/outputs/running_times.txt", fstream::out);
    fstream outputFile2("../misc/outputs/max_and_min_id.txt", fstream::out);
    string filename;

    //variables used to calculate the time elapsed in a create run
    double ts;//time start
    double te;//time end

    cout << "[INFO] Running program..." << endl << endl;


    //in each once of that groups of lines, is provided a file name
    //then, call  the create method, and put the data in the output files
    AVL* palo1 = new AVL();
    ts = clock();
    filename = "../misc/inputs/lista_10.txt";
    palo1->avl_tree_create(filename);
    te = clock();
    outputFile << ((te-ts)/CLOCKS_PER_SEC) << endl;
    outputFile2 << "In the " << filename << " the max ID is: ";
    outputFile2 << palo1->avl_tree_findMax(palo1->root)->ID << endl;
    outputFile2 << "In the " << filename << " the min ID is: ";
    outputFile2 << palo1->avl_tree_findMin(palo1->root)->ID << endl << endl;
    delete palo1;

    //in each once of that groups of lines, is provided a file name
    //then, call  the create method, and put the data in the output files
    AVL* palo2 = new AVL();
    ts = clock();
    filename = "../misc/inputs/lista_100.txt";
    palo2->avl_tree_create(filename);
    te = clock();
    outputFile << ((te-ts)/CLOCKS_PER_SEC) << endl;
    outputFile2 << "In the " << filename << " the max ID is: ";
    outputFile2 << palo2->avl_tree_findMax(palo2->root)->ID << endl;
    outputFile2 << "In the " << filename << " the min ID is: ";
    outputFile2 << palo2->avl_tree_findMin(palo2->root)->ID << endl << endl;
    delete palo2;

    //in each once of that groups of lines, is provided a file name
    //then, call  the create method, and put the data in the output files
    AVL* palo3 = new AVL();
    ts = clock();
    filename = "../misc/inputs/lista_1000.txt";
    palo3->avl_tree_create(filename);
    te = clock();
    outputFile << ((te-ts)/CLOCKS_PER_SEC) << endl;
    outputFile2 << "In the " << filename << " the max ID is: ";
    outputFile2 << palo3->avl_tree_findMax(palo3->root)->ID << endl;
    outputFile2 << "In the " << filename << " the min ID is: ";
    outputFile2 << palo3->avl_tree_findMin(palo3->root)->ID << endl << endl;
    delete palo3;

    //in each once of that groups of lines, is provided a file name
    //then, call  the create method, and put the data in the output files
    AVL* palo4 = new AVL();
    ts = clock();
    filename = "../misc/inputs/lista_5000.txt";
    palo4->avl_tree_create(filename);
    te = clock();
    outputFile << ((te-ts)/CLOCKS_PER_SEC) << endl;
    outputFile2 << "In the " << filename << " the max ID is: ";
    outputFile2 << palo4->avl_tree_findMax(palo4->root)->ID << endl;
    outputFile2 << "In the " << filename << " the min ID is: ";
    outputFile2 << palo4->avl_tree_findMin(palo4->root)->ID << endl << endl;
    delete palo4;

    //in each once of that groups of lines, is provided a file name
    //then, call  the create method, and put the data in the output files
    AVL* palo5 = new AVL();
    ts = clock();
    filename = "../misc/inputs/lista_10000.txt";
    palo5->avl_tree_create(filename);
    te = clock();
    outputFile << ((te-ts)/CLOCKS_PER_SEC) << endl;
    outputFile2 << "In the " << filename << " the max ID is: ";
    outputFile2 << palo5->avl_tree_findMax(palo5->root)->ID << endl;
    outputFile2 << "In the " << filename << " the min ID is: ";
    outputFile2 << palo5->avl_tree_findMin(palo5->root)->ID << endl << endl;
    delete palo5;

    cout << "[INFO] Program done." << endl;

    return 0;
}
