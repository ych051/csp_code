#include "sorted.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void SortedArray::AddNumber(int num){
    numbers_.push_back(num);
}

std::vector<int> SortedArray::GetSortedAscending(){
    sort(numbers_.begin(),numbers_.end());
    return numbers_;
}

std::vector<int> SortedArray::GetSortedDescending(){
    sort(numbers_.rbegin(),numbers_.rend());
    return numbers_;
}

int SortedArray::GetMax(){
    vector<int>::iterator max;
    max = max_element(numbers_.begin(),numbers_.end());
    return *max;
}

int SortedArray::GetMin(){
    vector<int>::iterator min;
    min = min_element(numbers_.begin(),numbers_.end());
    return *min;
}