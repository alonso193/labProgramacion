#include <iostream>
using namespace std;

class Node{
public:
    Node();//constructor method
    Node(string, unsigned int);//constructor method
    ~Node();//destructor method
    string name;
    unsigned int ID;
    int height;
    Node* leftChild;
    Node* rightChild;
};
