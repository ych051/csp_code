#include <iostream>
#include "accounts.h"
using namespace std;

int main(void){
    AccountManager accountmanager;
    char command;
    int id, from, to, amount;

    while (1){
        cout << "Job?" << endl;
        cin >> command;

        if(command=='N'){
            if(accountmanager.createAccount()){
                cout << "Success!" << endl;
                accountmanager.printAccount(accountmanager.getMaxID());
            }
            else{
                cout << "Failure!" << endl;
            }
        }
        else if(command=='D'){
            cin >> id >> amount;
            if(accountmanager.deposit(id, amount)){
                cout << "Success!" << endl;
                accountmanager.printAccount(id);
            }
            else{
                cout << "Failure!" << endl;
            }
        }
        else if(command=='W'){
            cin >> id >> amount;
            if(accountmanager.withdraw(id, amount)){
                cout << "Success!" << endl;
                accountmanager.printAccount(id);
            }
            else{
                cout << "Failure!" << endl;
                accountmanager.printAccount(id);
            }
        }
        else if(command=='T'){

            cin >> from >> to >> amount;

            
            if(accountmanager.transfer(from, to, amount)){
                cout << "Success!" << endl;
                if (from>to){
                    accountmanager.printAccount(to);
                    accountmanager.printAccount(from);
                }
                else {
                    accountmanager.printAccount(from);
                    accountmanager.printAccount(to);
                }
            }
            else{
                cout << "Failure!" << endl;
                bool a = accountmanager.deposit(from,0);
                bool b = accountmanager.deposit(to,0);
                if( a && b){
                    if (from>to){
                        accountmanager.printAccount(to);
                        accountmanager.printAccount(from);
                    }
                    else {
                        accountmanager.printAccount(from);
                        accountmanager.printAccount(to);
                    }
                }
                
            }
        }
        if(command=='Q'){
            break;
        }
    }

    return 0;
}