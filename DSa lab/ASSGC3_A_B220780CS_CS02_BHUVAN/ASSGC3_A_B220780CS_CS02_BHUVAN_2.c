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

void addedge(graph g,int x,int y){
    g->a[x-1][y-1]=1;
   // g->a[y-1][x-1]=1;
}

int iscycle(int v,graph g){
 int count[g->vertices];
    f(i,g->vertices)count[i]=0;
    f(i,g->vertices){
        f(j,g->vertices){
            if(g->a[i][j])
            count[j]++;
        }
    }
    int front=0,rear=0;int queue[g->vertices];
    f(i,g->vertices){
        if(count[i]==0){
            queue[rear++]=i;
        }
        
    }
    int c=1;c--;
    while(front<rear){
        int u=queue[front++];c++;
        f(i,g->vertices){
            if(g->a[u][i]){
                if(--count[i]==0){
                    queue[rear++]=i;
                   
                }
            }
        }




    }
     return c!=g->vertices;
}

int checkdirectg(graph g){
    f(i,g->vertices){
        f(j,g->vertices){
            if(g->a[i][j] && g->a[j][i]){
                return 0;
            }
        }
    }
    return 1;
}
int troposort(graph g){
    if(!checkdirectg(g))return -1;
    f(i,g->vertices){
        if(!g->visted[i] && iscycle(i,g)){
            return -1;
        }
    }
    return 1;

}

void dfs(graph g,int v){
    g->visted[v]=1;
    f(i,g->vertices){
        if(g->a[v][i]&& !g->visted[i]){
            dfs(g,i);
        }
    }
    g->stack[++g->top]=v;
}
void dfs2(graph g,int v){
    g->visted[v]=1;
    f(i,g->vertices){
        if(g->a[v][i]&& !g->visted[i]){
            dfs2(g,i);
        }
    }
   // g->stack[++g->top]=v;
}
int scc(graph g){
    g->top=-1;
    f(i,g->vertices){
        if(!g->visted[i])dfs(g,i);
        
    }
    graph g2=cg(g->vertices);
    f(i,g->vertices){
        f(j,g->vertices)
        g2->a[i][j]=g->a[j][i];
    }
    int c=0;
    while(g->top!=-1){
        int i=g->stack[g->top--];
        if(!g2->visted[i]){
            c++;
            dfs2(g2,i);
        }
       // g->top--;
    }
    return c;
}





int main(){
    int n;
    in(n);
    graph g=cg(n);
    f(i,n){
        int a[n];
        f(j,n){in(a[j]);
        if(a[j]==1)
        addedge(g,i+1,j+1);
        }
    }
   // print(g);
 //  iout(troposort(g));
   // f(j,g->vertices){g->visted[j]=0;}g->top=-1;
  // iout(scc(g));
   char ch;//iout(tree(g));
    while(ch!='x'){
        scanf(" %c",&ch);int a,b;
        switch(ch){
            case 't':
            //inn(a,b); 
            f(i,g->vertices)g->visted[i]=0;
           iout(troposort(g));
           
            break;
            case 'c':
            f(i,g->vertices)g->visted[i]=0;
            iout(scc(g)); 
            break;

        }
    }




}