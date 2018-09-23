#include "../include/AVL.hpp"


/*
Constructor method, used to initialize the respective attributes
*/
AVL::AVL(){
    root = NULL;
    nodeCounter = 0;
    nodeArray = new Node*[10000];
}

/*
Destructor method, used to avoid memory leakage
*/
AVL::~AVL(){
    this->avl_tree_destroyer(this->root);
}

void AVL::avl_tree_destroyer(Node* root){
    if (root->rightChild == NULL && root->leftChild == NULL) {
        delete root;
        root = NULL;
    }
    else if (root->leftChild == NULL) {
        avl_tree_destroyer(root->rightChild);
    }
    else if (root->rightChild == NULL) {
        avl_tree_destroyer(root->leftChild);
    }
    else{
        avl_tree_destroyer(root->rightChild);
        avl_tree_destroyer(root->leftChild);
    }
}

/*
Recursive method used to insert a new node on the tree
also, has the auto-balance control of the tree using the rotation methods
according with the K balance factor
*/
Node* AVL::avl_tree_insert(Node* newNode, string name, unsigned int ID){
    if (to_string(ID).length() != 9 || to_string(ID)[0] == 0) {
        cout << "[ERROR]";
        cout << " The ID number for " << name << " it's incorrect" << endl;
        cout << name  << " could not be added to the tree" << endl << endl;
        return newNode;
    }
    if (newNode == NULL) {
        this->root = new Node(name, ID);
        return this->root;
    }
    if (newNode->ID < ID) {
        newNode->rightChild = avl_tree_insert(newNode->rightChild, name, ID);
    }
    else if (newNode->ID > ID) {
        newNode->leftChild = avl_tree_insert(newNode->leftChild, name, ID);
    }
    else{
        cout << "The ID for " << name << " its repeated and could not be added to the tree" << endl << endl;
    }

    //in each iteration updates the height of each node
    newNode->height = max(avl_tree_height(newNode->leftChild),avl_tree_height(newNode->rightChild)) + 1;

    //after calculate the height of each node, its necessary to calculate
    //the K balance factor
    if (newNode != NULL) {
        this->k = avl_tree_height(newNode->rightChild) - avl_tree_height(newNode->leftChild);
    }
    else{
        this->k = 0;
    }

    //if a node has a negative balance, that means the unbalance
    //is at its left side. The relation between the new ID and its
    //childs ID will determine the appropriate rotation to aplicate

    if (k < -1 && ID > newNode->leftChild->ID) {//left right rotate
        newNode->leftChild = avl_tree_left_rotation(newNode->leftChild);
        this->root = avl_tree_righ_rotation(newNode);
        return this->root;
    }
    else if (k > 1 && ID < newNode->rightChild->ID) {//right left totate
        newNode->rightChild = avl_tree_righ_rotation(newNode->rightChild);
        this->root = avl_tree_left_rotation(newNode);
        return this->root;
    }
    else if (k < -1 && ID < newNode->leftChild->ID) {//rigth rotate
        this->root = avl_tree_righ_rotation(newNode);
        return this->root;
    }
    else if (k > 1 && ID > newNode->rightChild->ID) {//left rotate
        this->root = avl_tree_left_rotation(newNode);
        return this->root;
    }
    this->root = newNode;
    return newNode;
}
/*
this method make the reasignations of the child nodes
and the new root after the rotation for a right rotation
*/
Node* AVL::avl_tree_righ_rotation(Node* z){
    Node* y = z->leftChild;
    z->leftChild = y->rightChild;
    y->rightChild = z;
    z->height = max(avl_tree_height(z->leftChild), avl_tree_height(z->rightChild)) + 1;
    y->height = max(avl_tree_height(y->leftChild), avl_tree_height(y->rightChild)) + 1;
    return y;
}

/*
this method make the reasignations of the child nodes
and the new root after the rotation for a left rotation
*/
Node* AVL::avl_tree_left_rotation(Node* z){
    Node* y = z->rightChild;
    z->rightChild = y->leftChild;
    y->leftChild = z;
    z->height = max(avl_tree_height(z->leftChild), avl_tree_height(z->rightChild)) + 1;
    y->height = max(avl_tree_height(y->leftChild), avl_tree_height(y->rightChild)) + 1;
    return y;
}

/*
This method recive a node, and search an ID from this one
*/
bool AVL::avl_tree_search(Node* root, unsigned int ID2Search){
    if (root != NULL) {
        if (root->ID == ID2Search) {//if the ID was found
            return true;
        }
        else{//recursively search the ID
            if (root->ID < ID2Search) {
                avl_tree_search(root->rightChild, ID2Search);
            }
            else if(root->ID > ID2Search) {
                avl_tree_search(root->leftChild, ID2Search);
            }
        }
    }
    else{//if the ID has not found
        return false;
    }
}

/*
Returns the height of a node
*/
int AVL::avl_tree_height(Node* node){
    if (node != NULL) {
        return node->height;
    }
    else{
        return 0;
    }
}

/*
recursively search for the max ID in the tree
*/
Node* AVL::avl_tree_findMax(Node* root){
    if(root->rightChild != NULL){
        avl_tree_findMax(root->rightChild);
    }
    else{
        return root;
    }
}

/*
recursively search for the min ID in the tree
*/
Node* AVL::avl_tree_findMin(Node* root){
    if(root->leftChild != NULL){
        avl_tree_findMin(root->leftChild);
    }
    else{
        return root;
    }
}

/*
print each node of the tree on its structure
*/
void AVL::avl_tree_display(Node* root, int branch)
{
    if (root != NULL) {
        avl_tree_display(root->rightChild, branch + 1);
        cout << endl << endl;
        if (root == this->root) {
            cout << "root->";
        }
        for (int i = 0; i < branch && root != this->root; i++) {
            cout << "               ";
        }
        cout << root->ID;
        cout << endl << endl;
        avl_tree_display(root->leftChild, branch + 1);

    }
}

/*
returns the height of the tree from its root
*/
int AVL::avl_tree_getMaxHeight(){
    return this->root->height;
}


/*
return the number of nodes of the tree
*/
int AVL::avl_tree_getSize(Node* root){
    if(root != NULL){//count the nodes recursively
        nodeCounter += 1;
        avl_tree_getSize(root->rightChild);
        avl_tree_getSize(root->leftChild);
        return nodeCounter;
    }
}

/*
Receives a file and reads its lines to acquire a name and a ID to call
the insertion method
*/
void AVL::avl_tree_create(string filename){

    FILE* tempFile;
    tempFile = fopen(filename.c_str(), "r");
    string inputFilename = string(filename);
    //this is to verificate that the file exist
    if (tempFile != NULL) {
        fstream inputFile(inputFilename);
        string line;
        string name = "";
        string stringID = "";
        string temporal;
        while (!inputFile.eof()) {
            getline(inputFile, line, '\n');
            if (line != "\0") {

                //sweps the line looking for a char to append at the name
                for (int i = 0; i < line.length(); i++) {
                    temporal = line[i];
                    if (temporal != ",") {
                        name.append(temporal);
                    }
                    else{
                        break;
                    }
                }
                //once the name is complete, look for numbers
                //to append the ID
                for (int i = 0; i < line.length(); i++) {
                    temporal = line[i];
                    if (temporal == "0" || temporal == "1" || temporal == "2" ||
                        temporal == "3" || temporal == "4" || temporal == "5" ||
                        temporal == "6" || temporal == "7" || temporal == "8" || temporal == "9"){

                        stringID.append(temporal);
                    }
                }

                //here, detects posible mistakes in the ID
                if (stringID.length() != 9 || stoi(stringID) < 100000000) {
                    cout << "[ERROR] In " << filename << " file" << endl;
                    cout << "The ID number for " << name << " it's incorrect" << endl;
                    cout << name  << " could not be added to the tree" << endl << endl;
                }
                else{//if has no errors
                    unsigned int ID = stoi(stringID);
                    this->avl_tree_insert(this->root, name, ID);
                }

                name = "";
                stringID = "";
            }

        }
    }
    else{//if the file doesn't exist
        cout << "The file name it's incorrect and the tree can't be created" << endl;
    }


}
