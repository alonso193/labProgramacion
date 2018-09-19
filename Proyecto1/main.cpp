#include "AVL.hpp"
int main(){
    AVL* palo = new AVL();

    palo->root = NULL;

    palo->root = palo->avl_tree_insert(palo->root,"tati",50);

    palo->root = palo->avl_tree_insert(palo->root,"jose",21);

    palo->root = palo->avl_tree_insert(palo->root,"tati",12);

    palo->root = palo->avl_tree_insert(palo->root,"tati",94);

    palo->root = palo->avl_tree_insert(palo->root,"tati",23);

    palo->root = palo->avl_tree_insert(palo->root,"tati",43);
    palo->root = palo->avl_tree_insert(palo->root,"tati",87);
    palo->root = palo->avl_tree_insert(palo->root,"tati",7);
    if(palo->avl_tree_search(palo->root,90)){
        cout << "viva la liga" << endl;
    }
    return 0;
}
