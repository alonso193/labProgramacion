#include <iostream>
using namespace std;

class Node{
public:
    Node();
    Node(string, unsigned int);
    string name;
    unsigned int ID;
    int height;
    Node* leftChild;
    Node* rightChild;
    Node* father;
};
