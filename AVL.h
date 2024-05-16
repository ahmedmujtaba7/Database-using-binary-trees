#pragma once
#pragma once
#include<iostream> 
#include <fstream>
using namespace std;

template <class T>
class AVLNode
{
public:
    T key;
    string path;
    int LineNo;
    int ID;

    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode* next;   // for Linked List   
};



//get max of two integers 
int max(int n1, int n2) {
    if (n1 > n2)
        return n1;
    else
        return n2;
}

//function to get height of the tree 
template <class T>
int height(AVLNode<T>* n)
{
    if (n == NULL)
        return 0;
    return n->height;
}


// allocate a new node with key passed
template <class T>
AVLNode<T>* newNodeInTree(T key, string path, int LineNo, int ID)
{
    AVLNode<T>* node = new AVLNode<T>();
    node->key = key;

    node->path = path;
    node->LineNo = LineNo;
    node->ID = ID;

    node->left = NULL;
    node->right = NULL;
    node->height = 1; // new node added as leaf 

    node->next = NULL;

    return(node);
}


// right rotate the sub tree rooted with y
template <class T>
AVLNode<T>* RR(AVLNode<T>* n2)
{
    AVLNode<T>* n1 = n2->left;
    AVLNode<T>* T2 = n1->right;

    // Perform rotation  
    n1->right = n2;
    n2->left = T2;

    // Update heights  
    n2->height = max(height(n2->left), height(n2->right)) + 1;
    n1->height = max(height(n1->left), height(n1->right)) + 1;

    // Return new root  
    return n1;
}


// left rotate the sub tree rooted with x 
template <class T>
AVLNode<T>* LL(AVLNode<T>* n1)
{
    AVLNode<T>* n2 = n1->right;
    AVLNode<T>* T2 = n2->left;

    // Perform rotation  
    n2->left = n1;
    n1->right = T2;
    // Update heights  
    n1->height = max(height(n1->left), height(n1->right)) + 1;
    n2->height = max(height(n2->left), height(n2->right)) + 1;

    // Return new root  
    return n2;
}


// Get Balance factor of node N  
template <class T>
int getBalance(AVLNode<T>* N)
{
    if (N == NULL)
        return 0;
    return height(N->left) -
        height(N->right);
}


//insertion operation for node in AVL tree 
template <class T>
AVLNode<T>* Insert(AVLNode<T>* node, T key, string path, int LineNo, int ID)
{
    //normal BST rotation
    if (node == NULL)
        return(newNodeInTree(key, path, LineNo, ID));

    if (key < node->key)
        node->left = Insert(node->left, key, path, LineNo, ID);
    else if (key > node->key)
        node->right = Insert(node->right, key, path, LineNo, ID);
    else if (key == node->key)   // add as linked list node
    {
        AVLNode<T>* NodeforList = newNodeInTree(key, path, LineNo, ID);
        if (node->next == NULL)  // List is not created yet
        {
            node->next = NodeforList;
        }
        else
        {
            AVLNode<T>* temp = node;
            while (temp->next != NULL)
                temp = temp->next;     // go to end of list
            temp->next = NodeforList;  // linking to newNodeInTree
        }
    }
    else
        return node;

    //update height of ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);        //get balance factor

    // rotate if unbalanced 

    // LL 
    if (balance > 1 && key < node->left->key)
        return RR(node);

    // RR
    if (balance < -1 && key > node->right->key)
        return LL(node);

    // LR 
    if (balance > 1 && key > node->left->key)
    {
        node->left = LL(node->left);
        return RR(node);
    }

    // RL
    if (balance < -1 && key < node->right->key)
    {
        node->right = RR(node->right);
        return LL(node);
    }
    return node;
}




// prints inOrder traversal of the AVL tree
template <class T>
void Inorder_Traversal(AVLNode<T>* root, int choice)
{
    fstream output;
    if (choice == 1)
        output.open("D:/Indexed/AVLID/output.dsdb", ios::app);
    else if (choice == 2)
        output.open("D:/Indexed/AVLYear/output.dsdb", ios::app);
    else if (choice == 3)
        output.open("D:/Indexed/AVLCause/output.dsdb", ios::app);
    else if (choice == 4)
        output.open("D:/Indexed/AVLState/output.dsdb", ios::app);
    else if (choice == 5)
        output.open("D:/Indexed/AVLDeaths/output.dsdb", ios::app);
    else if (choice == 6)
        output.open("D:/Indexed/AVLAge/output.dsdb", ios::app);


    if (root != NULL)
    {
        Inorder_Traversal(root->left, choice);
        output << root->key << "   " << root->ID << "   " << root->path << "  " << root->LineNo << endl;

        //Check if linked list is created
        if (root->next != NULL)   //  Display List
        {
            AVLNode<T>* temp = root->next;
            while (temp != NULL)
            {
                output << temp->key << "   " << temp->ID << "   " << temp->path << "  " << temp->LineNo << endl;
                temp = temp->next;
            }
        }
        Inorder_Traversal(root->right, choice);
    }
    output.close();
}


//insertion operation for node in AVL tree 
//template <class T>
//AVLNode<T>* Insert(AVLNode<T>* node, string key, bool isString, string Path, int LineNo, int ID)
//{
//    //normal BST rotation
//    if (node == NULL)
//        return(newNodeInTree(key, Path, LineNo, ID));
//
//    if (key < node->key)
//        node->left = Insert(node->left, key, true, Path, LineNo, ID);
//    else if (key > node->key)
//        node->right = Insert(node->right, key, true, Path, LineNo, ID);
//    else if (key == node->key)   // add as linked list node
//    {
//        AVLNode<T>* NodeforList = newNodeInTree(key, Path, LineNo, ID);
//        if (node->next == NULL)  // List is not created yet
//        {
//            node->next = NodeforList;
//        }
//        else
//        {
//            AVLNode<T>* temp = node;
//            while (temp->next != NULL)
//                temp = temp->next;     // go to end of list
//            temp->next = NodeforList;  // linking to newNodeInTree
//        }
//
//    }
//    else
//        return node;
//
//    node->height = 1 + max(height(node->left), height(node->right));  // update height
//
//    int balance = getBalance(node);        //get balance factor
//
//    // rotate if unbalanced 
//
//    // LL Case  
//    if (balance > 1 && key < node->left->key)
//        return RR(node);
//
//    // RR
//    if (balance < -1 && key > node->right->key)
//        return LL(node);
//    // LR
//    if (balance > 1 && key > node->left->key)
//    {
//        node->left = LL(node->left);
//        return RR(node);
//    }
//
//    // RL
//    if (balance < -1 && key < node->right->key)
//    {
//        node->right = RR(node->right);
//        return LL(node);
//    }
//    return node;
//}

template<class T>
AVLNode<T>* Search(AVLNode<T>* tree, T& dataTobeSearched, bool& found)
{
    if (tree == nullptr)
    {
        found = false;
        cout << "        No Record to Display" << endl;
        return NULL;
    }
    else if (dataTobeSearched < tree->key)
        Search(tree->left, dataTobeSearched, found);
    else if (dataTobeSearched > tree->key)
        Search(tree->right, dataTobeSearched, found);
    else
    {
        found = true;
        return tree;
    }
}
template<class T>
void Print(AVLNode<T>* root, int k1, int k2,int choice)
{


    fstream output;
    if (choice == 1)
        output.open("D:/Indexed/AVLID/output.dsdb", ios::app);
    else if (choice == 2)
        output.open("D:/Indexed/AVLYear/output.dsdb", ios::app);
    else if (choice == 3)
        output.open("D:/Indexed/AVLCause/output.dsdb", ios::app);
    else if (choice == 4)
        output.open("D:/Indexed/AVLState/output.dsdb", ios::app);
    else if (choice == 5)
        output.open("D:/Indexed/AVLDeaths/output.dsdb", ios::app);
    else if (choice == 6)
        output.open("D:/Indexed/AVLAge/output.dsdb", ios::app);

    if ( k1==k2)
        return;
    if (root != NULL)
    {
        AVLNode<T>* temp = root->next;

        if (k1 < root->ID)
            Print(root->left, k1, k2,choice);

        if (k1 >= root->ID && k1 <= root->ID) {
            cout << temp->key << "   " << temp->ID << "   " << temp->path << "  " << temp->LineNo << endl;
            k1++;
        }

      
       

        //Check if linked list is created
        //if (root->next != NULL)   //  Display List
        //{
        //    AVLNode<T>* temp = root->next;
        //    while (temp != NULL)
        //    {
        //        cout<< temp->key << "   " << temp->ID << "   " << temp->path << "  " << temp->LineNo << endl;       
        //        temp = temp->next;
        //    }
        //}
        /* recursively call the right subtree */
        Print(root->right, k1, k2,choice);
    }
    output.close();

  
}