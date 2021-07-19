#include <iostream>
#include "MainDataStructure.h"
#include <iostream>

using namespace std;

bool compare_string(char str1[], char str2[]){
    int index = 0;

    while(str1[index] == str2[index]){
        if(str1[index] == '\0')
            break;
        index++;
    }

    if(str1[index] != '\0' || str2[index] != '\0')
        return false;
    return true;
}

int main() {
    MainDataStructure ds = MainDataStructure();

//    while(true){
//        char command[100];
//        cin >> command;
//        if(compare_string(command, "exit"))
//            break;
//        else if(compare_string(command, "Add")){
//            ds.add();
//        }
//    }

    ds.add(10, 7);
    ds.add(5, -10);
    ds.add(4, -3);
    ds.update(4, 10);
    ds.serve_sickest();
    ds.serve_sickest();

    return 0;
}
