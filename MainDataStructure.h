//
// Created by amir on 7/19/21.
//

#ifndef DS_PROJECT_MAINDATASTRUCTURE_H
#define DS_PROJECT_MAINDATASTRUCTURE_H

#include "AVL.h"
#include "Queue.h"

class MainDataStructure{

private:
    AVL *tree_for_health, *tree_for_id;
    Queue *queue;

public:
    MainDataStructure();
    void add(int, int);
    void serve_first();
    void serve_sickest();
    void update(int ,int);
};


#endif //DS_PROJECT_MAINDATASTRUCTURE_H
