#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include<list>

using namespace std;

struct Monomial{
    int coefficient;
    int power;

    Monomial(int c, int p): coefficient(c), power(p){}
};

class Polynomial{
private:
    list<Monomial> l;

public:
    void print()const;

    Polynomial operator+(const Monomial&)const;
    Polynomial operator-(const Monomial&)const;
    Polynomial operator+(const Polynomial&)const;
    Polynomial operator-(const Polynomial&)const;
};

#endif // POLYNOMIAL_H
