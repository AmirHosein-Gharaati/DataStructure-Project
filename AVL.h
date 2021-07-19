//
// Created by amir on 7/19/21.
//

#ifndef DS_PROJECT_AVL_H
#define DS_PROJECT_AVL_H

#include "Node.h"
#include "Queue.h"

class AVL {
private:
    Node *root;


    int max(int, int);
    int height(Node *);
    Node *newNode(int);
    Node *rightRotate(Node *);
    Node *leftRotate(Node *);
    int getBalanceFactor(Node *);
    Node *nodeWithMinimumValue(Node *);
    Node *insertNode(Node *, int);
    Node *deleteNode(Node *, int);


public:
    AVL();
    Node *last;
    Node *getRoot();
    void insert(Node *, int);
    void remove(Node *, int);
    Node *maximum();
    Node *minimum();
    Node *find(int);
};


#endif //DS_PROJECT_AVL_H
