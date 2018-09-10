#include "AVL.hpp"

AVL::AVL(){
    root = NULL;
}

AVL::~AVL(){}

void AVL::avl_tree_insert(string name, unsigned int ID){
    if (root == NULL) {
        root = new Node(name, ID);
    }
    else{
        Node* newNode = new Node(name, ID);
        avl_tree_search_position(newNode, root);
    }
}

void AVL::avl_tree_search_position(Node* &newNode, Node* &oldNode){
    if (newNode->ID > oldNode->ID) {
        oldNode->height += 1;
        if (oldNode->rigthSon == NULL) {
            oldNode->rigthSon = newNode;
            oldNode->rigthSon->father = oldNode;
        }
        else{
            avl_tree_search_position(newNode, oldNode->rigthSon);
        }
    }
    if (newNode->ID < oldNode->ID) {
        oldNode->height -= 1;
        if (oldNode->leftSon == NULL) {
            oldNode->leftSon = newNode;
            oldNode->leftSon->father = oldNode;
        }
        else{
            avl_tree_search_position(newNode, oldNode->leftSon);
        }
    }

}

void AVL::avl_tree_delete(string nombre, unsigned int cedula){

}

void AVL::avl_tree_create(string archivo){

}

void AVL::avl_tree_display(){
    root->printNode();
    root->rigthSon->printNode();
    root->leftSon->printNode();
    root->rigthSon->rigthSon->printNode();
}
