#include "shapes.h"
#include <cmath>


//Rectangle
void Circle::setInfo(int x, int y, int r){
    xpos=x;
    ypos=y;
    radius=r;
}

double Circle::getArea(){
    return 3.14*radius*radius;
}

double Circle::getPerimeter(){
    return 3.14*2*radius;
}

// Rectangle
void Rectangle::setInfo(int x1, int y1, int x2, int y2){
    xpos1=x1;
    ypos1=y1;
    xpos2=x2;
    ypos2=y2;
}

double Rectangle::getArea(){
    return abs(xpos1-xpos2)*abs(ypos1-ypos2);
}

double Rectangle::getPerimeter(){
    return 2*(abs(xpos1-xpos2)+abs(ypos1-ypos2));
}