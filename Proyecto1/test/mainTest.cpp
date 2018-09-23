#include "../include/AVL.hpp"

void printMenu();
void createTree();

AVL* palo = new AVL();

int main() {
    int testSelect;
    printMenu();
    cin >> testSelect;
    if (testSelect == 1) {
        palo->avl_tree_create("../misc/inputs/lista_1_0.txt");
    }
    else if (testSelect == 2) {
        palo->avl_tree_insert(palo->root,"Lochi Yu", 100000010);
        palo->avl_tree_insert(palo->root, "Parangaricutirimicuaro", 110101);
        palo->avl_tree_insert(palo->root,"Teodoro Willink", 100000010);
        palo->avl_tree_insert(palo->root,"Margie Sanchez", 901120967);
        palo->avl_tree_insert(palo->root,"Don Asdru", 301040666);
        palo->avl_tree_insert(palo->root, "Esternocleidomastoideo", 010000101);
        palo->avl_tree_display(palo->root, 1);
    }
    else if (testSelect == 3) {
        createTree();
        palo->avl_tree_display(palo->root, 1);
    }
    else if (testSelect == 4){
        createTree();
        palo->avl_tree_display(palo->root, 1);
        cout << "The min ID in the tree is: " << palo->avl_tree_findMin(palo->root)->ID << endl;
        cout << "The max ID in the tree is: " << palo->avl_tree_findMax(palo->root)->ID << endl;
    }
    else if (testSelect == 5) {
        createTree();
        palo->avl_tree_display(palo->root, 1);
        cout << "The tree's height is: " << palo->avl_tree_getMaxHeight() << endl;
    }
    else if (testSelect == 6) {
        createTree();
        palo->avl_tree_display(palo->root, 1);
        cout << "The number of nodes in the tree are: " << palo->avl_tree_getSize(palo->root) << endl;
    }
    else{
        cout << "Review the options and don't be silly" << endl;
         cout << "Now you lost the chance to run the program... sorry" << endl;
    }

    return 0;
}

void createTree(){
    palo->avl_tree_insert(palo->root,"Lochi Yu", 100000010);
    palo->avl_tree_insert(palo->root,"Teodoro Willink", 215250867);
    palo->avl_tree_insert(palo->root,"Margie Sanchez", 901120967);
    palo->avl_tree_insert(palo->root,"Don Asdru", 301040666);
    palo->avl_tree_insert(palo->root,"GD", 500000001);
    palo->avl_tree_insert(palo->root,"Luis Marin", 701010101);
    palo->avl_tree_insert(palo->root,"Isnalda", 810100101);
    palo->avl_tree_insert(palo->root,"Mili", 420298374);
    palo->avl_tree_insert(palo->root,"Johan", 617177272);
    palo->avl_tree_insert(palo->root,"Francisco Siles", 100000011);
}

void printMenu(){
    cout << "Here you can select across the different tests." << endl;
    cout << "Main menu:" << endl;
    cout << "   * Negative tests:" << endl;
    cout << "       1- Bad file name entry" << endl;
    cout << "       2- Incorrect ID number" << endl;
    cout << "           - Insuficient numbers" << endl;
    cout << "           - Repeated ID" << endl;
    cout << "           - Initial number invalid(different of 1-9 numbers)" << endl;
    cout << "   * Positive tests:" << endl;
    cout << "       3- Correct insert and display of 10 elements to the tree" << endl;
    cout << "       4- Search the min and max ID in the tree" << endl;
    cout << "       5- Display the tree's height" << endl;
    cout << "       6- Display the number of nodes in the tree" << endl;
    cout << "Select your option: ";
}
