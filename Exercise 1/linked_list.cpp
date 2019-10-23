#include "linked_list.h"

template <typename T>
linked_list<T>::linked_list(): first(NULL), last(NULL), current(NULL) {}

template <typename T>
linked_list<T>::linked_list(const linked_list<T>& other): current(NULL)
{
    copy_list(other);
}

template <typename T>
void copy_list(const linked_list<T>& other){
    node<T>* p = other.first;
    node<T>* previous = p;
    while(p)
    {
        node<T>* q = new(node<T>);
        q->value = p->value;
        if(previous != p)
        {
            previous->next = q;
        }
        else
        {
            first = q;
        }
        q->next = NULL;
        previous = q;
        last = q;
        p = p->next;
    }
}

template <typename T>
linked_list<T>::~linked_list()
{
    del_list();
}

template <typename T>
void linked_list<T>::del(){
    current = first;
    node<T>* next;
    while(current)
    {
        next = current->next;
        delete current;
        current = next;
    }
    first = NULL;
    last= NULL;
    current = NULL;
}

template <typename T>
linked_list<T>& linked_list<T>::operator=(const linked_list<T>& other)
{

    if(this != &other){
        del();
        copy_list(other);
    }
    return *this;
}

template <typename T>
void linked_list<T>::start_iter(){
    current = first;
}

template <typename T>
node<T>* linked_list<T>::next(){
    node<T>* curr = current;
    current = current->next;
    return curr;
}

template <typename T>
T& linked_list<T>::get_current() const{
    return current->value;
}

template <typename T>
void linked_list<T>::add_last(const T& val){
    node<T>* temp = new node<T>;
    temp->value = val;
    temp->next = NULL;
    if(first == NULL){
        first = temp;
    }
    last->next = temp;
    last = temp;
}

template <typename T>
void linked_list<T>::move_n_pos(node<T>*& ptr, const size_t& n){
    for(int i = 0; i<n && ptr; i++){
        ptr = ptr->next;
    }
}

template <typename T>
void linked_list<T>::add_element_at(const T& val, const size_t& pos){
    node<T>* iter = first;
    for(int i = 0; i<pos-1 && iter; i++){
        iter = iter->next;
    }
    node<T>* p = new node<T>;
    p->value = val;
    p->next = iter->next;
    if(iter == last){
        last = p;
    }
    if(first == NULL){
        first = p;
    }
    iter->next = p;
}

template <typename T>
node<T>* linked_list<T>::operator[](int){
    node<T>* result = first;
    for(int i = 0; i<n && result; i++){
        result = result->next;
    }
    return result;
}

template <typename T>
void remove_element_from(const size_t& pos){
    node<T>*
}

int main() {

}












