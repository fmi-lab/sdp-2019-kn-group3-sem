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
    node<T>* start;
    node<T>* last;

public:
    linked_list();
    linked_list(const linked_list&);
    linked_list& operator=(const linked_list&);
    ~linked_list();

    void add_last(const T& value);
    void add_element_at(const T& value, size_t pos);
    void remove_element_at(size_t pos);
};
