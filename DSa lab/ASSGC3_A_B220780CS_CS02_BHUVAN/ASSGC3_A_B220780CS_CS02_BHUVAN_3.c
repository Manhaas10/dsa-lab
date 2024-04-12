
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
struct graph{
    int vertices;
    int **a;
    int *visted;
    int *stack;
    int top;
};
typedef struct graph* graph;
void intialize(graph g){
     for(int i=0;i<g->vertices;i++){
        g->visted[i]=0;g->stack[i]=0;
        for(int j=0;j<g->vertices;j++){
            g->a[i][j]=0;

        }
        g->top=-1;
        //printf("\n");
    }
}
graph cg(int n){
    graph g=malloc(sizeof(struct graph));
    g->vertices=n;//n++;
    g->a=(int**)malloc(n*sizeof(int*));
    
    for(int i=0;i<n;i++){
        g->a[i]=(int*)malloc(n*sizeof(int));
    }
    g->visted=(int*)malloc(n*sizeof(int));
    g->stack=(int*)malloc(n*sizeof(int));
    g->top=-1;
   // g->visted=0;
   intialize(g);
    return g;
}

void print(graph g){
    //int f=1;
    f(i,g->top+1){
        printf("%d ",g->stack[i]);//
        //f=0;
    }
   // if(f)iout(-1);
   printf("\n");
}

void printpath(graph g,int curr,int dest,int* f){
    g->visted[curr]=1;
    g->stack[++g->top]=curr;
   //f=1;
    if(curr==dest){
        //g->stack[++g->top]=curr;
        *f=1;
        print(g);
    }
    else {
        f(i,g->vertices){
            if(g->a[curr][i] && !g->visted[i]){
                printpath(g,i,dest,f);
            }
        }
    }
   g->visted[curr]=0;
    g->top--;
   
   //if(g->top==-1){f=0;return;}
}

void addedge(graph g,int x,int y){
    g->a[x][y]=1;
    g->a[y][x]=1;
}
int isn(char ch){
    return ch>='0'&& ch<='9';
}
int iscycleut(int v,graph g,int p){
   // if(!g->visted[v])
    //{
        g->visted[v]=1;
        //g->stack[v]=1;
        for(int i=0;i<g->vertices;i++){
            if(g->a[v][i])
           { 
            if(!g->visted[i])
            {
                if(iscycleut(i,g,v) ){
               //printf("%dx",i);
              return 1;
            }
            }
            else if(i!=p){return 1;}}
        }

   // }
    //g->stack[v]=0;
    return 0;
}

int iscycle(graph g){
    f(i,g->vertices){
        if(!g->visted[i]){
            if(iscycleut(i,g,-1)){
                return 1;
            }
        }
    }
    return 0;
}

int tree(graph g){
    if(iscycle(g))return -1;
    //if(isco(g))return -1;
      int edges = 0;
    for (int i = 0; i < g->vertices; i++) {
        for (int j = i + 1; j < g->vertices; j++) {
            if (g->a[i][j]) {
                edges++;
            }
        }
    }
    return (edges == g->vertices - 1)?1:-1;
 
}

int main(){
     int n;
    scanf(" %d",&n);
    graph g=cg(n);
    //intialize(g);
    while(n--){
        char s[1000];
        scanf(" %[^\n]",s);
        int x=s[0]-'0';
        int j=1;
        if(isn(s[j])){
            x=x*10+s[j]-'0';j++;
        }
 
        for(int i=j+1;i<strlen(s);i++){
        if(isn(s[i])){
            int num=0;
            while(isn(s[i])){
                num=num*10+s[i]-'0';i++;
                }
            int y=num;
            addedge(g,x,y);}
            
        }

    }

    char ch;//iout(tree(g));
    while(ch!='x'){
        scanf(" %c",&ch);int a,b;
        switch(ch){
            case 'a':
            inn(a,b); f(i,g->vertices)g->visted[i]=0;
            
            int f=0;
            printpath(g,a,b,&f);
            if(!f)iout(-1);
            
           
            break;
            case 't':
            f(i,g->vertices)g->visted[i]=0;
            iout(tree(g)); 
            break;

        }
    }

}
