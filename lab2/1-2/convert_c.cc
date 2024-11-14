#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    int strlength=1000000000;
    char* str;
    str = (char *)malloc(sizeof(char)*strlength);
    
    while(true){
        scanf("%s",str);
        if(strcmp(str,"exit")==0){
            break;
        }
        if(strcmp(str,"Exit")==0){
            break;
        }
        if(strcmp(str,"eXit")==0){
            break;
        }
        if(strcmp(str,"exIt")==0){
            break;
        }
        if(strcmp(str,"exiT")==0){
            break;
        }
        if(strcmp(str,"EXit")==0){
            break;
        }
        if(strcmp(str,"eXIt")==0){
            break;
        }
        if(strcmp(str,"exIT")==0){
            break;
        }
        if(strcmp(str,"ExiT")==0){
            break;
        }
        if(strcmp(str,"eXiT")==0){
            break;
        }
        if(strcmp(str,"ExIt")==0){
            break;
        }
        if(strcmp(str,"EXIt")==0){
            break;
        }
        if(strcmp(str,"EXiT")==0){
            break;
        }
        if(strcmp(str,"ExIT")==0){
            break;
        }
        if(strcmp(str,"eXIT")==0){
            break;
        }
        if(strcmp(str,"EXIT")==0){
            break;
        }
        
        convert_case(str);
        
        if(str[0]=='^'){
            printf("Error: Wrong input!\n");
            break;
        }
        printf("%s\n",str);

    }
    free(str);
    return 0;
}