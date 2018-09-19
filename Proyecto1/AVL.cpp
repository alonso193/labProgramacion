#include "AVL.hpp"

AVL::AVL(){
    root = NULL;
}

AVL::~AVL(){
    delete root;
}

Node* AVL::avl_tree_insert(Node* newNode, string name, unsigned int ID){
    if (newNode == NULL) {
        newNode = new Node(name, ID);
        return newNode;
    }
    if (newNode->ID < ID) {
        newNode->rightChild = avl_tree_insert(newNode->rightChild, name, ID);
    }
    else if (newNode->ID > ID) {
        newNode->leftChild = avl_tree_insert(newNode->leftChild, name, ID);
    }
    else{
        cout << "Maybe the ID it's incorrect" << endl;
    }

    newNode->height = max(avl_tree_height(newNode->leftChild),avl_tree_height(newNode->rightChild)) + 1;

    if (newNode != NULL) {
        this->k = avl_tree_height(newNode->rightChild) - avl_tree_height(newNode->leftChild);
    }
    else{
        this->k = 0;
    }

    if (k < -1 && ID > newNode->leftChild->ID) {//left right rotate
        cout << "rotacion izquierda derecha" << endl;
        newNode->leftChild = avl_tree_left_rotation(newNode->leftChild);
        return avl_tree_righ_rotation(newNode);
    }
    else if (k > 1 && ID < newNode->rightChild->ID) {//right left totate
        cout << "rotacion derecha izquierda" << endl;
        newNode->rightChild = avl_tree_righ_rotation(newNode->rightChild);
        return avl_tree_left_rotation(newNode);
    }
    else if (k < -1 && ID < newNode->leftChild->ID) {//rigth rotate
        cout << "rotacion derecha" << endl;
        return avl_tree_righ_rotation(newNode);
    }
    else if (k > 1 && ID > newNode->rightChild->ID) {//left rotate
        cout << "rotacion izquierda" << endl;
        return avl_tree_left_rotation(newNode);
    }
    return newNode;
}

Node* AVL::avl_tree_righ_rotation(Node* z){
    Node* y = z->leftChild;
    z->leftChild = y->rightChild;
    y->rightChild = z;
    z->height = max(avl_tree_height(z->leftChild), avl_tree_height(z->rightChild)) + 1;
    y->height = max(avl_tree_height(y->leftChild), avl_tree_height(y->rightChild)) + 1;
    return y;
}

Node* AVL::avl_tree_left_rotation(Node* z){
    Node* y = z->rightChild;
    z->rightChild = y->leftChild;
    y->leftChild = z;
    z->height = max(avl_tree_height(z->leftChild), avl_tree_height(z->rightChild)) + 1;
    y->height = max(avl_tree_height(y->leftChild), avl_tree_height(y->rightChild)) + 1;
    return y;
}

bool AVL::avl_tree_search(Node* root, unsigned int ID2Search){
    if (root != NULL) {
        if (root->ID == ID2Search) {
            return true;
        }
        else{
            if (root->ID < ID2Search) {
                avl_tree_search(root->rightChild, ID2Search);
            }
            else if(root->ID > ID2Search) {
                avl_tree_search(root->leftChild, ID2Search);
            }
        }
    }
    else{
        return false;
    }
}

int AVL::avl_tree_height(Node* node){
    if (node != NULL) {
        return node->height;
    }
    else{
        return 0;
    }
}

void AVL::avl_tree_delete(string nombre, unsigned int cedula){

}

void AVL::avl_tree_create(string archivo){

}

void AVL::avl_tree_display(Node* root){
    if (root != NULL) {
        cout << root->ID << endl;
        avl_tree_display(root->leftChild);
        avl_tree_display(root->rightChild);
    }
}
