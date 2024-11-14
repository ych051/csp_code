#include "shapes.h"
#include <vector>
int main(void){
    double tri_width,tri_height,sqr_width,sqr_height;
    cin >> tri_width >> tri_height;
    cin >> sqr_width >> sqr_height;
    vector<Shape*> shape;
    shape.push_back(new Triangle(tri_width,tri_height));
    shape.push_back(new Rectangle(sqr_width,sqr_height));
    
    for(int i=0;i<shape.size();i++){
        cout << shape[i]->getArea() << endl;
    }
    for(int i=0;i<shape.size();i++){
        delete shape[i];
    }
    return 0;
}