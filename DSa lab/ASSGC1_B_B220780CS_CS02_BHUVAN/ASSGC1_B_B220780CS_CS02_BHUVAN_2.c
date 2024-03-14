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
int maxx(int a,int b){
    if(a>b)return a;
    else return b;
}
int minn(int a,int b){
    if(a<b)return a;
    else return b;
}
int isn(char ch){
    return (ch>='0' && ch<='9');
}
struct treenode{
    int key;
    struct treenode* left;
    struct treenode* right;
};
typedef struct treenode* node;
struct igris{
    int isbst;
    int max,min,sum;
};
typedef struct igris* igris;

node c_n(int k){
    node temp=malloc(sizeof(struct treenode));
    temp->key=k;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}int m=0;
void levelorder(node root,int level){
    if(!root)return;
    if(level==1){m=maxx(m,root->key);
        printf("%d ",root->key);}
    else if(level>1){

            levelorder(root->left,level-1);

           levelorder(root->right,level-1);

    }
}
int a[100];int ss=0;
void levelorderr(node root,int level){
    if(!root)return;
    if(level==1){a[ss++]=root->key;}
    else if(level>1){

            levelorderr(root->left,level-1);

           levelorderr(root->right,level-1);

    }
}
int fH(node root) {
    if (!root) return 0;
    if (!root->left&& !root->right) return 1;
    
    int lH = fH(root->left);
    int rH = fH(root->right);

    return (lH>rH)?(lH+1):(rH+1);
}
void printrightview(node root){
    // if(!root)return;
    // if(root->right){printf("%d ",root->key);printrightview(root->right);}
    // else if(root->left){printf("%d ",root->key);printrightview(root->left);}
    // else printf("%d ",root->key);
     int h=fH(root);
    for(int i=1;i<=h;i++){
        ss=0;
         levelorderr(root,i);
         printf("%d ",a[ss-1]);
    }

}

void printlevelorder(node root){
    int h=fH(root);
    for(int i=1;i<=h;i++){
         levelorder(root,i);
    }
}
node build_tree(char* s,int* i){
    if(s[*i]=='('){(*i)++;
    if(s[*i]==')'){(*i)++;return NULL;}
    int num=0;
    while(isn(s[*i])){
        num=num*10+s[*i]-'0';
       ( *i)++;
    }
    node root=c_n(num);
   
       root->left=build_tree(s,i);

        root->right=build_tree(s,i);
        if(s[*i]==')')(*i)++;
    return root;}
    return NULL;

}
igris c_i(int isb,int mi,int ma,int su){
    igris i=malloc(sizeof(struct igris));
    i->isbst=isb;
    i->min=mi;
    i->max=ma;
    i->sum=su;
    return i;
}
int ans=0;
igris maxbst(node root){
    if(!root) return c_i(1,INT_MAX,INT_MIN,0);
    
    igris l=maxbst(root->left);
    igris r=maxbst(root->right);
    if(r->isbst &&l->isbst && l->max<root->key && r->min>root->key ){
        int s=l->sum+r->sum+root->key;
        ans=maxx(ans,s);
        return c_i(1,minn(l->min,root->key),maxx(r->max,root->key),s);
    }
    else return c_i(0,0,0,0);
}
void maxibst(node root){
    maxbst(root);
    iout(ans);
}

int main(){
    int i=0;
    char st[100000];
    scanf("%s",st);
    char ss[1000000];
    int n=strlen(st);
    ss[0]='(';
    for(i=1;i<=n;i++) ss[i]=st[i-1];
    ss[i++]=')';ss[i]='\0';
i=0;
    node root=build_tree(ss,&i);


    char ch;
    while(ch!='e'){
        cin(ch);
        switch(ch){
            case 'l':
            printlevelorder(root);printf("\n");
            break;
            case 'm':
             maxibst(root);
            break;
            case 'r':
             printrightview(root);printf("\n");
             break;
        }
     
    }
    
    
    }