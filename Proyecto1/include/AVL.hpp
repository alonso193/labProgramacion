#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include "Node.hpp"

class AVL{
public:
    AVL();//constructor method
    ~AVL();//destrucctor method
    void avl_tree_destroyer(Node*);//invoked by the destroyer method
    void avl_tree_create(string);//to create a new tree from a file
    Node* avl_tree_insert(Node*, string, unsigned int);//to insert a node to the tree
    bool avl_tree_search(Node*, unsigned int);
    int avl_tree_height(Node*);//to calculate the height of a specific node
    void avl_tree_display(Node*,int);//to display the entire tree
    Node* avl_tree_findMin(Node*);//find the min ID in the tree
    Node* avl_tree_findMax(Node*);//find the max ID in the tree
    Node* avl_tree_righ_rotation(Node*);//execute a right rotation
    Node* avl_tree_left_rotation(Node*);//execute a left rotation
    int avl_tree_getSize(Node*);//return the number of nodes of a tree
    int avl_tree_getMaxHeight();//return the number of levels of a tree
    Node* root;//I'm groot
    int k;//contains the balance of a node, used to indicate unbalanced nodes
    int nodeCounter;//used as a counter for the avl_tree_getSize method
};
