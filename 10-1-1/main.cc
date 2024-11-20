#include <iostream>
#include <string>
#include "my_string.h"

using namespace std;

int main(){
    MyString a,b;
    string cmd;
    int n;
    char op;

    while (1){
        cin >> cmd;
        if(cmd=="new"){
            cout << "enter a" << '\n';
            cin >> a;
            cout << "enter b" << '\n';
            cin >> b;
        }
        else if(cmd=="quit"){
            break;
        }
        else{
            string a_char=cmd;
            cin >> op;
            if(op=='*'){
                cin >> n;
                if(a_char=="a"){
                    MyString result =a*n;
                    cout << result << '\n';
                }
                else if(a_char=="b"){
                    MyString result =b*n;
                    cout << result << '\n';
                }
            }
            else if(op=='+'){
                string b_str;
                cin >> b_str;
                if(a_char=="a"){
                    if(b_str=="a"){
                        MyString result =a+a;
                        cout << result << '\n';
                    }
                    else if(b_str=="b"){
                        MyString result =a+b;
                        cout << result << '\n';
                    }
                }
                else if(a_char=="b"){
                    if(b_str=="a"){
                        MyString result =b+a;
                        cout << result << '\n';
                    }
                    else if(b_str=="b"){
                        MyString result =b+b;
                        cout << result << '\n';
                    }
                }
            }
        }  
    }
    
    return 0;
}