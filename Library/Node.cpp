//
// Created by amir on 7/19/21.
//

#include "Node.h"



Node::Node(int key) {
    this->left = this->right = nullptr;
    this->queue = nullptr;
    this->key = key;
}

Node::Node() {
    this->left = this->right = nullptr;
    this->queue = nullptr;
}

void Node::setQueueNode(QueueNode *q) {
    this->queue = q;
}