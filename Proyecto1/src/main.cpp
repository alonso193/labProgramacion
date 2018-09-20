#include "../include/AVL.hpp"
int main(){
    AVL* palo = new AVL();

    //palo->root = NULL;

    palo->root = palo->avl_tree_insert(palo->root,"tati",50);

    palo->root = palo->avl_tree_insert(palo->root,"jose",21);

    palo->root = palo->avl_tree_insert(palo->root,"tati",12);

    palo->root = palo->avl_tree_insert(palo->root,"tati",94);

    palo->root = palo->avl_tree_insert(palo->root,"tati",122);
    palo->root = palo->avl_tree_insert(palo->root,"tati",10);
    palo->root = palo->avl_tree_insert(palo->root,"tati",142);
    palo->root = palo->avl_tree_insert(palo->root,"tati",222);
    palo->root = palo->avl_tree_insert(palo->root,"tati",322);

    palo->root = palo->avl_tree_insert(palo->root,"tati",43);
    palo->root = palo->avl_tree_insert(palo->root,"tati",1112);
    palo->root = palo->avl_tree_insert(palo->root,"tati",7);
    palo->root = palo->avl_tree_insert(palo->root,"tati",431);

    palo->avl_tree_display(palo->root, 1);
    cout << palo->avl_tree_findMax(palo->root)->ID << endl;
    cout << palo->avl_tree_findMin(palo->root)->ID << endl;
    cout << palo->avl_tree_getSize(palo->root) << endl;
    cout << palo->avl_tree_getMaxHeight() << endl;
    // if(palo->avl_tree_search(palo->root,90)){
    //     cout << "viva la liga" << endl;
    // }
    return 0;
}
