#include "animal.h"
#include <iostream>
#include <string>
using namespace std;

Animal::Animal(string _name, int _age){
    name=_name;
    age=_age;
}

Zebra::Zebra(string _name, int _age,int numStripes):Animal(name,age){
    this->numStripes=numStripes;
}
void Zebra::printInfo(){
    cout << "Zebra, Name: "<< name <<", Age: "<< age <<", Number of stripes: "<< numStripes <<endl;
}
Cat::Cat(string _name, int _age,string favoriteToy):Animal(name,age){
    this->favoriteToy=favoriteToy;
}
void Cat::printInfo(){
    cout << "Cat, Name: "<< name <<", Age: "<< age <<", Favorite toy: "<< favoriteToy << endl;
}