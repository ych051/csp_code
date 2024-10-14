#include <iostream>
#include <cmath>
using namespace std;

typedef struct{
    int xpos;
    int ypos;
}Point;

void getShortest(const Point* points, int n, Point* minP){
    //초기값 설정
    double min_distance = sqrt(pow(points[0].xpos - points[1].xpos, 2) + pow(points[0].ypos - points[1].ypos, 2));
    double distance;
    minP->xpos=0;
    minP->ypos=1;

    for(int i =0;i<n;i++){
        for(int j=i+1;j<n;j++){
            distance = sqrt(pow(points[i].xpos - points[j].xpos, 2) + pow(points[i].ypos - points[j].ypos, 2));
            if (distance < min_distance){
                min_distance = distance;
                minP->xpos=i;
                minP->ypos=j;
                    
            }
        }
    }

}


void getLongest(const Point* points, int n, Point* maxP){
    //초기값 설정
    double max_distance = sqrt(pow(points[0].xpos - points[1].xpos, 2) + pow(points[0].ypos - points[1].ypos, 2));
    double distance;
    maxP->xpos=0;
    maxP->ypos=1;

    for(int i =0;i<n;i++){
        for(int j=i+1;j<n;j++){
            distance = sqrt(pow(points[i].xpos - points[j].xpos, 2) + pow(points[i].ypos - points[j].ypos, 2));
            if (distance > max_distance){
                max_distance = distance;
                maxP->xpos=i;
                maxP->ypos=j;
                    
            }
        }
    }
}

int main(void){
    int n;
    int count=0;

    cin >> n;

    Point* arr = new Point[n];
    while (n>count){
        cin >> arr[count].xpos >> arr[count].ypos;
        count++;
    }
    Point minP;
    Point maxP;
    getShortest(arr,n,&minP);
    getLongest(arr,n,&maxP);

    cout << "longest: ("<< arr[maxP.xpos].xpos <<","<< arr[maxP.xpos].ypos <<") ("<< arr[maxP.ypos].xpos <<","<< arr[maxP.ypos].ypos <<")"<<endl;
    cout << "shortest: ("<< arr[minP.xpos].xpos <<","<< arr[minP.xpos].ypos <<") ("<< arr[minP.ypos].xpos <<","<< arr[minP.ypos].ypos <<")"<<endl;
    
    delete[] arr;
    return 0;
}