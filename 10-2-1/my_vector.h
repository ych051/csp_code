#ifndef __MY_VECTOR_H__
#define __MY_VECTOR_H__
#include <iostream>

class MyVector {
    public:
        MyVector();
        MyVector(int length);
        ~MyVector();
        MyVector& operator=(const MyVector& b);
        MyVector operator+(const MyVector& b);
        MyVector operator-(const MyVector& b);
        MyVector operator+(const int b);
        MyVector operator-(const int b);
        friend std::ostream& operator<< (std::ostream& out, const MyVector& b);
        friend std::istream& operator>> (std::istream& in, MyVector& b);
    private:
        int length;
        int *a;
}; 
#endif