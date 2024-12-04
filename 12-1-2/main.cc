#include <iostream>

using namespace std;

class A {
    public:
        A(int n) {
            if(n<=0)throw "caught in the main";
            cout << "ID=" << n << ": constructed\n";
            n_ID = n;
            data = new int[n];

        } 
        ~A() {
            delete[] data;
            cout << "ID=" << n_ID << ": destroyed\n";
        } 
    private:
        int* data = NULL;
        int n_ID;
};

int main(){
    try{
        A a(3);
        A b(2);
        {
            A c(1);
            A d(0);
            A e(-1);
        }
    }
    catch (const char* m) {
        cout << m << '\n';
    }
    return 0;
}