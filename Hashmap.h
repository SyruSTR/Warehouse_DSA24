#ifndef HASHMAP_H
#define HASHMAP_H
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
    };

    static int hashFunction1(const Item& item, int table_size) {}
    static int hashFunction2(const Item& item, int table_size) {}

    template <class T>
    class Hashmap {
    private:

        struct Node {
            T value;
            bool state;

            Node(const T &value) : value(value), state(false) {}
        };
        const unsigned int DEFAULT_CAPACITY = 16;

        Node** table;
        unsigned int buffer_size_{};
        unsigned int size_{};
        unsigned int non_nullptr;

    public:

        void printMap(){}
        void resize();
        void increase();
        Hashmap();

        ~Hashmap();

        bool addItem(T& value);
        int removeItem();
        unsigned int getItemID(std::string itemName);
    };
};

#endif //HASHMAP_H
