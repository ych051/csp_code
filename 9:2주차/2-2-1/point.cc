#include <iostream>
using namespace std;

typedef struct{
       int xpos;
       int ypos;
}Point;

Point getScalePoint(Point* p, int s){
    p->xpos=p->xpos*s;
    p->ypos=p->ypos*s;
    return *p;
}

void swapPoints(Point* p1, Point* p2){
    Point swap;
    swap=*p1;
    *p1= *p2;
    *p2= swap;    
}

int main(void) {
    Point pa1,pa2;
    int mul1,mul2;
    cin >> pa1.xpos >> pa1.ypos >> mul1 ;
    cin >> pa2.xpos >> pa2.ypos >> mul2 ;
    cout << "Calling getScalePoint() for (" << pa1.xpos << ", "<< pa1.ypos <<")"<< endl;
    getScalePoint(&pa1,mul1);
    cout << "Calling getScalePoint() for (" << pa2.xpos << ", "<< pa2.ypos <<")"<< endl;
    getScalePoint(&pa2,mul2);
    cout << "Calling swapPoints()"<<endl;
    swapPoints(&pa1,&pa2);
    cout << "P1: " << pa1.xpos << " "<< pa1.ypos << endl;
    cout << "P2: " << pa2.xpos << " "<< pa2.ypos << endl;
    return 0;
}