#include <iostream>
#include "print_member.h"
using namespace std;

int main(void){
    A* arr[3];

    int A_pm;
    double B_pm;
    string C_pm;

    cin >> A_pm >> B_pm >> C_pm;

    arr[0] = new A(A_pm);
    arr[1] = new B(B_pm);
    arr[2] = new C(C_pm);

    for(int i=0;i<3;i++){
        arr[i]->print();
    }

    for(int i=0;i<3;i++){
        delete arr[i];
    }

    return 0;
}