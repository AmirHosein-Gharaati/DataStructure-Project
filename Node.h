//
// Created by amir on 7/19/21.
//

#ifndef DS_PROJECT_NODE_H
#define DS_PROJECT_NODE_H
#include "Queue.h"

class Queue;
class QueueNode;

class Node {
public:
    int key;
    Node *left;
    Node *right;
    int height;
    QueueNode *queue;

    Node(int);
    Node();
    void setQueueNode(QueueNode *);
};


#endif //DS_PROJECT_NODE_H
