#include<iostream>
using namespace std;

template <typename T>
struct dllnode{
    T value;
    dllnode<T>* next;
    dllnode<T>* previous;
};

template <typename T>
int count_x(const dllnode<T>* l, T x){
    dllnode<T>* temp = l;
    int counter = 0;
    while(temp){
        if (temp->value == x){
            counter ++;
        }
        temp = temp->next;
    }
}

dllnode<int>* range (int x, int y){
    dllnode<int>* l;
    dllnode<int>* temp;
    l = temp;
    dllnode<int>* prev;
    prev = temp;
    while(x<=y){
        temp = new dllnode<int>;
        prev->next = temp;
        temp->value = x;
        prev = temp;
        x++;
    }
    return l;
}

int main(){
    dllnode<int>* dll = range(1,5);
    while(dll){
        cout<<dll->value;
        dll = dll->next;
    }
}
