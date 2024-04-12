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
void solve(int n,int a[n][n]){
    f(i,n){
        f(j,n){
            if(a[i][j]==-1)a[i][j]=99999;
        }
    }
    f(k,n){
        f(i,n){
            f(j,n){
                
                if(a[i][k]+a[k][j]<a[i][j]){
                   a[i][j]= a[i][k]+a[k][j];
                }
            }
        }
    }
    f(i,n){
        f(j,n){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int n;in(n);
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf(" %d",&a[i][j]);
            //a[i][j]=0;
        }
    }
    solve(n,a);
}