#include <iostream>
#include <algorithm>
#include "Node.hpp"

class AVL{
public:
    AVL();//constructor method
    ~AVL();//destrucctor method
    void avl_tree_delete(string, unsigned int);//method to delete a node from the tree
    void avl_tree_create(string);//to create a new tree from a file
    Node* avl_tree_insert(Node*, string, unsigned int);//to insert a node to the tree
    bool avl_tree_search(Node*, unsigned int);
    int avl_tree_height(Node*);//to calculate the height of a specific node
    void avl_tree_display();//to display the entire tree
    Node* avl_tree_righ_rotation(Node*);
    Node* avl_tree_left_rotation(Node*);
    Node* root;
    int k;//contains the balance of a node, used to indicate unbalanced nodes
};
