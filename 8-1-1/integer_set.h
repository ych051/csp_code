#ifndef __INTEGERSET_H__
#define __INTEGERSET_H__

#include <iostream>
#include <vector>
using namespace std;

class IntegerSet{
    public:
        void AddNumber(int num);
        void DeleteNumber(int num);
        int GetItem(int pos);
        vector<int> GetAll();
    private:
        vector<int> numbers_;
};

#endif