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
    int key;
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
node insertsort(node head,int k){
    node temp=malloc(sizeof(struct node));
    temp->key=k;
   temp->next=NULL;
    if(head==NULL || head->key>=k){temp->next=head;head=temp;return head;}
node tep=head;node prev=head;
    while(tep->next && tep->next->key<k){tep=tep->next;}
   // printf("%d ",tep->key);printf("\n");
    temp->next=tep->next;
    tep->next=temp;
    return head;

}
int search2(hasht h,int n,int k){
    int i=k%n;int f=1;
    node temp=h->a[i];
    if(temp==NULL)f=0;int c=1;
    while(temp && temp->key!=k){c++;temp=temp->next;}
    if(f&&temp)return 1;
    else return 0;
}
hasht insert(hasht h,int n,int k){
    int i=k%n;
    if(search2(h,n,k)){iout(-1);return h;}
    node temp=h->a[i];
    h->a[i]=insertsort(temp,k);
    return h;
}
hasht insertq(hasht h,int n,int k){
    int i=k%n;
    //if(search2(h,n,k)){iout(-1);return h;}
    node temp=h->a[i];
    h->a[i]=insertsort(temp,k);
    return h;
}
void search(hasht h,int n,int k){
    int i=k%n;int f=1;
    node temp=h->a[i];
    if(temp==NULL)f=0;int c=1;
    while(temp && temp->key!=k){c++;temp=temp->next;}
    if(f&&temp)printf("%d %d\n",i,c);
    else printf("-1\n");
}

hasht del(hasht h,int n,int k){
    int i=k%n;int f=1;
     node temp=h->a[i];
    if(temp==NULL){printf("-1\n");return h;}
    node prev=temp;int c=1;
    if(temp->key==k && temp->next==NULL){h->a[i]=NULL;printf("%d %d\n",i,c);return h;}
    while(temp && temp->key!=k){c++;prev=temp;temp=temp->next;}
    if(f&&temp){prev->next=temp->next;if(c==1)h->a[i]=temp->next;}
    else {printf("-1\n");return h;}
    printf("%d %d\n",i,c);
    
    return h;
}


void print(hasht h,int i){
    node temp=h->a[i];
    if(temp==NULL){printf("-1\n");return;}
    while(temp){printf("%d ",temp->key);temp=temp->next;}
    printf("\n");
}
int main(){
  int n;
  in(n);
  hasht h=create_table(n);
  char ch;
  while(ch!='e'){
    cin(ch);int k,ok;
    switch(ch){
        case 'i':
         in(k);
         h=insert(h,n,k);
         break;
        case 'p':
         in(k);
         print(h,k);
         break;
        case 's':
         in(k);
         search(h,n,k);
         break;

        case 'd':
         in(k);
         h=del(h,n,k);
         break;
        case 'u':
         inn(k,ok);
         if(!search2(h,n,k)|| search2(h,n,ok) && k!=ok)iout(-1);
         else {h=del(h,n,k);h=insertq(h,n,ok);}
         break;
    }
  }







}

