#ifndef LINKED_LIST_HEADER
#define LINKED_LIST_HEADER

#include<iostream>

using namespace std;

template <typename T>
struct node{
    T value;
    node<T>* next;
};

template <typename T>
class linked_list{
private:
    node<T>* first;
    node<T>* last;
    node<T>* current;

    void del_list();
    void copy_list(const linked_list<T>&){

public:
    linked_list();
    linked_list(const linked_list<T>&);
    linked_list<T>& operator=(const linked_list<T>&);
    ~linked_list();

    void start_iter();
    node<T>* next();
    T& get_current() const;
    void add_last(const T&);
    void add_element_at(const T&, const size_t&);
    void remove_element_from(const size_t&);
    node<T>* operator[](int);

};

#endif // LINKED_LIST_HEADER
