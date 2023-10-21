#pragma once
#include <cstdlib>
#include <iostream>
#define EMPTY_LISTNODE 101
#define OUT_OF_BOUNDS  102

namespace star {
template <typename T> class list_node {
public:
    list_node()                             = default;
    list_node(list_node &&)                 = default;
    list_node(const list_node &)            = default;
    list_node &operator=(list_node &&)      = default;
    list_node &operator=(const list_node &) = default;
    ~list_node()                            = default;

    inline T at(const unsigned long long &&index) const {
        if (this->headNode.begin == nullptr) {
            std::cerr << "*** Visit empty listnode! ***\n";
            exit(EMPTY_LISTNODE);
        } else if (index >= this->headNode.lenger) {
            std::cerr << "*** Index out of bounds! ***\n";
            exit(OUT_OF_BOUNDS);
        }
        node *get;
        if (index <= this->headNode.lenger / 2) {
            get = this->headNode.begin;
            for (unsigned long long i = 0; i < index; ++i) {
                get = get->next;
            }
        } else {
            get = this->headNode.end;
            for (unsigned long long i = 0; i < index; ++i) {
                get = get->prev;
            }
        }
        return get->data;
    }

    inline T &operator[](const unsigned long long &&index) const {
        node *get;
        if (index <= this->headNode.lenger / 2) {
            get = this->headNode.begin;
            for (unsigned long long i = 0; i < index; ++i) {
                get = get->next;
            }
        } else {
            get = this->headNode.end;
            for (unsigned long long i = 0; i < index; ++i) {
                get = get->prev;
            }
        }
        return get->data;
    }

    inline void push_back(T &&value) {
        if (this->headNode.begin == nullptr) {
            this->headNode.end   = new node({nullptr, value, nullptr});
            this->headNode.begin = this->headNode.end;
            ++this->headNode.lenger;
            return;
        }
        node *temp               = new node({this->headNode.end->prev, value, nullptr});
        this->headNode.end->next = temp;
        temp->prev               = this->headNode.end;
        this->headNode.end       = temp;
        ++this->headNode.lenger;
    }

private:
    struct node {
        node *prev;
        T     data;
        node *next;
    };
    struct {
        node              *begin  = nullptr;
        unsigned long long lenger = 0;
        node              *end    = nullptr;
    } headNode;
};
}
#undef OUT_OF_BOUNDS
#undef EMPTY_LISTNODE
