#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#define f(i,n) for(int i=0;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
#define in(n) scanf("%d",&n)
#define cin(c) scanf(" %c",&c)
#define sin(s) scanf(" %s",s)
#define inn(n,k) scanf("%d %d",&n,&k)
#define iout(n) printf("%d\n",n)
#define sout(s) printf("%s\n",s)
#define cout(c) printf("%c\n",c)
#define ll long long
int maxx(int a,int b){
    if(a>b)return a;
    else return b;
}
int minn(int a,int b){
    if(a<b)return a;
    else return b;
}

struct node{
    int age;
    char s1[1000]; 
    char s2[1000]; 
    struct node* next;
};
typedef struct node* node;
struct hasht{
    node* a;
};
typedef struct hasht* hasht;
hasht create_table(int n){
    hasht h=malloc(sizeof(struct hasht));
   h->a=malloc(n*sizeof(node));
    f(i,n)
        h->a[i]=NULL;
        return h;
}
int capl(char ch){
    return (ch>='A' &&ch<='Z');
}
int sml(char ch){
    return (ch>='a' && ch<='z');
}
int hash(char s[],int age){
    int sum=0;
    for(int i=0;s[i]!='\0';i++){
        sum+=s[i];
    }sum+=age;
    return sum%4;
}
hasht insert(hasht h,char ss1[],char ss2[],int ag){
    int i=hash(ss1,ag);
    node tep=malloc(sizeof(struct node));
    strcpy(tep->s1,ss1);
    strcpy(tep->s2,ss2);
    tep->age=ag;
    tep->next=NULL;
    node temp=h->a[i];
    if(temp==NULL){h->a[i]=tep; return h;}

    //node prev=temp;
    while(temp->next){temp=temp->next;}
    temp->next=tep;
 
   

    return h;
}
void printc(hasht h,int i){
    node temp=h->a[i];
    if(temp==NULL){iout(0);return;}
    int c=1;
    while(temp->next){c++;temp=temp->next;}
    printf("%d ",c);
    temp=h->a[i];
    while(temp){printf("%s ",temp->s1);temp=temp->next;}
    printf("\n");
}

void printn(hasht h,int i,char s[]){
    node temp=h->a[i];
    if(sml(s[0])){s[0]+='A'-'a';}
    if(sml(s[1])){s[1]+='A'-'a';}
    if(!temp){iout(-1);return;}int f=0;
    while(temp){
        int n=strlen(temp->s2);
        if(temp->s2[n-1]==s[1] && temp->s2[n-2]==s[0]){f=1;printf("%s ",temp->s1);}
        temp=temp->next;
    }
    if(f)
    printf("\n");
    else iout(-1);
}
int main(){
    int n;
    in(n);
    hasht h=create_table(4);
    f(i,n){
        char ss1[100];
        char ss2[100];
        int age;
        scanf(" %s %s %d",ss1,ss2,&age);
        h=insert(h,ss1,ss2,age);
    }
    char ch;
    while(ch!='e'){
        cin(ch);int k;char s[100];
        switch(ch){
            case 'c': in(k);printc(h,k);break;
            case '1': sin(s);printn(h,1,s);break;
            case '2': sin(s);printn(h,2,s);break;
            case '3': sin(s);printn(h,3,s);break;
            case '0': sin(s);printn(h,0,s);break;
        }
    }


}

