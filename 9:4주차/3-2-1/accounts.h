#ifndef __ACCOUNTS_H__
#define __ACCOUNTS_H__
class Account{
    public:
        void setID(int id);
        void setBalance(int amount);
        bool deposit(int amount);
        bool withdraw(int amount);
        int getID();
        int getBalance();
    
    private:
        int _id;
        int _balance;
};

class AccountManager{
    public:
        bool createAccount();
        bool deposit(int _id, int amount);
        bool withdraw(int _id, int amount);
        bool transfer(int from, int to, int amount);
        void printAccount(int _id);
        int getMaxID();
        
    private:
        Account accounts[10];
        int accountcount=0;
};

#endif

