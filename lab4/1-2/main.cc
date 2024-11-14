#include "vehicle.h"
#include <iostream>
#include <string>
using namespace std;

int main(void){
    Vehicle* vehicle[10];
    string brand;
    int year,mileage;
    int count=0;

    while(count<10){
        cin >> brand;
        if(brand=="0"){
            break;
        }
        cin >> year >> mileage;
        vehicle[count] = new Vehicle(brand, year, mileage);
        count++;
    }
    
    string choice;
    int vehicle_num,Mileage_1,Mileage_2;
    while(1){
        cout << "Update?"<<endl;
        cin >> choice;
        if(choice=="y"){
            cin >> vehicle_num >> Mileage_1;
            if (cin.peek() =='\n'){
                vehicle[vehicle_num]->updateMileage(Mileage_1);
            }
            else {
                cin >> Mileage_2;
                vehicle[vehicle_num]->updateMileage(Mileage_1,Mileage_2);
            }
            for (int i = 0; i < count; i++) {
                vehicle[i]->printVehicle();
            }
        }
        else{
            break;
        }
    }
    for (int i = 0; i < count; i++) {
        delete vehicle[i];
    }
    return 0;
}