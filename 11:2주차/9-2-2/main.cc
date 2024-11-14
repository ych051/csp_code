#include "sorted.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(void){
    SortedArray sortarr;
    string cmd,nums;
    int num;
    while (1){
        cin >> cmd;
        if(cmd=="add"){
            cin.ignore();
            getline(cin,nums);
            stringstream num_only(nums);
            while (num_only >> num){
                sortarr.AddNumber(num);
            }
        }
        else if(cmd=="ascend"){
            vector<int> prt = sortarr.GetSortedAscending();
            for(int i=0;i<prt.size();i++){
                cout << prt[i] << ' ';
            }
            cout << endl;
        }
        else if(cmd=="descend"){
            vector<int> prt = sortarr.GetSortedDescending();
            for(int i=0;i<prt.size();i++){
                cout << prt[i] << ' ';
            }
            cout << endl;
        }
        else if(cmd=="max"){
            cout << sortarr.GetMax() << endl;
        }
        else if(cmd=="min"){
            cout << sortarr.GetMin() << endl;
        }
        else if(cmd=="quit"){
            break;
        }
    }
    return 0;
}