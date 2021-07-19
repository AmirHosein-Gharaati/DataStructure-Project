//
// Created by amir on 7/19/21.
//

#include "MainDataStructure.h"
#include <iostream>
#include "AVL.h"

MainDataStructure::MainDataStructure(){
    this->tree_for_health = new AVL();
    this->tree_for_id = new AVL();
    this->queue = new Queue();
}


void MainDataStructure::add(int id, int health) {
    QueueNode *q = new QueueNode(id, health);
    this->queue->add(q);

    this->tree_for_id->insert(this->tree_for_id->getRoot(), id);
    this->tree_for_id->last->queue = q;
    q->node_for_id = this->tree_for_id->last;

    this->tree_for_health->insert(this->tree_for_health->getRoot(), health);
    this->tree_for_health->last->queue = q;
    q->node_for_health = this->tree_for_health->last;

}


void MainDataStructure::serve_first() {
    QueueNode *q = this->queue->getHead();
    std::cout << q->id << " " << q->health << std::endl;
    this->tree_for_id->remove(this->tree_for_id->getRoot(), q->id);
    this->tree_for_health->remove(this->tree_for_health->getRoot(), q->health);

    this->queue->remove(this->queue->getHead());
}

void MainDataStructure::serve_sickest() {
    Node *temp = this->tree_for_health->minimum();
    if(temp == nullptr) return;

    QueueNode *q = temp->queue;
    std::cout << q->id << " " << q->health << std::endl;

    this->tree_for_id->remove(this->tree_for_id->getRoot(), q->id);
    this->tree_for_health->remove(this->tree_for_health->getRoot(), q->health);

    this->queue->remove(q);
}

void MainDataStructure::update(int id, int new_health) {
    Node *temp = this->tree_for_id->find(id);
    if(temp == nullptr) return;

    QueueNode *q = temp->queue;
    this->tree_for_health->remove(this->tree_for_health->getRoot(), q->health);
    q->node_for_health = nullptr;
    q->health = new_health;

    this->tree_for_health->insert(this->tree_for_health->getRoot(), new_health);
    q->node_for_health = this->tree_for_health->last;
}