#include "../include/Node.hpp"

/*
Empty contructure for the class
*/
Node::Node(){
}

/*
Contructor method
*/
Node::Node(string name, unsigned int ID){
    this->name = name;
    this->ID = ID;
    height = 1;
    rightChild = NULL;
    leftChild = NULL;
}

Node::~Node(){
    delete rightChild;
    delete leftChild;
}
