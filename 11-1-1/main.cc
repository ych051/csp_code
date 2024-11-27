#include <iostream>
#include <string>
#include <vector>
#include "my_clock.h"

using namespace std;

int main(){
    MyClock mc;
    string cmd,time;
    vector<int> time_set;
    int time_change,v;
    while (1){
        cin >> cmd;
        if(cmd=="quit") break;
        else if(cmd=="set"){
            cin >> mc;
            cout << mc;
        }
        else if(cmd=="tick"){
            cin >> time_change;
            mc.Tick(time_change);
            cout << mc;
        }
    }
    return 0;
}