#include <iostream>
using namespace std;

void rotateLeft(int* pa, int* pb, int* pc) 
{
    int nul = *pa;
    int* nll=&nul;
    *pa=*pb;
    *pb=*pc;
    *pc=*nll;
}

void rotateRight(int* pa, int* pb, int* pc) 
{
    int nul = *pc;
    int* nll=&nul;
    *pc=*pb;
    *pb=*pa;
    *pa=*nll;
}
int main(void) 
{
    char str;
    int a;
    int b;
    int c;
    int* pa;
    int* pb;
    int* pc;
    a=10;
    b=20;
    c=30;
    pa=&a;
    pb=&b;
    pc=&c;
    cout << a <<":"<< b <<":"<< c << endl;
    while(1){
        cin >> str;

        if (str=='L'){
            rotateLeft(pa,pb,pc);
        }
        else if (str=='R'){
            rotateRight(pa,pb,pc);
        }
        else if (str=='E'){
            break;
        }
        else{
            cout << "Error: Wrong input!"<< endl;
            break;
        }
        cout << a <<":"<< b <<":"<< c << endl;
    }
    return 0;
}