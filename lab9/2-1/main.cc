#include "setfunc.h"
#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
using namespace std;

int main(void){
    
    string input;
    
    while (1){
        
        getline(cin,input);
        if(input=="0"){
            break;
        }
        size_t first_brace = input.find('{');
        size_t second_brace = input.find('}', first_brace);
        size_t third_brace = input.find('{', second_brace);
        size_t fourth_brace = input.find('}', third_brace);

        string set0_str = input.substr(first_brace, second_brace - first_brace + 1);
        string set1_str = input.substr(third_brace, fourth_brace - third_brace + 1);
        string op = input.substr(second_brace + 1, third_brace - second_brace - 1);
        
        op = op.erase(0, op.find_first_not_of(' '));
        op = op.erase(op.find_last_not_of(' ') + 1);

        set<int> set0 = parseSet(set0_str);
        set<int> set1 = parseSet(set1_str);
        set<int> result;

        if(op == "+"){  //union
            result = getUnion(set0, set1);
        }
        
        else if(op == "*"){ //intersection
            result = getIntersection(set0, set1);
        }
        
        else if(op == "-"){ //difference
            result = getDifference(set0, set1);
        }
        printSet(result);
    }
    return 0;
}