#include <iostream>
#include <string>
#include <cstring>
using namespace std;
void convert_case(char* a) {
    int n=0;
    while (a[n]!='\0'){
        if(a[n]>='A'&&a[n]<='Z'){
            a[n]+=32;
        }
        else if(a[n]>='a'&&a[n]<='z'){
            a[n]-=32;
        }
        else{
            a[0]='^';
        }
        n++;
    }
    
}
int main(void) {
    string str;
    while(true){
        cin>>str;
        if(str=="exit"){
            break;
        }
        if(str=="Exit"){
            break;
        }
        if(str=="eXit"){
            break;
        }
        if(str=="exIt"){
            break;
        }
        if(str=="exiT"){
            break;
        }
        if(str=="EXit"){
            break;
        }
        if(str=="eXIt"){
            break;
        }
        if(str=="exIT"){
            break;
        }
        if(str=="ExiT"){
            break;
        }
        if(str=="eXiT"){
            break;
        }
        if(str=="ExIt"){
            break;
        }
        if(str=="EXIt"){
            break;
        }
        if(str=="EXiT"){
            break;
        }
        if(str=="ExIT"){
            break;
        }
        if(str=="eXIT"){
            break;
        }
        if(str=="EXIT"){
            break;
        }
        int len=str.length()+1;
        char test[len];
        strcpy(test, str.c_str());
        convert_case(test);
        
        if(test[0]=='^'){
            cout<<"Error: Wrong input!\n";
            break;
        }
        cout<<test<<endl;

    }
    return 0;
}