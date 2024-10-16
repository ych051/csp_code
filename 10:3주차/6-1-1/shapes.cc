#include "shapes.h"
#include <iostream>
using namespace std;

Shape::Shape(double width, double height){
    this->width=width;
    this->height=height;
}

Triangle::Triangle(double width,double height):Shape(width,height){}

double Triangle::getArea(){
    return (width*height)/2;
}

Rectangle::Rectangle(double width,double height):Shape(width,height){}
double Rectangle::getArea(){
    return width*height;
}