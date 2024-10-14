#include "shapes.h"
#include <iostream>
using namespace std;

static char **init(char **matrix, const size_t row, const size_t col) {
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            matrix[i][j] = '.';
    return matrix;
}
static char **auto_alloc(const size_t row, const size_t col) {
    char **matrix = new char*[row];
    for (int i = 0; i < row; ++i) matrix[i] = new char[col];
        matrix = init(matrix, row, col);
    return matrix;
}
static void auto_delete(char **matrix, const size_t row, const size_t col) {
    for (int i = 0; i < row; ++i) delete[] matrix[i];
    delete[] matrix;
}

Canvas::Canvas(const size_t row, const size_t col){
    this->row=row;
    this->col=col;
    this->canvas = auto_alloc(row,col);
}
Canvas::~Canvas(){
    auto_delete(canvas,row,col);
}
bool Canvas::DrawPixel(const int x, const int y, const char brush){
    if(x>=row || x<0 || y>=col || y<0){
        return false;
    }
    canvas[x][y]=brush;
    return true;
}
void Canvas::Print() const {
    for (int i = 0; i < this->col; ++i) cout << (i);
    cout << endl;
    for (int i = 0; i < this->row; ++i) {
        cout << (i);
        for (int j = 0; j < this->col; ++j) cout << this->canvas[i][j];
        cout << endl;
    }
}
void Canvas::Clear() {
    this->canvas = init(this->canvas, this->row, this->col);
}

//모양
Shape::Shape(){
    x=0;
    y=0;
    brush='.';
}
Shape::Shape(const size_t x, const size_t y, const char brush){
    this->x =x;
    this->y=y;
    this->brush=brush;
}

//직사각형
Rectangle::Rectangle(size_t x, size_t y, size_t width, size_t height, char brush): Shape (x,y,brush){
    this->width=width;
    this->height=height;
}
double Rectangle::GetArea() {
    return width*height;
}
int Rectangle::GetPerimeter() {
    return 2*(width+height);
}
void Rectangle::Draw(Canvas *canvas) const{
    for (size_t i = y; i < y + height; i++) {
        for (size_t j = x; j < x + width; j++) {
            if(!canvas->DrawPixel(i, j, brush)){
                continue;
            }
        }
    }
}

//정사각형
Square::Square(size_t x, size_t y, size_t side, char brush): Shape (x,y,brush){
    this->side=side;
}
double Square::GetArea(){
    return side*side;
}
int Square::GetPerimeter(){
    return 4*side;
}
void Square::Draw(Canvas *canvas) const{
    for (size_t i = y; i < y + side; i++) {
        for (size_t j = x; j < x + side; j++) {
            if(!canvas->DrawPixel(i, j, brush)){
                continue;
            }
        }
    }
}