#include <iostream>
#include "animal.h"
#include <string>
using namespace std;

int main(void){
    Animal* animal[10];
    char key;
    int age,stripes;
    string name,toy;
    int count=0;
    while (1){
        cin >> key;
        if(key=='0'){
            break;
        }
        
        if (key=='z' && count<10){
            cin >> name >> age >> stripes;
            animal[count]= new Zebra(name,age,stripes);
        }
        else if (key=='c' && count<10){
            cin >> name >> age >> toy;
            animal[count]= new Cat(name,age,toy);
        }
        count++;
    }
    if(count>10){
        count=10;
    }
    for (int i = 0; i < count; i++){
        animal[i]->printInfo();
        delete animal[i];
    }
    return 0;
}