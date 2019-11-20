#include"tree.h"

template <typename T>
using Predicate = bool (*)(T const&);

template <typename T>
tree<T>::tree(T value, int weight): value(value), weight(weight){}

template <typename T>
void tree<T>::add_child(const T& value, const int& weight){
    tree<T>* child = new tree<T>(value, weight);
    children.push_back(child);
}

template <typename T>
void tree<T>::remove_children(){
    while(!children.empty()){
        children[0]->remove_children();
        delete children[0];
        children.erase(children.begin());
    }
}

template <typename T>
void tree<T>::remove_nth_child(const size_t& pos){
    children[pos]->remove_children();
    delete children[pos];
    children.erase(children.begin() + pos);
}

template <typename T>
void tree<T>::remove_only_nth_child(const size_t& pos){
    int i = pos+1;
    tree<T>* child = children[pos];
    for(tree<T>* grand_child : child->children){
        children.insert(children.begin() + i, grand_child);
        i++;
    }
    children[pos]->children.clear();
    delete children[pos];
    children.erase(children.begin() + pos);
}

template <typename T>
void tree<T>::print(size_t level)const{
    for(int i = 0; i<level; i++){
        cout<<'\t';
    }
    cout<<'('<<value<<','<<weight<<")\n";
    ++level;
    for(tree<T>* child : children){
        child->print(level);
    }
}

template <typename T>
void tree<T>::copy(const tree<T>& other){
    value = other.value;
    weight = other.weight;
    for(tree<T>* child : other.children){
        tree<T>* new_child = new tree<T>(child->value, child->weight);
        children.push_back(new_child);
        children.back()->copy(*child);
    }
}

template <typename T>
tree<T>::tree(const tree<T>& other){
    copy(other);
}

template <typename T>
tree<T>& tree<T>::operator=(const tree<T>& other){
    if(this != &other){
        remove_children();
        copy(other);
    }
    return *this;
}

template <typename T>
tree<T>::~tree(){
    remove_children();
}

template <typename T>
void filter_helper(tree<T>& t, Predicate<T> p){
    for(int i = 0; i<t.children.size(); i++){
        filter_helper(*t.children[i], p);
        if(!p(t.children[i]->value)){
            t.remove_only_nth_child(i);
            i--;
        }
    }
}

template <typename T>
tree<T> filter(const tree<T>& t, Predicate<T> p){
    tree<T> result(t);
    filter_helper(result, p);
    return result;
}

bool isOdd(int const& x)
{
    return x%2 != 0;
}

int main(){
    tree<int> t1(1,5);
    t1.add_child(2,10);
    t1.add_child(3,15);
    t1.add_child(8,40);
    t1.add_child(9,45);
    t1.children[1]->add_child(4,20);
    t1.children[1]->add_child(5,25);
    t1.children[1]->add_child(6,30);
    t1.children[1]->add_child(7,35);
    t1.children[2]->add_child(10,50);
    t1.children[2]->add_child(11,55);

    t1.print();

    tree<int> t2 = filter(t1, isOdd);

    cout<<"--------\n";
    t2.print();

}
