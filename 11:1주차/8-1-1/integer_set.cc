#include "integer_set.h"

void IntegerSet::AddNumber(int num){
    for (size_t i = 0; i < numbers_.size(); ++i) {
        if (numbers_[i] == num) {
            return;
        }
    }
    numbers_.push_back(num);
}

void IntegerSet::DeleteNumber(int num){
    for (auto it = numbers_.begin(); it != numbers_.end(); ++it) {
        if (*it == num) {
            numbers_.erase(it);
            return;
        }
    }
}

int IntegerSet::GetItem(int pos){
    if (pos < 0 || pos >= numbers_.size()) {
        return -1;
    }
    return numbers_[pos];
}

vector<int> IntegerSet::GetAll(){
    return numbers_;
}