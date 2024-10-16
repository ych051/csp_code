#ifndef __SHAPES_H__
#define __SHAPES_H__

class Shape{
    public:
        Shape(double width, double height);
        virtual double getArea()=0;
    protected:
        double width, height;
};
class Triangle : public Shape{
    public:
        Triangle(double width,double height);
        double getArea();
};
//Implement Class Rectangle
class Rectangle : public Shape{
    public:
        Rectangle(double width,double height);
        double getArea();
};
#endif