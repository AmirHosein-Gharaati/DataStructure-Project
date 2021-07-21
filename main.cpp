#include <iostream>
#include "Library/MainDataStructure.h"
using namespace std;

bool compare_string(char str1[], const char *str2);

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
        }
        else if(compare_string(command, "Update")){
            int id, new_health;
            cin >> id >> new_health;
            ds.update(id, new_health);
        }
        else if(compare_string(command, "Serve")){
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



bool compare_string(char str1[], const char *str2){
    int index = -1;
    char c1, c2;

    do{
        index++;
        c1 = str1[index];
        c2 = str2[index];

        if(c1 >= 'A' && c1 <= 'Z')
            c1 = c1 - 'A' + 'a';
        if(c2 >= 'A' && c2 <= 'Z')
            c2 = c2 - 'A' + 'a';

    }while(c1 == c2 && c1 != '\0');

    if(c1 != c2)
        return false;
    return true;
}