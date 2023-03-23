#include <iostream>
#include "car_catalog.h"
using namespace std;

int main() {
    Car Opel("AAAA",100,2,'B');
    Car VW("bbbb",120,2,'B');
    Car Peugot("cccc",130,2,'B');
    Car Mazda("dddd",140,2,'B');
    Car Mercedes("eeee",150,5,'B');
    Car BMW("ffff",160,2,'B');
    CarCatalog myCatalog;
    
    
    myCatalog.insert(Mazda);
    myCatalog.insert(Mercedes);
    myCatalog.insert(BMW);
    myCatalog.display();
    myCatalog.insert(Opel);
    myCatalog.insert(VW);
    myCatalog.insert(Peugot);
    myCatalog.display();
    
    return 0;
}
