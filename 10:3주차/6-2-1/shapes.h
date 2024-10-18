#ifndef __SHAPES_H__
#define __SHAPES_H__

#include <cmath>

class Canvas{
    public:
        Canvas(const size_t canvas_row, const size_t canvas_col);
        ~Canvas();
        void Resize(const size_t canvas_row, const size_t canvas_col);
        bool DrawPixel(const int row, const int col, const char brush);
        void Print() const;
        void Clear();
    private:
        size_t canvas_row, canvas_col;
        char **canvas;
};

class Shape {
    public:
        Shape();
        Shape(const size_t row, const size_t col, const char brush);
        virtual void Draw(Canvas *canvas) const = 0;
        virtual void printInfo() const = 0;
    protected:
        size_t row, col;
        char brush;
};

class Rectangle : public Shape{
    public:
        Rectangle(size_t row, size_t col, size_t width, size_t height, char brush);
        void Draw(Canvas *canvas) const;
        void printInfo() const;
    private:
        size_t width,height;
};

class UpTriangle : public Shape{
    public:    
        UpTriangle(size_t row, size_t col, size_t height, char brush);
        void Draw(Canvas *canvas) const;
        void printInfo() const;
    private:
        size_t height;
};

class DownTriangle : public Shape{
    public:
        DownTriangle(size_t row, size_t col, size_t height, char brush);
        void Draw(Canvas *canvas) const;
        void printInfo() const;
    private:
        size_t height;
};

class Diamond : public Shape{
    public:
        Diamond(size_t row, size_t col, size_t distance_CenterPoint_Vertex, char brush);
        void Draw(Canvas *canvas) const;
        void printInfo() const;
    private:
        size_t distance_CenterPoint_Vertex;
};

#endif