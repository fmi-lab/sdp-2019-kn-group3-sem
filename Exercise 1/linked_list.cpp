#include "linked_list.h"

template <typename T>
linked_list<T>::linked_list(): start(NULL), last(NULL){}


template <typename T>
linked_list<T>::linked_list(const linked_list& other){
    node<T>* current = other.first;
    node<T>* previous = current;
    while(current){
        node<T>* p = new(node<T>);
        p->value = current->value;
        if(previous != current){
            previous->next = p;
        }
        previous = p;
        last = p;
        current = current->next;
    }
    last->next = NULL;
}

int main(){}
