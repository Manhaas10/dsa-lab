
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
int isn(char ch){
    return ch>='0'&& ch<='9';
}
int minkey(int set[],int key[],int n){
    int min=INT_MAX,pos;
    for(int i=0;i<n;i++){
        if(!set[i] && key[i]<=min){
            min=key[i];pos=i;
        }
    }
    return pos;
}

void solve(int n,int a[n][n],int strt){
    int ans[n];
    int reach[n];
    f(i,n){
        ans[i]=INT_MAX;
        reach[i]=0;
    }
    ans[strt]=0;
    f(i,n-1){
        int u=minkey(reach,ans,n);
        reach[u]=1;
        f(j,n){
            if(!reach[j] && a[u][j] && ans[u]!=INT_MAX && ans[u]+a[u][j]<ans[j])ans[j]=ans[u]+a[u][j];
        }
    }
    f(i,n)printf("%d ",ans[i]);


}
int main(){

  

    int n;in(n);
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=0;
        }
    }
    int ii=0;
    while(ii<n){
         char s[1000];
        scanf(" %[^\n]",s);
        int x=s[0]-'0';
        int j=1;
        if(isn(s[j])){
            x=x*10+s[j]-'0';j++;
        }
        //iout(1);
         for(int i=j+1;i<strlen(s);i++){
        if(isn(s[i])){
            int num=0;
            while(isn(s[i])){
                num=num*10+s[i]-'0';i++;
                }
            int y=num;
             a[x-1][y-1]=1;
             a[y-1][x-1]=1;
            
            }
            
        }
          ii++;
    }
    ii=0;
    while(ii<n){
          char s[1000];
        scanf(" %[^\n]",s);
        int x=s[0]-'0';
        int j=1;
        if(isn(s[j])){
            x=x*10+s[j]-'0';j++;
        }
        int b[n];int z=0;
         for(int i=j+1;i<strlen(s);i++){
        if(isn(s[i])){
            int num=0;
            while(isn(s[i])){
                num=num*10+s[i]-'0';i++;
                }
            int y=num;
            b[z++]=y;
            }  
        }
        int zz=0;z=0;
        for(int jj=0;jj<n;jj++){
            if(a[x-1][jj]){
                a[x-1][jj]=b[z];
                a[jj][x-1]=b[z++];
            }
        }
          ii++;
    }
    int k;
    in(k);
    solve(n,a,k-1);printf("\n");


}