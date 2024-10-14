#include "vehicle.h"
#include <iostream>
#include <string>

Vehicle::Vehicle(){
    brand="Unknown";
    year=0;
    mileage=0;
}

Vehicle::Vehicle(std::string _brand, int _year, int _mileage){
    brand=_brand;
    year=_year;
    mileage=_mileage;
}

void Vehicle::printVehicle(){
    std::cout << "Brand: " << brand << ", Year: " << year << ", Mileage: " << mileage << "km" << std::endl;
}

void Vehicle::updateMileage(int newMileage){
    mileage=newMileage;
}

void Vehicle::updateMileage(int currentMileage, int distance){
    mileage = currentMileage+distance;
}