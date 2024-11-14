#ifndef __PRINT_INFO_H__
#define __PRINT_INFO_H__
#include <string>
using namespace std;
class A {
public:
    virtual string getTypeInfo();
    virtual ~A() {}
};

class B: public A{
public:
    string getTypeInfo() override;
};

class C: public B{
public:
    string getTypeInfo() override;
};

#endif