#include<iostream>
#include<list>

using namespace std;

template <typename T>
void print_list(const list<T>& l){
    typename list<T>::const_iterator i = l.begin();
    for(; i!=l.end(); i++){
        cout<<*i<<' ';
    }
    cout<<endl;
}

template <typename T>
void merge_lists(const list<T> l1, const  list<T> l2, list<T>& result){
    result.clear();

    typename list<T>::const_iterator i1 = l1.begin();
    typename list<T>::const_iterator i2 = l2.begin();

    while(i1 != l1.end() && i2!= l2.end()){
        if(*i1 < *i2){
            result.push_back(*i1);
            i1++;
        } else{
            result.push_back(*i2);
            i2++;
        }
    }

    while(i1 != l1.end()){
        result.push_back(*i1);
        i1++;
    }
    while(i2 != l2.end()){
        result.push_back(*i2);
        i2++;
    }
}

template <typename T>
void merge_sort(list<T>& l){
    typename list<T>::iterator i = l.begin();

    list<T> l1, l2;

    while(i != l.end()){
        l1.push_back(*i);
        i++;
        if(i != l.end()){
            l2.push_back(*i);
            i++;
        }
    }

    if(l1.size() != 1){
        merge_sort(l1);
    }

    if(l2.size() != 1){
        merge_sort(l2);
    }

    merge_lists(l1, l2, l);
}

int main(){
    list<int> l1 = {5,10,15,20};
    list<int> l2 = {2, 4, 8, 16, 32};

    list<int> merged;

    merge_lists(l1, l2, merged);

    print_list(merged);

    list<int> l = {42, 0, 5, -10, 8, 13, -5, 3};

    merge_sort(l);

    print_list(l);
}
