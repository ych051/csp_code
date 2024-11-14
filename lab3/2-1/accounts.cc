#include <iostream>
#include "accounts.h"
using namespace std;

void Account::setID(int id){
    _id=id;
}

void Account::setBalance(int amount){
    _balance=amount;
}

bool Account::deposit(int amount){
    if(_balance+amount>1000000){
        return false;
    }
    _balance+=amount;
    return true;
}

bool Account::withdraw(int amount){
    if(_balance-amount<0){
        return false;
    }
    _balance-=amount;
    return true;

}

int Account::getID(){
    return _id;
}

int Account::getBalance(){
    return _balance;
}


bool AccountManager::createAccount(){
    if(accountcount>=10){
        return false;
    }
    accounts[accountcount].setID(accountcount);
    accounts[accountcount].setBalance(0);
    accountcount++;
    return true;
}

bool AccountManager::deposit(int _id, int amount){
    if (_id>=accountcount || _id<0){
        return false;
    }
    return accounts[_id].deposit(amount);
}

bool AccountManager::withdraw(int _id, int amount){
    if (_id >= accountcount || _id < 0) {
        return false;
    }
    return accounts[_id].withdraw(amount);
}

bool AccountManager::transfer(int from, int to, int amount){
    if (from >= accountcount || to >= accountcount || from < 0 || to < 0) {
        return false;
    }
    if (!accounts[from].withdraw(amount)) {
        return false;
    }
    if(!accounts[to].deposit(amount)){
        accounts[from].deposit(amount);
        return false;
    }
    else{
        return true;
    }
}

void AccountManager::printAccount(int _id){
    if(_id<accountcount && _id>=0) {
        cout << "Balance of user " << _id << ": " << accounts[_id].getBalance() << endl;
    }
}

int AccountManager::getMaxID(){
    return accountcount - 1;
}