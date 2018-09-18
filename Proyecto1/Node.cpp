#include "Node.hpp"
Node::Node(){
}

Node::Node(string name, unsigned int ID){
    this->name = name;
    this->ID = ID;
    height = 1;
    rightChild = NULL;
    leftChild = NULL;
    father = NULL;
}
void Node::printNode(){
    cout << ID << ", " << height << ", ";
    if (father != NULL){
        cout << "mi papá es: " << father->ID<< endl;
    }
    else{
        cout << "I don't have father, because I'm the tomatoes father" << endl;
    }
}
