
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
void makeset(int p[],int r[],int n){
    f(i,n){
        p[i]=i;
        r[i]=1;
    }
}
int compare(const void* a,const void* b){
    const int(*x)[3]=a;
    const int(*y)[3]=b;
    return (*x)[2]-(*y)[2];
}
int findp(int p[],int v){
    if(v==p[v])return v;
    else return p[v]=findp(p,p[v]);
}
void unionsets(int u,int v,int p[],int size[],int n){
   int up= findp(p,u);
    int vp= findp(p,v);
    if(size[up]<size[vp]){
        p[up]=vp;size[vp]+=size[up];
    }
    else {
        p[vp]=up;
        size[up]+=size[vp];
    }
}
void mst(int n,int edges[n][3]){
    qsort(edges,n,sizeof(edges[0]),compare);
    
    int p[n];
    int size[n];
    makeset(p,size,n);
    int minw=0;
    for(int i=0;i<n;i++){
        
        int up=findp(p,edges[i][0]);
        int vp=findp(p,edges[i][1]);
        
        if(up>vp){
            unionsets(up,vp,p,size,n);
            minw+=edges[i][2];
            //iout(minw);
        }
        else if(vp>up){
            unionsets(vp,up,p,size,n);
            minw+=edges[i][2];
                    }
    }
    iout(minw);
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
             a[x][y]=1;
             a[y][x]=1;
            
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
            if(a[x][jj]){
                a[x][jj]=b[z];
                a[jj][x]=b[z++];
            }
        }
          ii++;
    }

    int edges[100][3];int i=0;
    for(int x=0;x<n;x++){
       
        for(int y=0;y<n;y++){
            if(a[x][y]){
                 edges[i][0]=x;
                edges[i][1]=y;
                edges[i][2]=a[x][y];
                i++;
            }
            
        }
    }
    mst(i,edges);




}