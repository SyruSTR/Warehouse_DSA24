#ifndef HASHMAP_H
#define HASHMAP_H
#include <iostream>
#include <string>



namespace Warehouse {

    struct Item {
        unsigned int itemID;
        std::string itemName;
        unsigned int price;
        unsigned int count;

        Item() : itemID(0), itemName(""), price(0), count(0) {}

        Item(int ItemId, const char * name, int price, int count) {
            this->itemID = ItemId;
            this->itemName = name;
            this->price = price;
            this->count = count;
        }

        bool operator==(const Warehouse::Item & item) {
            return this->itemID ==  item.itemID
                && this->count == item.count
                && this->itemName == item.itemName
                && this->price == item.price;
        }
    };

    template <class T>
    class Hashmap {
    private:

        struct Node {
            T value;
            bool state;

            Node(const T &value) : value(value), state(true) {}
        };
        const unsigned int DEFAULT_CAPACITY = 4;

        Node** table;
        unsigned int buffer_size_{};
        unsigned int size_{};
        unsigned int non_nullptr;
        double rehash_percent = 0.7;

    public:

        void printMap(){}
        void resize();
        void rehash();
        void increase();
        Hashmap();

        ~Hashmap();

        bool addItem(T& value);
        int removeItem();
        unsigned int getItemID(std::string itemName);
    };

    int hashFunction1(const Item& item, const int table_size) {
        return (((int)item.itemID << 8) * 100 / table_size) % table_size;
    }

    int hashFunction2(const Item& item, const int table_size) {
        return (((int)item.itemID + 100 % table_size) * 100 / table_size) % table_size;
    }

    template<typename T>
    Hashmap<T>::Hashmap() {
        table = new Node*[DEFAULT_CAPACITY];
        buffer_size_ = DEFAULT_CAPACITY;
        non_nullptr = 0;

        for (int i = 0; i < DEFAULT_CAPACITY; i++) {
            table[i] = NULL;
        }
    }

    template<class T>
    void Hashmap<T>::resize() {

        int past_buffer_size_ = buffer_size_;
        buffer_size_ *= 2;
        size_ = 0;
        non_nullptr = 0;
        Node** new_table = new Node*[buffer_size_];

        for(int i = 0; i < past_buffer_size_; i++) {
            new_table[i] = NULL;
        }

        std::swap(table, new_table);

        for (int i = 0; i < past_buffer_size_; i++) {
            if(new_table[i] && new_table[i]->state)
                addItem(new_table[i]->value);
        }

        for (int i = 0; i < past_buffer_size_; i++) {
            if(new_table[i])
                delete new_table[i];
        }
        delete new_table;
    }

    template<>
    void Hashmap<Item>::printMap() {

        std::cout << "Main info:" << std::endl;
        std::cout << "Size: " << size_ << std::endl;
        std::cout << "Non_nullptr_elements: " << non_nullptr << std::endl;
        std::cout << "Buffer size: " << buffer_size_ << std::endl;
        for (int i = 0; i < buffer_size_;i++) {
            if(table[i]) {
                Item item = table[i]->value;
                std::cout << item.itemID << item.itemName << "\n";
            }
        }
    }



    template<class T>
    bool Hashmap<T>::addItem(T &value) {
        //todo rehash
        if(this->size_ > this->buffer_size_ * this->rehash_percent)
            resize();


        int hash1 = hashFunction1(value, buffer_size_);
        int hash2 = hashFunction2(value, buffer_size_);
        int i = 0;
        int first_deleted = -1;
        while(table[hash1] != NULL && i < buffer_size_) {
            //value already exist, shouldn`t insert this value
            if(table[hash1]->value == value && table[hash1]->state) {
                return false;
            }
            if(!table[hash1]->state && first_deleted == -1) {
                first_deleted = hash1;
            }

            hash1 = (hash1 + hash2) % buffer_size_;
            ++i;
        }

        if(first_deleted == -1) {
            table[hash1] = new Node(value);
            non_nullptr++;
        }
        else {
            table[first_deleted]->value = value;
            table[first_deleted]->state = true;
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
};

#endif //HASHMAP_H
