#include "setfunc.h"
#include <iostream>
#include <sstream>

std::set<int> parseSet(const std::string& str) {
    std::set<int> result;
    std::istringstream iss(str.substr(1, str.size() - 2));
    int num;
    while (iss >> num) {
        result.insert(num);
    }
    return result;
}

void printSet(const std::set<int>& set) {
    std::cout << "{ ";
    for (auto it = set.begin(); it != set.end(); ++it) {
        if (it != set.begin()) {
            std::cout << " ";
        }
        std::cout << *it;
    }
    std::cout << " }" << std::endl;
}

std::set<int> getIntersection(const std::set<int>& set0, const std::set<int>& set1) {
    std::set<int> result;
    for (int elem : set0) {
        if (set1.find(elem) != set1.end()) {
            result.insert(elem);
        }
    }
    return result;
}

std::set<int> getUnion(const std::set<int>& set0, const std::set<int>& set1) {
    std::set<int> result = set0;
    result.insert(set1.begin(), set1.end());
    return result;
}

std::set<int> getDifference(const std::set<int>& set0, const std::set<int>& set1) {
    std::set<int> result;
    for (int elem : set0) {
        if (set1.find(elem) == set1.end()) {
            result.insert(elem);
        }
    }
    return result;
}