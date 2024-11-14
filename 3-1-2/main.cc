#include <iostream>
#include "shapes.h"
using namespace std;

int main(void){

    char word;

    while (1) {
        cout << "shape? " << endl;
        cin >> word;

        if (word == 'C') {
            int x, y, r;
            cin >> x >> y >> r;
            Circle circle;
            circle.setInfo(x, y, r);
            cout << "area: " << circle.getArea() << ", perimeter: " << circle.getPerimeter() << endl;
        }

        else if (word == 'R') {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            Rectangle rectangle;
            rectangle.setInfo(x1, y1, x2, y2);
            cout << "area: " << rectangle.getArea() << ", perimeter: " << rectangle.getPerimeter() << endl;
        }

        else if (word == 'Q') {
            break;
        }
    }
    return 0;
}