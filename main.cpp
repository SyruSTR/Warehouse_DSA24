#include <iostream>
#include <limits.h>

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
            //todo delete
            std::cout << "ADD" << std::endl;
            Warehouse::Item * tmpItem = new Warehouse::Item();
            char tmpStr[100];
            printf("Enter the itemID, its a number between 0 and %ui: ", INT_MAX);
            scanf("%d",&tmpItem->itemID);
            printf("Enter the item name: ");
            scanf("%99s", &tmpStr);
            tmpItem->itemName = tmpStr;
            printf("Enter the price number between 1 and %ui: ", INT_MAX);
            scanf("\n%ui\n",&tmpItem->price);
            printf("Enter the count number between 1 and %ui: ", INT_MAX);
            scanf("\n%ui\n",&tmpItem->count);

            if (map->addItem(*tmpItem))
                printf("Item added\n");
            else
                printf("Item with this name is exist\n");

            //debug,
            map->printMap();

        }
        else if(command == "-r") {
            std::cout << "REMOVE" << std::endl;
        }
        else if(command == "-p") {
            std::cout << "PRINT\n" << std::endl;
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


    delete(map);

    return 0;
}

