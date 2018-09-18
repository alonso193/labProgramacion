#include "AVL.hpp"
int main(){
    AVL* palo = new AVL();
    //Node* root = NULL;
    palo->root = NULL;
    palo->root = palo->avl_tree_insert(palo->root,"jose",10);
    cout << palo->root->ID << " ";
    cout << palo->root->name << endl;
    palo->root = palo->avl_tree_insert(palo->root,"tati",9);
    cout << palo->root->ID << " ";
    cout << palo->root->name << endl;
    palo->root = palo->avl_tree_insert(palo->root,"tati",7);
    cout << palo->root->ID << " ";
    cout << palo->root->name << endl;
    if (palo->avl_tree_search(palo->root, 3)) {
        cout << "mi guapa es muy guapa... viva la liga" << endl;
    }
    else{
        cout << "entre" << endl;
    }
    return 0;
}
