#include <iostream>
#include <string>
#include <vector>
#include "my_vector.h"

using namespace std;

int main(){
    MyVector a,b;
    string cmd;
    int n,length;

    char op, a_char;
    string b_char;
    int b_int=0;

    while (1){
        
        cin >> cmd;

        if(cmd=="new"){
            cin >> length;
            a= MyVector(length);
            b= MyVector(length);
            cout << "enter a" << '\n';
            cin >> a;
            cout << "enter b" << '\n';
            cin >> b;
        }

        else if(cmd=="quit") break;

        else{
            a_char=cmd[0];
            cin >> op >> b_char;
            if(b_char[0]>='0' && b_char[0]<='9') {
                b_int=stoi(b_char);
                if(op=='+') cout << a+b_int << '\n';
                else if(op=='-') cout << a-b_int << '\n';
            }
            else{
                if(op=='+') cout << a+b << '\n';
                else if(op=='-') cout << a-b << '\n';
            }
        }  
    }
    return 0;
}