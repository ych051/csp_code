#include "reply_admin.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main(void){
    ReplyAdmin admin;
    string input;
    int* indices = new int(NUM_OF_CHAT);
    while(1){
        getline(cin,input);
        if(input=="#quit"){
            break;
        }
        else if(input.substr(0,7)=="#remove"){
            string input_behind=input.substr(8);
            int count = 0;
            if (input_behind.find(",") != string::npos) {
                stringstream ss(input_behind);
                string indexStr;
                while (getline(ss, indexStr, ',')) {
                    indices[count++] = stoi(indexStr);
                }
                if(admin.removeChat(indices, count)){
                    admin.printChats();
                }
                else{
                    cout << "Error!" << endl;
                }
            }
            else if (input_behind.find('-') != string::npos) {
                stringstream ss(input_behind);
                int start, end;
                string indexStr;
                while (getline(ss, indexStr, '-')) {
                    indices[count++] = stoi(indexStr);
                }
                start=indices[0];
                end=indices[1];
                cout << start << endl;
                cout << end << endl;
                if(admin.removeChat(start, end)){
                    admin.printChats();
                }
                else{
                    cout << "Error!" << endl;
                }
            }
            else {
                int index = stoi(input_behind);
                if(admin.removeChat(index)){
                    admin.printChats();
                }
                else{
                    cout << "Error!" << endl;
                }
            }
        }
        
        else{
            if(admin.addChat(input)==false){
                break;
            }
            else{
                admin.printChats();
            }
        }
        
    }
    
    delete[] indices;
    return 0;
}