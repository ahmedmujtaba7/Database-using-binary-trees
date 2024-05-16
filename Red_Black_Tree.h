#pragma once
#include<iostream>
#include<fstream>

using namespace std;
template <class T>
class Node
{
public:
    T key;
    string path;
    int LineNo;
    int ID;

    Node* parent;
    Node* left;
    Node* right;
    int color;
    Node<T>* root;

    Node* next;   // for Linked List   
};

template <class T>
Node<T>* newnodeInTree(T key, string path, int LineNo, int ID)
{
    Node<T>* node1 = new Node<T>();
    node1->key = key;

    node1->path = path;
    node1->LineNo = LineNo;
    node1->ID = ID;

    node1->left = NULL;
    node1->right = NULL;
    //node->height = 1; // new node added as leaf 
    node1->parent = NULL;
    node1->next = NULL;

    return(node1);
}

template <class T>
Node<T>* insert(Node<T>* node1, T key, string path, int LineNo, int ID)
{
    //normal BST rotation
    if (node1 == NULL) {
        return(newnodeInTree(key, path, LineNo, ID));

    }

    if (key < node1->key)
        node1->left = insert(node1->left, key, path, LineNo, ID);
    else if (key > node1->key)
        node1->right = insert(node1->right, key, path, LineNo, ID);
    else if (key == node1->key)   // add as linked list node
    {
        Node<T>* NodeforList = newnodeInTree(key, path, LineNo, ID);
        if (node1->next == NULL)  // List is not created yet
        {
            node1->next = NodeforList;
        }
        else
        {
            Node<T>* temp = node1;
            while (temp->next != NULL)
                temp = temp->next;     // go to end of list
            temp->next = NodeforList;  // linking to newNodeInTree
        }
    }
    else
        return node1;

    //update height of ancestor node
    return node1;
}

template <class T>
void inorder_Traversal(Node<T>* root, int choice)
{
    fstream output;
    if (choice == 1)
        output.open("D:/Indexed/RBID/output.dsdb", ios::app);
    else if (choice == 2)
        output.open("D:/Indexed/RBYear/output.dsdb", ios::app);
    else if (choice == 3)
        output.open("D:/Indexed/RBCause/output.dsdb", ios::app);
    else if (choice == 4)
        output.open("D:/Indexed/RBState/output.dsdb", ios::app);
    else if (choice == 5)
        output.open("D:/Indexed/RBDeaths/output.dsdb", ios::app);
    else if (choice == 6)
        output.open("D:/Indexed/RBAge/output.dsdb", ios::app);


    if (root != NULL)
    {
        inorder_Traversal(root->left, choice);
        output << root->key << "   " << root->ID << "   " << root->path << "  " << root->LineNo << endl;

        //Check if linked list is created
        if (root->next != NULL)   //  Display List
        {
            Node<T>* temp = root->next;
            while (temp != NULL)
            {
                output << temp->key << "   " << temp->ID << "   " << temp->path << "  " << temp->LineNo << endl;
                temp = temp->next;
            }
        }
        inorder_Traversal(root->right, choice);
    }
    output.close();
}


template <class T>
Node<T>* insert(Node<T>* node1, string key, bool isString, string Path, int LineNo, int ID)
{
    //normal BST rotation
    if (node1 == NULL)
        return(newnodeInTree(key, Path, LineNo, ID));

    if (key < node1->key)
        node1->left = insert(node1->left, key, true, Path, LineNo, ID);
    else if (key > node1->key)
        node1->right = insert(node1->right, key, true, Path, LineNo, ID);
    else if (key == node1->key)   // add as linked list node
    {
        Node<T>* NodeforList = newnodeInTree(key, Path, LineNo, ID);
        if (node1->next == NULL)  // List is not created yet
        {
            node1->next = NodeforList;
        }
        else
        {
            Node<T>* temp = node1;
            while (temp->next != NULL)
                temp = temp->next;     // go to end of list
            temp->next = NodeforList;  // linking to newNodeInTree
        }

    }
    else
        return node1;
    return node1;
}

template<class T>
Node<T>* search(Node<T>* tree, T& dataTobeSearched, bool& found)
{
    if (tree == nullptr)
    {
        found = false;
        cout << "        No Record to Display" << endl;
        return NULL;
    }
    else if (dataTobeSearched < tree->key)
        search(tree->left, dataTobeSearched, found);
    else if (dataTobeSearched > tree->key)
        search(tree->right, dataTobeSearched, found);
    else
    {
        found = true;
        return tree;
    }
}
template<class T>
void LL(Node<T>* p, Node<T>* root) {
    if (p->right == NULL)
        return;
    else
    {
        Node<T>* y = p->right;
        if (y->left != NULL)
        {
            p->right = y->left;
            y->left->parent = p;
        }
        else
            p->right = NULL;
        if (p->parent != NULL)
            y->parent = p->parent;
        if (p->parent == NULL)
            root = y;
        else
        {
            if (p == p->parent->left)
                p->parent->left = y;
            else
                p->parent->right = y;
        }
        y->left = p;
        p->parent = y;
    }
}
template<class T>
void RR(Node<T>* p, Node<T>* root) {
    if (p->left == NULL)
        return;
    else
    {
        Node<T>* y = p->left;
        if (y->right != NULL)
        {
            p->left = y->right;
            y->right->parent = p;
        }
        else
            p->left = NULL;
        if (p->parent != NULL)
            y->parent = p->parent;
        if (p->parent == NULL)
            root = y;
        else
        {
            if (p == p->parent->left)
                p->parent->left = y;
            else
                p->parent->right = y;
        }
        y->right = p;
        p->parent = y;
    }
}
template<class T>
void insertfixer(Node<T>* key, Node<T>* root) {
    Node<T>* temp;
    if (root == key) {
        key->color = 0;
        return;
    }
    while (/*key->parent!=NULL &&*/ key->parent->color == 1) {
        if (key->parent == key->parent->parent->right) {
            temp = key->parent->parent->left;
            if (temp == NULL)
                temp = key->parent->parent->right;
            if (temp->color == 1 && temp != NULL) {
                temp->color = 0;
                key->parent->color = 0;
                key->parent->parent->color = 1;
                key = key->parent->parent;
            }
            else {
                if (key = key->parent->left) {
                    key = key->parent;
                    RR(key);
                }
                key->parent->color = 0;
                key->parent->parent->color = 1;
                LL(key->parent->parent);
            }
        }
        else {
            temp = key->parent->parent->right;
            if (temp->color == 1) {
                temp->color = 0;
                key->parent->color = 0;
                key->parent->parent->color = 1;
                key = key->parent->parent;
            }
            else {
                if (key = key->parent->right) {
                    key = key->parent;
                    LL(key);
                }
                key->parent->color = 0;
                key->parent->parent->color = 1;
                RR(key->parent->parent);
            }
        }
        if (key == root) {
            break;
        }
    }
    root->color= 0;
}
