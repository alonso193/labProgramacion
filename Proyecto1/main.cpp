#include "AVL.hpp"
int main(){
    //Node* yo = new Node("jose",115250867);
    //Node* tati = new Node("tati",115250666);
    // yo->printNode();
    // yo->rigthSon = tati;
    // yo->rigthSon->printNode();
    AVL* palo = new AVL();
    palo->avl_tree_insert("jose",3);
    palo->avl_tree_insert("tati",5);
    palo->avl_tree_insert("papi",1);
    palo->avl_tree_insert("mami",16);
    palo->avl_tree_insert("turo",25);
    palo->avl_tree_display();
    return 0;
}
