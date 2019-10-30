#ifndef PRINT_LIST
#define PRINT_LIST

#include<iostream>
#include<list>

template <typename T>
void print_list(const std::list<T>& l){
    typename std::list<T>::const_iterator i = l.begin();
    for(; i!=l.end(); i++){
        std::cout<<*i<<' ';
    }
    std::cout<<std::endl;
}

#endif // PRINT_LIST
