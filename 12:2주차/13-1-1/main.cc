#include "integer_set.h"

int main(void){

    IntegerSet intSet;
    string command;

    while (1) {

        cin >> command;

        if (command == "add") {
            int num;
            cin >> num;
            intSet.AddNumber(num);
            vector<int> allNumbers = intSet.GetAll();
            for (size_t i = 0; i < allNumbers.size(); i++) {
                cout << allNumbers[i] << " ";
            }
            cout << endl;
        }
        
        else if (command == "del") {
            int num;
            cin >> num;
            intSet.DeleteNumber(num);
            vector<int> allNumbers = intSet.GetAll();
            for (size_t i = 0; i < allNumbers.size(); i++) {
                cout << allNumbers[i] << " ";
            }
            cout << endl;
        }
        
        else if (command == "get") {
            int pos;
            cin >> pos;
            cout << intSet.GetItem(pos) << endl;
        }
        
        else if (command == "quit") {
            break;
        }
    }
    return 0;
}