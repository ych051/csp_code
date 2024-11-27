#include "my_vector.h"

MyVector::MyVector(){
    length=0;
    a=nullptr;
}
MyVector::MyVector(int length){
    this->length=length;
    a= new int[length];
    for(int i=0;i<length;i++) a[i]=0;
}

MyVector::~MyVector(){
    delete[] a;
}

MyVector& MyVector::operator=(const MyVector& b){
    if (this == &b) {
        return *this;
    }

    delete[] a;

    length = b.length;
    a = new int[length];
    for (int i = 0; i < length; i++) {
        a[i] = b.a[i];
    }
    return *this;
}

MyVector MyVector::operator+(const MyVector& b){
    MyVector result(length);
    for (int i = 0; i < length; i++) {
        result.a[i] = this->a[i] + b.a[i];
    }
    return result;
}
MyVector MyVector::operator-(const MyVector& b){
    MyVector result(length);
    for (int i = 0; i < length; i++) {
        result.a[i] = this->a[i] - b.a[i];
    }
    return result;
}

MyVector MyVector::operator+(const int b){
    MyVector result(length);
    for (int i = 0; i < length; i++) {
        result.a[i] = this->a[i] + b;
    }
    return result;
}
MyVector MyVector::operator-(const int b){
    MyVector result(length);
    for (int i = 0; i < length; i++) {
        result.a[i] = this->a[i] - b;
    }
    return result;
}

std::ostream& operator<< (std::ostream& out, const MyVector& b){
    for(int i=0;i<b.length;i++) out << b.a[i] << ' ';
    return out;
}
std::istream& operator>> (std::istream& in, MyVector& b){
    for(int i=0;i<b.length;i++) in >> b.a[i];
    return in;
}