#include <iostream>
#include "Library/MainDataStructure.h"
#include <iostream>

using namespace std;

bool compare_string(char str1[], char str2[]){
    int index = 0;

    while(str1[index] == str2[index]){
        if(str1[index] == '\0')
            break;
        index++;
    }

    if(str1[index] != str2[index])
        return false;
    return true;
}

int main() {
    MainDataStructure ds = MainDataStructure();

    while(true){
        char command[100];
        cin >> command;

        if(compare_string(command, "exit"))
            break;
        else if(compare_string(command, "Add")){
            int id, health;
            cin >> id >> health;
            ds.add(id, health);
        }else if(compare_string(command, "Serve")){
            char sec[100];
            cin >> sec;
            if(compare_string(sec, "First"))
                ds.serve_first();
            else if(compare_string(sec, "Sickest"))
                ds.serve_sickest();
        }
    }

    return 0;
}
