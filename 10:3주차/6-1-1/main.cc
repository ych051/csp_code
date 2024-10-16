#include <iostream>
#include "shapes.h"
using namespace std;
int main(void){
    Shape* shape[10];
    char key;
    int width,height;
    int count=0;
    while (1){
        cin >> key;
        if(key=='0'){
            break;
        }
        cin >> width >> height;
        
        if (key=='r' && count<10){
            shape[count]= new Rectangle(width,height);
        }
        else if (key=='t' && count<10){
            shape[count]= new Triangle(width,height);
        }
        count++;
    }
    if(count>10){
        count=10;
    }
    for (int i = 0; i < count; i++){
        cout <<shape[i]->getArea() << endl;
        delete shape[i];
    }
    return 0;
}