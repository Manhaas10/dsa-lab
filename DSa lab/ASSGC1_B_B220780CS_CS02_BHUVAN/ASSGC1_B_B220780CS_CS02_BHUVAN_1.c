
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define f(i,n) for(int i=0;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
#define in(n) scanf("%d",&n);
#define cin(c) scanf("%c",&c);
#define sin(s) scanf("%s",s);
#define inn(n,k) scanf("%d %d",&n,&k);
#define iout(n) printf("%d\n",n);
#define sout(s) printf("%s\n",s);
#define cout(c) printf("%c\n",c);
int maxx(int a,int b){
    if(a>b)return a;
    else return b;
}
struct treenode{
    int key;
    struct treenode* left;
    struct treenode* right;
};
typedef struct treenode* node;
node c_n(int k){
    node temp=malloc(sizeof(struct treenode));
    temp->key=k;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}
int search(int* in,int f,int l,int k){
    for(int j=f;j<=l;j++){
        if(in[j]==k)return j;
    }
    return 0;
}
int i=0;
node build_tree(int in[],int pre[],int f,int l){
    if(f>l)return NULL;
    node root=c_n(pre[i++]);
      if (f==l) return root;
    int ind=search(in,f,l,root->key);

    root->left=build_tree(in,pre,f,ind-1);
    root->right=build_tree(in,pre,ind+1,l);
    return root;
}

void print(node root){
    if (root) {
        print(root->left);
      
        print(root->right);
        printf("%d ",root->key);
    }
    else return;
}
int fH(node root) {
    if (!root) return 0;
    if (!root->left&& !root->right) return 1;
    
    int lH = fH(root->left);
    int rH = fH(root->right);

    return (lH>rH)?(lH+1):(rH+1);
}
int m=0;
void zigzagl(node root,int level){
    if(!root)return;
    if(level==1){m=maxx(m,root->key);
        printf("%d ",root->key);}
    else if(level>1){

            zigzagl(root->left,level-1);

            zigzagl(root->right,level-1);

    }
}
void zigzaglm(node root,int level){
    if(!root)return;
    if(level==1){m=maxx(m,root->key);}
    else if(level>1){

            zigzaglm(root->left,level-1);

            zigzaglm(root->right,level-1);

    }
}
void zigzagrm(node root,int level){
    if(!root)return;
    if(level==1){m=maxx(m,root->key);}
    else if(level>1){
            zigzagrm(root->right,level-1);
            zigzagrm(root->left,level-1);
        }

}
void zigzagr(node root,int level){
    if(!root)return;
    if(level==1){m=maxx(m,root->key);printf("%d ",root->key);}
    else if(level>1){
            zigzagr(root->right,level-1);
            zigzagr(root->left,level-1);
        }

}
int aa[100000];int y=0;
void printzigzag(node root){
    int h=fH(root);
    for(int i=1;i<=h;i++){
        if(i%2) zigzagl(root,i);
        else zigzagr(root,i);
    }
}
void maxlevel(node root){
    int h=fH(root);
    for(int i=1;i<=h;i++){
        m=0;
        if(i%2) zigzaglm(root,i);
        else zigzagrm(root,i);
        aa[y++]=m;
    }
}
int isleaf(node root){
    if(!root)return 0;
    else if(root->left==NULL&& root->right==NULL)return 1;
    return 0;
}
int leftleaves(node root){
    int s=0;
    if(root){
        if(isleaf(root->left)){s+=root->left->key;}
        else s+=leftleaves(root->left);
        s+=leftleaves(root->right);
        
    }
    return s;
}
int diameter(node root){
    if(!root)return 0;
    int lh=fH(root->left);
    int rh=fH(root->right);

    int ld=diameter(root->left);
    int rd=diameter(root->right);

    return maxx(lh+rh+1,maxx(ld,rd));

}
int main(){
    int n;
    in(n);int a[n],b[n];
    f(ii,n)in(a[ii]);
    f(ii,n)in(b[ii]);
    node root=build_tree(a,b,0,n-1);
        char ch;
        while(ch!='e'){
            int h1,hh,sss;
            cin(ch);
            switch(ch){
                case 'p':
                print(root);printf("\n");
                break;
                case 'z':
                  printzigzag(root);printf("\n");
                  break;
                case 'm':
                 maxlevel(root);
                 f(i,y) printf("%d ",aa[i]);printf("\n");
                 break;
                case 'd':
                  h1=diameter(root);
                 iout(h1);
                 break;

                case 's':
                  sss=leftleaves(root);iout(sss);
                 break;

            }
        }


    
}