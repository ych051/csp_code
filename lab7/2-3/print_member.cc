#include <iostream>
#include <string>
#include "print_member.h"

using namespace std;

A::A(int A){
    memberA = new int(A);
    cout << "new memberA" << endl;
}
A::~A(){
    delete memberA;
    cout << "delete memberA" << endl;
}
void A::print(){
    cout << "*memberA " << *memberA << endl;
}


B::B(double B): A(1){
    memberB = new double(B);
    cout << "new memberB" << endl;
}
B::~B(){
    delete memberB;
    cout << "delete memberB" << endl;
}
void B::print(){
    A::print();
    cout << "*memberB " << *memberB << endl;
}


C::C(string C): B(1.1){
    memberC = new string(C);
    cout << "new memberC" << endl;
}
C::~C(){
    delete memberC;
    cout << "delete memberC" << endl;
}
void C::print(){
    B::print();
    cout << "*memberC " << *memberC << endl;
}
