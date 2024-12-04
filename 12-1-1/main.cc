#include "my_container.h"
#include <string>

using namespace std;

int main(){
    
    int n;
    cin >> n;
    MyContainer<int> int_mc(n);
    cin >> int_mc;
    cout << int_mc;
    cout << '\n';

    cin >> n;
    MyContainer<double> double_mc(n);
    cin >> double_mc;
    cout << double_mc;
    cout << '\n';

    cin >> n;  
    MyContainer<string> str_mc(n);
    cin >> str_mc;
    cout << str_mc;
    cout << '\n';

    return 0;
}