#include <iostream>
#include "Node.hpp"

class AVL{
public:
    AVL();
    ~AVL();
    void avl_tree_delete(string, unsigned int);
    void avl_tree_create(string);
    void avl_tree_insert(string, unsigned int);
    void avl_tree_search_position(Node* &, Node* &);
    void avl_tree_display();
    Node* root;
};
