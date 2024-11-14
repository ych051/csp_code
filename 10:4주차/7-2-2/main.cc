#include <iostream>
#include "print_info.h"
using namespace std;

void printObjectTypeInfo1(A* object){
    cout << object->getTypeInfo() << endl;
}

void printObjectTypeInfo2(A& object){
    cout << object.getTypeInfo() << endl;
}

int main(void){
    A* arr[3];
    
    arr[0] = new A();
    arr[1] = new B();
    arr[2] = new C();
    
    for(int i=0;i<3;i++){
        printObjectTypeInfo1(arr[i]);
        printObjectTypeInfo2(*arr[i]);
    }

    for(int i=0;i<3;i++){
        delete arr[i];
    }

    return 0;
}