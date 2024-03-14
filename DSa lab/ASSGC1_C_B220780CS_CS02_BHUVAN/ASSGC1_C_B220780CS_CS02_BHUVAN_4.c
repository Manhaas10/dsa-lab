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

void insertl(int aaa[],int n,int k){
    hasht h= create_table(k);
   // int bash[k];int j=0;
   int aa[n];
   f(i,n)aa[i]=aaa[i];
   int c=0;
    f(i,n){
         int index=aa[i]%k;
        node temp=(node)malloc(sizeof(struct node));

            while(h->a[index]!=NULL){c++;index++;index=index%k;}
            temp->key=aa[i];aa[i]=index;
            h->a[index]=temp;
        
    }
    f(i,n)printf("%d ",aa[i]);
    printf("\n%d\n",c);

}
void insertq(int aaa[],int n,int k){
    hasht h= create_table(k);
   // int bash[k];int j=0;
   int aa[n];
   f(i,n)aa[i]=aaa[i];
   int c=0;
    f(i,n){
         int index=aa[i]%k;
         int j=1;
        node temp=(node)malloc(sizeof(struct node));
         while(h->a[index]!=NULL && j<n){c++;index=((aa[i]%k)+j*j)%k;j++;}
          temp->key=aa[i];aa[i]=index;
          //iout(index);
           h->a[index]=temp;
        
    }
    f(i,n)printf("%d ",aa[i]);
    printf("\n%d\n",c);

}

bool isprime(int n){
    if (n <= 1) return false;
    if (n <= 3)return true;
    if (n % 2 == 0 || n % 3 == 0)return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
int prime(int n){
    //if(isprime(n))return n;
    int s=n-1;
    while(1){
        if(isprime(s))return s;s--;
    }
    
}
int h1(int key, int size) {
    return key % size;
}
int h2(int key, int R) {
    return R-(key % R);
}
void insertdh(int aaa[],int n,int k){
    hasht h= create_table(k);
   // int bash[k];int j=0;
   int aa[n];
   f(i,n)aa[i]=aaa[i];
   int c=0;
    f(i,n){
         int index=aa[i]%k;
         int j=1;int r=prime(k);
        node temp=(node)malloc(sizeof(struct node));
         while(h->a[index]!=NULL){
            c++;
            index=(h1(aa[i],k)+j*h2(aa[i],r))%k;
            //printf("%d %d\n",aa[i],h2(aa[i],r));
            j++;
            }
          temp->key=aa[i];aa[i]=index;
           h->a[index]=temp;
        
    }
    f(i,n)printf("%d ",aa[i]);
    printf("\n%d\n",c);

}
int isn(char ch){
    return (ch>='0' && ch<='9');
}
int main(){
    int k;
    in(k);
    char s[k];
    scanf(" %[^\n]",s);
    int nn=strlen(s);
    int a[k];int n=0;
    f(i,nn){
    if(isn(s[i])){
        int num=0;
     while(isn(s[i])){
        num=num*10+s[i]-'0';
       i++;
    }
    a[n++]=num;
    }
    }
    //f(i,n)printf("%d ",a[i]);
    insertl(a,n,k);
    insertq(a,n,k);
    insertdh(a,n,k);

}