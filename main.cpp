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
    //-c calculate item
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
            << "\ncommand \"-pm\" - print info about map\n"
            << "\ncommand \"-c\" - calculate item cost by ItemId\n"
            << "\ncommand \"-q\" - quit from the program\n"
            << std::endl;
        }
        else if(command == "-a") {
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

            if (!map->addItem(*tmpItem))
                printf("Item with this name isnt exist\n");
        }
        else if(command == "-r") {
            std::cout << "REMOVE" << std::endl;
            unsigned int removingItemId;
            printf("Enter the itemID to remove from the warehouse by itemID\n");
            scanf("%ui",&removingItemId);

            if (!map->removeItem(removingItemId))
                std::cout << "Item with this id isnt exist\n";
        }
        else if(command == "-p") {
            map->printMap();
        }
        else if(command == "-c") {
            int calculatingItemId;
            printf("Enter the itemID to calculate cost by itemID\n");
            std::cin >> calculatingItemId;
            auto item = map->findItem(calculatingItemId);

            if (item) {
                std::cout << "Item price: " << item->value.price * item->value.count << std::endl;
            }
            else {
                std::cout << "Item with this id isnt exist\n";
            }
        }
        else if (command == "-pm") {
            map->printInfo();
        }
        else{
            std::cout << "Wrong operation" << std::endl;
        }
        std::cin >> command;
    }


    delete(map);

    return 0;
}

