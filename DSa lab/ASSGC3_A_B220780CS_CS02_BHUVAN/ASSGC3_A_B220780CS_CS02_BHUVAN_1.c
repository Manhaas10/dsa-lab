
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
};
typedef struct graph* graph;
graph cg(int n){
    graph g=malloc(sizeof(struct graph));
    g->vertices=n;//n++;
    g->a=(int**)malloc(n*sizeof(int*));
    
    for(int i=0;i<n;i++){
        g->a[i]=(int*)malloc(n*sizeof(int));
    }
    g->visted=(int*)malloc(n*sizeof(int));
   // g->visted=0;
    return g;
}
void intialize(graph g){
     for(int i=0;i<g->vertices;i++){
        g->visted[i]=0;
        for(int j=0;j<g->vertices;j++){
            g->a[i][j]=0;

        }
        //printf("\n");
    }
}
void addedge(graph g,int x,int y){
    g->a[x-1][y-1]=1;
    g->a[y-1][x-1]=1;
}
int minn(int a,int b){
    if(a<b)return a;
    else return b;
}
// void print(graph g){
//     for(int i=0;i<g->vertices;i++){

//         for(int j=0;j<g->vertices;j++){
//             printf("%d ",g->a[i][j]);

//         }
//         printf("\n");
//     }
// }
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int s=0;int x;
void dfs2(graph g,int y,int* v){
    g->visted[y]=1;
   //s-- v[x++]=y;
    s++;
    for(int i=0;i<g->vertices;i++){
        if(g->a[y][i] && !g->visted[i]){
            dfs2(g,i,v);
        }
    }
}
void dfs(graph g,int y){
    g->visted[y]=1;
    //v[x++]=y;
    s++;
    for(int i=0;i<g->vertices;i++){
        if(g->a[y][i] && !g->visted[i]){
            dfs(g,i);
        }
    }
}

int diffconnectedgraph(graph g){
    int c=0;
int com[g->vertices];
int j=0;
    for(int i=0;i<g->vertices;i++){
        if(!g->visted[i]){
            s=0;
            dfs(g,i);
            com[j++]=s;
            c++;
        }
    }
    qsort(com,j,sizeof(int),compare);
    for(int i=0;i<j;i++){
        printf("%d ",com[i]);
    }
    printf("\n");

    return c;
}
int diffconnectedgraph1(graph g){
    int c=0;
int com[g->vertices];
int j=0;
    for(int i=0;i<g->vertices;i++){
        if(!g->visted[i]){
            s=0;int v[100];x=0; 
            dfs2(g,i,v);
            com[j++]=s;            
            c++;
        }
    }
    return c;
}
int bride=0;int time=0;
void bridgedfs(graph g,int v,int parent,int low[],int dtime[]){
    g->visted[v]=1;
    dtime[v]=++time;
    low[v]=time;
    for(int i=0;i<g->vertices;i++){
        if(g->a[v][i]){
            int u=i;
            if(!g->visted[i]){
            bridgedfs(g,u,v,low,dtime);
            low[v]=minn(low[u],low[v]);
            if(low[u]>dtime[v]){
                //bridge
                bride++;
            }
            else if(u!=parent){
                low[v]=minn(low[v],dtime[u]);
            }  
            
            }
            else if(u!=parent){
                low[v]=minn(low[v],dtime[u]);
            } 
        }
        

    }



}
int bridge(graph g){
    int low[g->vertices];
    int dtime[g->vertices];
    for(int i=0;i<g->vertices;i++){
        low[i]=0;
        dtime[i]=0;
        g->visted[i]=0;
    }
    for(int i=0;i<g->vertices;i++){
        if(!g->visted[i]){
            bridgedfs(g,i,-1,low,dtime);
        }
    }
    return bride==0?-1:bride;
}
int t=0;
void articulationdfs(graph g,int v,int parent[],int low[],int dtime[],int hash[]){
    int child=0;
    g->visted[v]=1;
    dtime[v]=++t;
    low[v]=t;
    for(int i=0;i<g->vertices;i++){
        if(g->a[v][i]){
            int u=i;
            if(!g->visted[i]){
                child++;
                parent[u]=v;
                articulationdfs(g,u,parent,low,dtime,hash);
                low[v]=minn(low[u],low[v]);
                if(parent[v]==-1 && child>1){
                    hash[v]=1;
                }
                 if(parent[v]!=-1 && low[u]>=dtime[v]){
                    hash[v]=1;
                }
                else if(u!=parent[v]){
                    low[v]=minn(low[v],dtime[u]);
                }

            }
            else if(u != parent[v]) {
                low[v] = minn(low[v],dtime[u]);
            }

        }
        
        }
}
int articulationp(graph g){
    time=0;
     int low[g->vertices];
    int dtime[g->vertices];
    int parent[g->vertices];
    int hash[g->vertices];
     for(int i=0;i<g->vertices;i++){
        low[i]=0;
        dtime[i]=0;
        g->visted[i]=0;
        parent[i]=-1;
        hash[i]=0;
    }
    for(int i=0;i<g->vertices;i++){
        if(!g->visted[i]){
            articulationdfs(g,i,parent,low,dtime,hash);
        }
    }
    int ans=0;
    for(int i=0;i<g->vertices;i++){
        if(hash[i])ans++;
    }
    return ans==0?-1:ans;

}
int isn(char ch){
    return ch>='0'&& ch<='9';
}
int main(){
    int n;
    scanf(" %d",&n);
    graph g=cg(n);
    intialize(g);
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
   // print(g);
    char ch;//iout(tree(g));
    while(ch!='t'){
        scanf(" %c",&ch);int a,b;
        switch(ch){
            case 's':
            //inn(a,b); 
            f(i,g->vertices)g->visted[i]=0;
            diffconnectedgraph(g);
           
            break;
            case 'b':
            f(i,g->vertices)g->visted[i]=0;
           iout(bridge(g)); 
            break;
            case'a':
             f(i,g->vertices)g->visted[i]=0;
            iout(articulationp(g));
            break;
            case'n':
             f(i,g->vertices)g->visted[i]=0;
           iout(diffconnectedgraph1(g));
           break;


        }
    }
    

}