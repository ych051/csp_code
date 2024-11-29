#include "calendar.h"
#include <string>

using namespace std;

int main(){
    MyCalendar mc;
    string cmd,day;

    while (1){
        cin >> cmd;
        if(cmd=="quit") break;

        else if(cmd=="set"){
            cin >> mc;
            cout << mc;
        }

        else if(cmd=="next"){
            cin >> day;
            if(day=="day"){
                if(!mc.NextDay()) cout << "Invalid date" << '\n';
            }
            else {
                if(!mc.NextDay(stoi(day))) cout << "Invalid date" << '\n';
            }
            cout << mc;
        }
    }
    return 0;
}