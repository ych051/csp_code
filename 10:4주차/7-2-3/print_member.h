#ifndef __PRINT_MEMBER_H__
#define __PRINT_MEMBER_H__
#include <string>
using namespace std;
class A {
public:
    A(int A);
    virtual ~A();
    virtual void print();
private:
    int* memberA;
};

class B: public A{
public:
    B(double B);
    virtual ~B();
    void print() override;
private:
    double* memberB;
};

class C: public B{
public:
    C(string C);
    virtual ~C();
    void print() override;
private:
    string* memberC;
};

#endif