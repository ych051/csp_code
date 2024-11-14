#include "message.h"
#include <iostream>

using namespace std;

int main(void){
    MessageBook mb;
    string command, message_string;
    int phone_number;
    while (1){
        cin >> command;
        if (command == "add"){
            cin >> phone_number;
            cin.ignore();
            getline(cin,message_string);
            mb.AddMessage(phone_number, message_string);
        }
        else if (command == "delete"){
            cin >> phone_number;
            mb.DeleteMessage(phone_number);
        }
        else if (command == "print"){
            cin >> phone_number;
            cout << mb.GetMessage(phone_number) << endl;
        }
        else if (command == "list"){
            vector<int> numbers = mb.GetNumbers();
            for (int number : numbers) {
                cout << number << ": " << mb.GetMessage(number) << endl;
            }
        }
        else if (command == "quit"){
            break;
        }
    }
    return 0;
}