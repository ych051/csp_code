#ifndef __CLASSES_H__
#define __CLASSES_H__

class A {
public:
    virtual void test();
    virtual ~A() {}
};

class B: public A{
public:
    void test() override;
};

class C: public B{
public:
    void test() override;
};

#endif