//
// Created by amir on 7/19/21.
//

#ifndef DS_PROJECT_QUEUE_H
#define DS_PROJECT_QUEUE_H

#include "Node.h"

class Node;

class QueueNode{
public:
    int id;
    int health;
    Node *node_for_id, *node_for_health;
    QueueNode *next, *prev;

    QueueNode(int, int);
};

class Queue{
public:
    QueueNode *head, *tail;

    Queue();
    void remove(QueueNode *);
    void add(QueueNode *);
    QueueNode *getHead();
    QueueNode *getTail();
};


#endif //DS_PROJECT_QUEUE_H
