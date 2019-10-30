#include<iostream>
#include<list>

using namespace std;

void print_list_int(const list<int>& l){
    list<int>::const_iterator i = l.begin();
    for(; i!=l.end(); i++){
        cout<<*i<<' ';
    }
    cout<<endl;
}

template <typename T>
void print_list(const list<T>& l){
    typename list<T>::const_iterator i = l.begin();
    for(; i!=l.end(); i++){
        cout<<*i<<' ';
    }
    cout<<endl;
}

int main(){
    list<int> l;

    l.push_back(5);
    l.push_front(4);
    l.push_back(3);
    l.push_back(2);
    l.push_back(1);

    cout<<l.front()<<endl;
    print_list_int(l);
}
