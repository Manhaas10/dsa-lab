
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define f(i,n) for(int i=0;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
#define in(n) scanf("%d",&n)
#define cin(c) scanf("%c",&c)
#define sin(s) scanf("%s",s)
#define inn(n,k) scanf("%d %d",&n,&k)
#define iout(n) printf("%d\n",n)
#define sout(s) printf("%s\n",s)
#define cout(c) printf("%c\n",c)
#define ll long long

int main(){
    int n,k;
    inn(n,k);
    int a[n];
    f(i,n)in(a[i]);
    int b[100000]={0};int c=0;
    int x[100000];
    f(i,k){
        b[a[i]]++;
        if(b[a[i]]==1)c++;
    }
    int kk=0;
    //iout(c);
    x[kk++]=c;
    int j=k,i=1;
    while(i<n && j<n){
        b[a[i-1]]--;
        if(b[a[i-1]]<1)c--;
        b[a[j]]++;
        if(b[a[j]]==1)c++;
        x[kk++]=c;
        i++;j++;
    }
    f(i,kk)printf("%d ",x[i]);


}