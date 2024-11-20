#include "my_string.h"

//std::string str;

MyString MyString::operator+(const MyString& b){
    MyString result;
    result.str = this->str + b.str;
    return result;
}
MyString MyString::operator*(const int b){
    MyString result;
    for (int i = 0; i < b; ++i) {
        result.str += this->str;
    }
    return result;
}

std::ostream& operator<<(std::ostream& out, MyString& my_string){
    out << my_string.str;
    return out;
}
std::istream& operator>>(std::istream& in, MyString& my_string){
    in >> my_string.str;
    return in;
}