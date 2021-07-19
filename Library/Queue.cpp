//
// Created by amir on 7/19/21.
//

#include "Queue.h"


QueueNode::QueueNode(int id, int health){
    this->node_for_id = this->node_for_health = nullptr;
    this->next = this->prev = nullptr;

    this->id = id;
    this->health = health;
}

//---------------------------------------

Queue::Queue() {
    this->head = this->tail = nullptr;
}

void Queue::remove(QueueNode *q) {
    if(q == this->getHead() && q == this->getTail()){
        this->head = this->tail = nullptr;
        delete q;
    }else if(q == this->getHead() && q != this->getTail()){
        this->getHead()->next->prev = nullptr;
        this->head = this->getHead()->next;
        delete q;
    }else if(q != this->getHead() && q == this->getTail()){
        this->getTail()->prev->next = nullptr;
        this->tail = this->getTail()->prev;
        delete q;
    }else{
        q->prev->next = q->next;
        q->next->prev = q->prev;

        delete q;
    }
}

void Queue::add(QueueNode *q) {
    if(this->getHead() == nullptr){
        this->head = this->tail = q;
    }else{
        this->tail->next = q;
        q->prev = this->tail;
        this->tail = q;
    }
}

QueueNode *Queue::getHead() {
    return this->head;
}

QueueNode *Queue::getTail() {
    return this->tail;
}

//---------------------------------------