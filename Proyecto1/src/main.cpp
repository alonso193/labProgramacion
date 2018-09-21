#include "../include/AVL.hpp"
#include <ctime>

int main(){
    double ts;//time start
    double te;//time end
    ts = clock();
    AVL* palo = new AVL();


    // cout << palo->avl_tree_findMax(palo->root)->ID << endl;
    // cout << palo->avl_tree_findMin(palo->root)->ID << endl;
    // cout << palo->avl_tree_getSize(palo->root) << endl;
    // cout << palo->avl_tree_getMaxHeight() << endl;
    palo->avl_tree_create("../misc/inputs/lista_10.txt");
    palo->avl_tree_display(palo->root, 1);
    // if(palo->avl_tree_search(palo->root,90)){
    //     cout << "viva la liga" << endl;
    // }
    te = clock();
    cout << "Elapsed time: " << (te-ts)/CLOCKS_PER_SEC << " s" << endl;
    return 0;
}
