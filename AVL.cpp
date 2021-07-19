//
// Created by amir on 7/19/21.
//
#include "AVL.h"
#include <iostream>


int AVL::max(int a, int b) {
    return (a > b) ? a : b;
}

int AVL::height(Node *N) {
    if (N == nullptr)
        return 0;
    return N->height;
}

AVL::AVL() {
    this->root = nullptr;
    this->last = nullptr;
}

Node *AVL::newNode(int key) {
    Node *node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return (node);
}

Node *AVL::rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left),
                    height(y->right)) +
                1;
    x->height = max(height(x->left),
                    height(x->right)) +
                1;
    return x;
}

Node *AVL::leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left),
                    height(x->right)) +
                1;
    y->height = max(height(y->left),
                    height(y->right)) +
                1;
    return y;
}

int AVL::getBalanceFactor(Node *N) {
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

Node *AVL::insertNode(Node *node, int key) {
    if (node == nullptr)
        return (this->last = newNode(key));
    if (key < node->key)
        node->left = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node->right, key);
    else
        return node;

    // Update the balance factor of each node and
    // balance the tree
    node->height = 1 + max(height(node->left),
                           height(node->right));
    int balanceFactor = getBalanceFactor(node);
    if (balanceFactor > 1) {
        if (key < node->left->key) {
            return rightRotate(node);
        } else if (key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }
    if (balanceFactor < -1) {
        if (key > node->right->key) {
            return leftRotate(node);
        } else if (key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }
    return node;
}

Node *AVL::nodeWithMinimumValue(Node *node) {
    Node *current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

Node *AVL::deleteNode(Node *root, int key){
    // Find the node and delete it
    if (root == nullptr)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if ((root->left == nullptr) ||
            (root->right == nullptr)) {
            Node *temp = root->left ? root->left : root->right;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;
            delete (temp);
        } else {
            Node *temp = nodeWithMinimumValue(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right,
                                     temp->key);
        }
    }

    if (root == nullptr)
        return root;

    // Update the balance factor of each node and
    // balance the tree
    root->height = 1 + max(height(root->left),
                           height(root->right));
    int balanceFactor = getBalanceFactor(root);
    if (balanceFactor > 1) {
        if (getBalanceFactor(root->left) >= 0) {
            return rightRotate(root);
        } else {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }
    if (balanceFactor < -1) {
        if (getBalanceFactor(root->right) <= 0) {
            return leftRotate(root);
        } else {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }
    return root;
}

void AVL::insert(Node *n, int value) {
    this->root = insertNode(n, value);
}

void AVL::remove(Node *n, int value) {
    this->root = deleteNode(n, value);
}

Node *AVL::getRoot() {
    return this->root;
}

Node *AVL::maximum() {
    if(this->getRoot() == nullptr)
        return nullptr;
    Node *temp = this->getRoot();

    while(temp->right != nullptr){
        temp = temp->right;
    }

    return temp;
}

Node *AVL::minimum() {
    if(this->getRoot() == nullptr)
        return nullptr;
    Node * temp = this->getRoot();

    while(temp->left != nullptr)
            temp = temp->left;

    return temp;
}

Node *AVL::find(int value) {
    if(this->getRoot() == nullptr)
        return nullptr;

    Node *temp = this->getRoot();

    while(temp != nullptr && temp->key != value){
        if(value < temp->key)
                temp = temp->left;
        else
            temp = temp->right;
    }

    return temp;
}

//-------------------------------------

