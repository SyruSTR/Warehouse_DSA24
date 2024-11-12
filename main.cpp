#include <iostream>

#include "Hashmap.h"

using namespace Warehouse;
int main() {
    Hashmap<Item> *map = new Hashmap<Item>();

    Item *item1 = new Item(123123,"GGWP",10,5);
    Item *item2 = new Item(777263,"Hehe",50,1);
    Item *item3 = new Item(123098,"NotHehe",100,100);
    Item *item4 = new Item(454278984,"Something",500,2);

    map->addItem(*item1);
    map->addItem(*item2);
    map->addItem(*item3);
    map->addItem(*item4);

    map->removeItem(*item1);

    map->printMap();

    delete(map);

    return 0;
}

