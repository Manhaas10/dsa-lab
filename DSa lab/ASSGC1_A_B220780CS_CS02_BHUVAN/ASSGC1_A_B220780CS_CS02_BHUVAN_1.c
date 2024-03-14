#include <stdio.h>
#include <string.h>
char stack[1000000];
int top=-1;
int isexp(char ch){
    return ch=='+'||ch=='-'||ch== '*'||ch== '/'||ch=='^'||ch=='%';
}
int check(char s[],int n){
    int f=0;
    for(int i=0;i<n;i++){
        if(s[i]==')'){
            int c=0;
            while(stack[top]!='('){
                if(isexp(stack[top]))c++;
                top--;
            }
            if(stack[top]=='(')top--;
            if(c<1)return 1;
        }
        else stack[++top]=s[i];
    }
    return 0;
}
int main(){
    int n;scanf("%d",&n);
    char s[n];
    scanf("%s",s);
   // int n=strlen(s);
    int c=check(s,n);
    printf("%d\n",c);
}