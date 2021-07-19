#include <iostream>
#include "MainDataStructure.h"

using namespace std;

int main() {
    MainDataStructure ds = MainDataStructure();

    ds.add(10, 7);
    ds.add(4, -3);
    ds.add(5, -10);
    ds.serve_sickest();
    ds.serve_sickest();

    return 0;
}
