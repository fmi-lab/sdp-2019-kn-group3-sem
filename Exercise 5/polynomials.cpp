#include"polynomials.h"
#include<iostream>

void Polynomial::print() const
{
    list<Monomial>::const_iterator i = l.begin();
    for(;i!=l.end(); i++){
        if(i->coefficient > 0){
            cout<<" +";
        } else if (i->coefficient < 0){
            cout<<' ';
        }
        cout<<i->coefficient<<"x^"<<i->power;
    }
}

Polynomial Polynomial::operator+(const Monomial& mono)const{
    if(mono.coefficient == 0){
        return *this;
    }

    Polynomial p = *this;

    list<Monomial>::iterator i = p.l.begin();

    for(; i->power < mono.power && i != p.l.end(); i++);

    if(i != p.l.end()){
        if(i->power == mono.power){
            i->coefficient += mono.coefficient;
            if(i->coefficient == 0){
                p.l.erase(i);
            }
        } else {
            p.l.insert(i, mono);
        }
    } else {
        p.l.insert(i, mono);
    }

    return p;
}


Polynomial Polynomial::operator-(const Monomial& mono)const{
    return this->operator+(Monomial(mono.coefficient*(-1), mono.power));
}


int main(){
    Monomial m1(5, 1), m2(0, 2), m3(-5, 1), m4(2, 2);
    Polynomial p1;

    p1 = p1 + m1;
    p1 = p1 + m3;
    p1 = p1 + m2;
    p1 = p1 + m4;
    p1 = p1 - m4;


    p1.print();
}
