#include <iostream>
using namespace std;

class Node{
public:
    Node();
    Node(string, unsigned int);
    void printNode();
    string name;
    unsigned int ID;
    int height;
    Node* leftSon;
    Node* rigthSon;
    Node* father;
};
