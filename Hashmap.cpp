#include "Hashmap.h"

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;
using namespace Warehouse;


int hashFunction1(const Item& item, const int table_size) {
    return ((int)item.itemID << 8) * 100 / table_size % table_size;
}

int hashFunction2(const Item& item, const int table_size) {
    return ((int)item.itemID + 100 % table_size) * 100 / table_size;
}

void Hashmap<Item>::printMap() {
    for (int i = 0; i < buffer_size_;i++) {
        if(table[i]) {
            Item item = table[i]->value;
            std::cout << item.itemID << item.itemName << "\n";
        }
    }
}

template<class  T>
Hashmap<T>::Hashmap() {
    table = new Node*[DEFAULT_CAPACITY];
    buffer_size_ = DEFAULT_CAPACITY;
    non_nullptr = 0;

    for (int i = 0; i < DEFAULT_CAPACITY; i++) {
        table[i] = NULL;
    }
}

template<class T>
bool Hashmap<T>::addItem(T& value) {
    //todo rezise and rehash

    int hash1 = hashFunction1(value, buffer_size_);
    int hash2 = hashFunction2(value, buffer_size_);
    int i = 0;
    int first_deleted = -1;
    while(table[hash1] != NULL && i < buffer_size_) {
        //value already exist, shouldn`t insert this value
        if(table[hash1]->itemID == value && table[hash1]->state) {
            return false;
        }
        if(!table[hash1]->state && first_deleted == -1) {
            first_deleted = hash1;
        }

        hash1 = (hash1 + hash2) % buffer_size_;
    }

    if(first_deleted == -1) {
        table[hash1] = new Node(value);
        non_nullptr++;
    }
    else {
        table[hash1]->itemID = value;
        table[hash1]->state = true;
    }
    size_++;

    return true;
}

template<class T>
Hashmap<T>::~Hashmap() {
    for (int i = 0; i < buffer_size_; i++) {
        delete table[i];
    }
    delete table;
}
