#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#define f(i,n) for(int i=0;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
#define in(n) scanf("%d",&n)
#define cin(c) scanf(" %c",&c)
#define sin(s) scanf("%s",s)
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
bool search(hasht h,int k,int x){
    f(i,x){
        if(h->a[i]!=NULL && h->a[i]->key==k)return true;
    }
return false;
}
void unionn(int aa[],int b[],int n,int m){
    hasht h=create_table(2*maxx(n,m));
    int x=2*maxx(n,m);
    f(i,n){ 
        int index=aa[i]%x;
        node temp=(node)malloc(sizeof(struct node));

        if(h->a[index]==NULL){temp->key=aa[i];h->a[index]=temp;}
        else if(h->a[index]->key!=aa[i]) {
            while(h->a[index]!=NULL && index<x)index++;
            temp->key=aa[i];
            h->a[index]=temp;
        }
        else aa[i]=0;
    }
    hasht hh=create_table(x);
    f(i,m){
        int index=b[i]%x;
         node temp=(node)malloc(sizeof(struct node));
        if(hh->a[index]==NULL){temp->key=b[i];hh->a[index]=temp;}
        else if(hh->a[index]->key!=b[i]){
            while(hh->a[index]!=NULL)index++;
            temp->key=b[i];
            hh->a[index]=temp;
        }
        else b[i]=0;
    }
    f(i,m){
        if(b[i]!=0)
       { int index=b[i]%x;
         node temp=(node)malloc(sizeof(struct node));
        if(h->a[index]==NULL){temp->key=b[i];h->a[index]=temp;}
        else if(h->a[index]->key!=b[i]){
            int f=0;
            while(h->a[index]!=NULL){index++;}
            if(!search(h,b[i],x))
           { temp->key=b[i];
            h->a[index]=temp;}
            else b[i]=0;
        }
        else b[i]=0;}
    }
    int f1=0,f2=0;
    f(i,n){
        if(aa[i]!=0){f1=1;printf("%d ",aa[i]);}
    }
    f(i,m){
        if(b[i]!=0){f2=1;printf("%d ",b[i]);}
    }
    if(!f1 &&!f2)printf("-1");
    printf("\n");
}

void intersection(int aa[],int b[],int n,int m){
    hasht h=create_table(2*maxx(n,m));
    int x=2*maxx(n,m);
    
    hasht hh=create_table(x);
    f(i,m){
        int index=b[i]%x;
         node temp=(node)malloc(sizeof(struct node));
        if(hh->a[index]==NULL){temp->key=b[i];hh->a[index]=temp;}
        else if(hh->a[index]->key!=b[i]){
            while(hh->a[index]!=NULL)index++;
            temp->key=b[i];
            hh->a[index]=temp;
        }
        else b[i]=0;
    }
    f(i,n){ 
        int index=aa[i]%x;
        node temp=(node)malloc(sizeof(struct node));

        if(h->a[index]==NULL){temp->key=aa[i];h->a[index]=temp;}
        else if(h->a[index]->key!=aa[i]) {
            while(h->a[index]!=NULL && index<x)index++;
            temp->key=aa[i];
            h->a[index]=temp;
        }
        else aa[i]=0;
    }
    f(i,n){
        if(!search(hh,aa[i],x))aa[i]=0;
    }
    
    int f=1;
    f(i,n){
        if(aa[i]!=0){f=0;printf("%d ",aa[i]);}
    }
    if(f)printf("-1");
    printf("\n");


}
void minus(int aa[],int b[],int n,int m){
     hasht h=create_table(2*maxx(n,m));
    int x=2*maxx(n,m);
    
    hasht hh=create_table(x);
     f(i,m){
        int index=b[i]%x;
         node temp=(node)malloc(sizeof(struct node));
        if(hh->a[index]==NULL){temp->key=b[i];hh->a[index]=temp;}
        else if(hh->a[index]->key!=b[i]){
            while(hh->a[index]!=NULL)index++;
            temp->key=b[i];
            hh->a[index]=temp;
        }
        else b[i]=0;
    }
    f(i,n){ 
        int index=aa[i]%x;
        node temp=(node)malloc(sizeof(struct node));

        if(h->a[index]==NULL){temp->key=aa[i];h->a[index]=temp;}
        else if(h->a[index]->key!=aa[i]) {
            while(h->a[index]!=NULL && index<x)index++;
            temp->key=aa[i];
            h->a[index]=temp;
        }
        else aa[i]=0;
    }
    f(i,n){
        if(search(hh,aa[i],x))aa[i]=0;
    }
    
    int f=1;
    f(i,n){
        if(aa[i]!=0){f=0;printf("%d ",aa[i]);}
    }
    if(f)printf("-1");
    printf("\n");
}
int main(){
    int n,m;
    inn(n,m);
    int aa[n],bb[m];
    f(i,n)in(aa[i]);
    f(i,m)in(bb[i]);
    char ch;
    while(ch!='e'){
        int a[n],b[m];
        f(i,n)a[i]=aa[i];
        f(i,m)b[i]=bb[i];
        char x,y;
        cin(ch);
        switch(ch){
            case 'u': cin(x);cin(y);if(x=='A')unionn(a,b,n,m);else unionn(b,a,m,n);break;
            case 'i':cin(x);cin(y); if(x=='A')intersection(a,b,n,m);else intersection(b,a,m,n);break;
            case 's': cin(x);cin(y);if(x=='A')minus(a,b,n,m);else minus(b,a,m,n);break;

               
        }
    }

}