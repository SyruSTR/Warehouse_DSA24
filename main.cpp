#include <iostream>

#include "Hashmap.h"

using namespace Warehouse;
int main() {
    Hashmap<Item> *map = new Hashmap<Item>();

    std::cout << "Enter a command, use '-h' for help" << std::endl;

    std::string command;
    //-h help
    //-a Add item
    //-r remove item
    //-p print hashmap
    //-q quit
    std::cin >> command;
    while( command != "-q") {
        if(command == "-h") {
            std::cout <<
                "This program can storage Items in the warehouse\n"
            << "Usage:\n"
            << "command \"-a\" Add item\nFormat for ItemID is number between 1 and 1,\n"
            << "for item name is simply word\\s\n"
            << "for price is number between 1 and 1\n"
            << "for count is number between 1 and 1\n"
            << "\ncommand \"-r\" - remove item from warehouse by itemID\n"
            << "\ncommand \"-p\" - print actual items in the warehouse\n"
            << "\ncommand \"-q\" - quit from the program\n"
            << std::endl;
        }
        else if(command == "-a") {
            std::cout << "ADD" << std::endl;
        }
        else if(command == "-r") {
            std::cout << "REMOVE" << std::endl;
        }
        else if(command == "-p") {
            std::cout << "PRINT" << std::endl;
        }
        else{
            std::cout << "Wrong operation" << std::endl;
        }
        std::cin >> command;
    }


    std::cout << "Goodbye!" << std::endl;


    // Item *item1 = new Item(123123,"GGWP",10,5);
    // Item *item2 = new Item(777263,"Hehe",50,1);
    // Item *item3 = new Item(123098,"NotHehe",100,100);
    // Item *item4 = new Item(454278984,"Something",500,2);
    //
    // map->addItem(*item1);
    // map->addItem(*item2);
    // map->addItem(*item3);
    // map->addItem(*item4);


    map->printMap();

    delete(map);

    return 0;
}

