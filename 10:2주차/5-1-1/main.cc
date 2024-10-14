#include "shapes.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(void){
    Shape shape;
    string input;
    char brush;
    int row,col;
    int lx,ly;
    int width,height;
    int side;
    cin >> col >> row;

    while (1){
        Canvas canvas(row,col);
        
        cin >> input;
        if(input=="quit"){
            break;
        }
        else if (input=="rect"){
            cin >> lx >> ly >> width >> height >> brush;
            Rectangle rect(lx,ly,width,height,brush);
            cout << "Area: " << rect.GetArea() << endl;
            cout << "Perimeter: " << rect.GetPerimeter() << endl;
            rect.Draw(&canvas);
        }
        else if (input=="square"){
            cin >> lx >> ly >> side >> brush;
            Square squ(lx,ly,side,brush);
            cout << "Area: " << squ.GetArea() << endl;
            cout << "Perimeter: " << squ.GetPerimeter() << endl;
            squ.Draw(&canvas);
        }
        canvas.Print();
    }
    return 0;
}