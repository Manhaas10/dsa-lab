
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
int minn(int a,int b){
    return (a>b)?b:a;
}
struct kth{
    int e1;
    int e2;
    int w;
};
typedef struct kth* kth;

kth create(int ee1,int ee2,int ww){
     kth hi = malloc(sizeof(struct kth));
     hi->e1=ee1;
     hi->e2=ee2;
     hi->w=ww;
     return hi;
}
int minkey(int set[],int key[],int n){
    int min=INT_MAX,pos;
    for(int i=0;i<n;i++){
        if(!set[i] && key[i]<min){
            min=key[i];pos=i;
        }
    }
    return pos;
}
int compare(const void* a,const void* b){
    kth k1=*(kth*)a;
    kth k2=*(kth*)b;
    return k1->w-k2->w;
}
// int printw(int parent[],int n,int aa[n][n]){
//     int w=0;
//     f(i,n){
//         if(parent[i]!=-1){
//             w+=aa[i][parent[i]];
//         }
//     }
//     return w;
// }
// int print(int parent[],int n, int v,int aa[n][n])
// {
//     int c=0,k=0;
//     int w=printw(parent,n,aa);
//     kth a[n];int x=0;int i=0;
//     while(k<w){

//         if(c<=1 && i<n && parent[i]==v){
//             a[x++]=create(parent[i],i,aa[i][parent[i]]);
//             c++;
//             k+=aa[i][parent[i]];
//             if(c>=2){
                
//                 qsort(a,x,sizeof(kth),compare);
//                 f(j,x){
//                     printf("%d %d ",a[j]->e1,a[j]->e2);
//                 }
//                 v=a[x-1]->e2;
//                 x=0;
//                 i=0;c=0;}
//         }
//         else if(i>=n)i=0;
//         i++;
        


//     }

//0}


int mst(int n,int a[n][n],int v,int f){
   int w=0;int x,y,ii=0;
   int set[n];int min=INT_MAX;
   f(i,n)set[i]=0;
   set[v]=1;
   while(ii<n-1){
    int x=0,y=0;min=INT_MAX;
    f(i,n){
        if(set[i]){
            f(j,n){
                if(!set[j] && a[i][j]){
                    if(min>a[i][j]){
                        min=a[i][j];
                        x=i;
                        y=j;
                    }
                }

            }
        }
    }
    if(!f)
    printf("%d %d ",x,y);
    ii++;
    set[y]=1;
    w+=a[x][y];
   }
   if(!f)printf("\n");
   return w;
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

    char ch,ch1,ch2;
    while(ch!='x'){
        cin(ch);int k=INT_MAX,w;
        switch(ch){
            case 't':
             f(i,n){
                w=mst(n,a,i,1);
                k=minn(k,w);
             //   iout(k);
             }
             iout(k);
             break;
             case 's':
              cin(ch1);
              in(w);
              cin(ch2);
              mst(n,a,w,0);
              break;



        }
    }


    




}