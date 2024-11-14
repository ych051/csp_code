#include <iostream>
#include "classes.h"
using namespace std;

int main(void){
    A* arr[3];
    
    arr[0] = new A();
    arr[1] = new B();
    arr[2] = new C();
    
    for(int i=0;i<3;i++){
        arr[i]->test();
    }

    for(int i=0;i<3;i++){
        delete arr[i];
    }

    return 0;
}