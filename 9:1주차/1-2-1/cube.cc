#include <iostream>
using namespace std;

int cube (const int* pd){
    int a =*pd;
    a=a*a*a;
    return a;
}

int main(void){
    int n;
    cin >> n;
    cout << cube(&n) << endl; 
    return 0;
}