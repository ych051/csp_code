#ifndef __SHAPES_H__
#define __SHAPES_H__

#include <cmath>

class Canvas{
    public:
        Canvas(const size_t row, const size_t col);
        ~Canvas();
        bool DrawPixel(const int x, const int y, const char brush);//여기서 유효한 위치인지 판별
        void Print() const; //점 출력만 
        void Clear();
    private:
        size_t row, col;
        char **canvas;
};


class Shape {
    public:
        Shape();
        Shape(const size_t x, const size_t y, const char brush);
        double GetArea() { return 0; };
        int GetPerimeter() {return 0; };
        void Draw(Canvas *canvas) const {};
    protected:
        size_t x, y;
        char brush;
};

class Rectangle : public Shape{
    public:
        Rectangle(size_t x, size_t y, size_t width, size_t height, char brush);
        double GetArea();
        int GetPerimeter();
        void Draw(Canvas *canvas) const;
    private:
        size_t width,height;
};

class Square : public Shape{
    public:
        Square(size_t x, size_t y, size_t side, char brush);
        double GetArea();
        int GetPerimeter();
        void Draw(Canvas *canvas) const;
    private:
        int side;
}; 

#endif