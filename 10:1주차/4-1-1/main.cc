#include "zebra.h"
#include <iostream>
#include <string>
using namespace std;

int main(void){
    Zebra* zebra[10];
    string name;
    int age,numStripes;
    int count=0;
    while(count<10){
        cin >> name;
        if(name=="0"){
            break;
        }
        cin >> age >> numStripes;
        zebra[count] = new Zebra(name, age, numStripes);
        count++;
    }
    for (int i = 0; i < count; i++) {
        zebra[i]->printZebra();
        delete zebra[i];
    }
    return 0;
}