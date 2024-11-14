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



//Canvas 생성자
Canvas::Canvas(const size_t row, const size_t col){
    this->canvas_row=row;
    this->canvas_col=col;
    this->canvas = auto_alloc(row,col);
}
Canvas::~Canvas(){
    auto_delete(canvas,canvas_row,canvas_col);
}





//Canvas 함수
void Canvas::Resize(const size_t row, const size_t col){
    char** new_canvas = auto_alloc(row,col);
    size_t min_row = min(row, this->canvas_row);
    size_t min_col = min(col, this->canvas_col);
    for (size_t i = 0; i < min_row; i++) {
        for (size_t j = 0; j < min_col; j++) {
            new_canvas[i][j] = this->canvas[i][j];
        }
    }
    auto_delete(this->canvas, this->canvas_row, this->canvas_col);
    this->canvas = new_canvas;
    this->canvas_row = row;
    this->canvas_col = col;
}

bool Canvas::DrawPixel(const int row, const int col, const char brush){
    if(row>=canvas_row || row<0 || col>=canvas_col || col<0){
        return false;
    }
    canvas[row][col]=brush;
    return true;
}

void Canvas::Print() const { 
    cout << " ";
    for (int i = 0; i < this->canvas_col; ++i) cout << (i % 10); 
    cout << endl;
    for (int i = 0; i < this->canvas_row; ++i) { 
        cout << (i % 10);
        for (int j = 0; j < this->canvas_col; ++j) cout << this->canvas[i][j]; 
        cout << endl;
    } 
}

void Canvas::Clear() {
    this->canvas = init(this->canvas, this->canvas_row, this->canvas_col);
}



//모양
Shape::Shape(){
    col=0;
    row=0;
    brush='.';
}
Shape::Shape(const size_t row, const size_t col, const char brush){
    this->row=row;
    this->col=col;
    this->brush=brush;
}





//직사각형
Rectangle::Rectangle(size_t row, size_t col, size_t width, size_t height, char brush): Shape (row,col,brush){
    this->width=width;
    this->height=height;
}

void Rectangle::Draw(Canvas *canvas) const{
    for (size_t i = row; i < row + height; i++) {
        for (size_t j = col; j < col + width; j++) {
            if(!canvas->DrawPixel(i, j, brush)){
                continue;
            }
        }
    }
}
void Rectangle::printInfo() const{
    cout << " rect " << row << ' ' <<  col << ' ' << width << ' ' << height << ' ' <<  brush << endl;
}







//위삼각형
UpTriangle::UpTriangle(size_t row, size_t col, size_t height, char brush): Shape (row,col,brush){
    this->height=height;
}

void UpTriangle::Draw(Canvas *canvas) const{
    for(size_t i=0;i<height;i++){
        for(size_t j=col-i;j<=col+i;j++){
            if(!canvas->DrawPixel(row+i, j, brush)){
                continue;
            }
        }
    }
}
void UpTriangle::printInfo() const{
    cout << " tri_up " << row << ' ' << col << ' ' << height << ' ' <<  brush << endl;
}






//아래삼각형
DownTriangle::DownTriangle(size_t row, size_t col, size_t height, char brush): Shape (row,col,brush){
    this->height=height;
}

void DownTriangle::Draw(Canvas *canvas) const{
    for(size_t i=0;i<height;i++){
        for(size_t j=col-i;j<=col+i;j++){
            if(!canvas->DrawPixel(row-i, j, brush)){
                continue;
            }
        }
    }
}
void DownTriangle::printInfo() const{
    cout << " tri_down " << row << ' ' << col << ' ' << height << ' ' <<  brush << endl;
}







//다이아몬드
Diamond::Diamond(size_t row, size_t col, size_t distance_CenterPoint_Vertex, char brush): Shape (row,col,brush){
    this->distance_CenterPoint_Vertex=distance_CenterPoint_Vertex;
}

void Diamond::Draw(Canvas *canvas) const{
    for(size_t i=0;i<distance_CenterPoint_Vertex+1;i++){
        for(size_t j=col-i;j<=col+i;j++){
            if(!canvas->DrawPixel(row+i, j, brush)){
                continue;
            }
        }
    }
    for(size_t i = 1; i <= distance_CenterPoint_Vertex; i++) {
        for(size_t j = col - (distance_CenterPoint_Vertex - i); j <= col + (distance_CenterPoint_Vertex - i); j++) {
            if (!canvas->DrawPixel(row + distance_CenterPoint_Vertex + i, j, brush)) {
                continue;
            }
        }
    }
}
void Diamond::printInfo() const {
    cout << " diamond " << row << ' ' << col << ' ' << distance_CenterPoint_Vertex << ' ' <<  brush << endl;
}