#include <iostream>
#include <limits.h>

#include "Hashmap.h"
#include <limits>

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

            std::cout << "Enter the itemID: ";
            if (!(std::cin >> tmpItem->itemID)) {
                std::cerr << "Invalid input for itemID!" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            std::cin.ignore();

            std::cout << "Enter the item name: ";
            std::getline(std::cin, tmpItem->itemName);

            std::cout << "Enter the price: ";
            if (!(std::cin >> tmpItem->price)) {
                std::cerr << "Invalid input for price!" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            std::cout << "Enter the count: \n";
            if (!(std::cin >> tmpItem->count)) {
                std::cerr << "Invalid input for count!" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

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

