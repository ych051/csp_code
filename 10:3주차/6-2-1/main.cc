#include "shapes.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(void){
    Shape* shape[10];
    int shape_Count=0;
    int delete_Shape_info;

    string command,input_Shape;
    char brush;

    int canvas_row,canvas_col;

    int Top_Left_Row,Top_Left_Col;
    int Width, Height;
    int Vertex_Row, Vertex_Col;
    int distance_CenterPoint_Vertex;

    cin >> canvas_row >> canvas_col;
    Canvas canvas(canvas_col,canvas_row);
    canvas.Print();

    while (1){

        cin >> command;// 1. quit, 2. add 3. draw, 4. resize, 5. dump, 6.delete 

        if(command=="quit"){
            break;
        }

        else if(command=="add"){
            if(shape_Count>=10){
                break;
            }
            cin >> input_Shape; //1. rect, 2. tri_up, 3.tri_down, 4.diamond
            if(input_Shape=="rect"){ //{top-left row} {top-left col} {width} {height} {brush}
                cin >> Top_Left_Row >> Top_Left_Col >> Width >> Height >> brush;
                shape[shape_Count]= new Rectangle(Top_Left_Row,Top_Left_Col,Width,Height,brush);
                shape[shape_Count]->Draw(&canvas);
                shape_Count++;
            }
            else if(input_Shape=="tri_up"){ //{vertex-row} {vertex-col} {height} {brush}
                cin >> Vertex_Row >> Vertex_Col >> Height >> brush;
                shape[shape_Count]= new UpTriangle(Vertex_Row,Vertex_Col,Height,brush);
                shape_Count++;
            }
            else if(input_Shape=="tri_down"){ //{vertex-row} {vertex-col} {height} {brush}
                cin >> Vertex_Row >> Vertex_Col >> Height >> brush;
                shape[shape_Count]= new DownTriangle(Vertex_Row,Vertex_Col,Height,brush);
                shape_Count++;
            }
            else if(input_Shape=="diamond"){ //{vertex-row} {vertex-col} {distance between center point and vertex} {brush}
                cin >> Vertex_Row >>Vertex_Col >> distance_CenterPoint_Vertex >> brush;
                shape[shape_Count]= new Diamond(Vertex_Row,Vertex_Col,distance_CenterPoint_Vertex,brush);
                shape_Count++;
            }
        }

        else if(command=="draw"){
            canvas.Clear();
            for(int i=0;i<shape_Count;i++){
                shape[i]->Draw(&canvas);
            }
            canvas.Print();
        }

        else if(command=="resize"){
            cin >> canvas_col >> canvas_row;
            canvas.Resize(canvas_row,canvas_col);
        }

        else if(command=="dump"){
            for(int i=0;i<shape_Count;i++){
                cout << i;
                shape[i]->printInfo();
            }
        }

        else if(command=="delete"){
            cin >> delete_Shape_info;
            if(delete_Shape_info >=0 && shape_Count>delete_Shape_info){
                delete shape[delete_Shape_info]; 
                for(int i= delete_Shape_info; i<shape_Count-1; i++){
                    shape[i]=shape[i+1];
                }
                shape[shape_Count-1] = nullptr;
                shape_Count--;
            }
        } 
    }

    for (int i = 0; i < shape_Count; i++){
        delete shape[i];
    }
    
    return 0;
}