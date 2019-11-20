#ifndef TREE_H
#define TREE_H
#include<iostream>
#include<vector>

using namespace std;

template <typename T>
struct tree{
    T value;
    int weight;
    vector<tree<T>*> children;

    void copy(tree<T>& other);
    void del();

    tree(const tree<T>&);
    tree<T>& operator=(const tree<T>&);
//    ~tree();

    tree(T = T(), int = 0);
    void add_child(const T&, const int&);
    void remove_children();
    void remove_nth_child(const size_t&);

    void print(size_t = 0)const;
};

#endif // TREE_H
