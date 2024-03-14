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

int maxx(int a,int b){
    if(a>b)return a;
    else return b;
}
int minn(int a,int b){
    if(a<b)return a;
    else return b;
}
struct node{
    int key;
    int val;
    struct node* left;
    struct node* right;
    int h;
};
typedef struct node* node;
int height(node root){
    if(root==NULL)return 0;
    return root->h;
}
node cn(int k,int v){
    node temp=malloc(sizeof(struct node));
    temp->left=NULL;
    temp->right=NULL;
    temp->key=k;
    temp->val=v;
    temp->h=1;
    return temp;
}
//left left
int c1=0;
node rightrotate(node root){
    c1++;
    node x1=root->left;
    node x2=x1->right;
    x1->right=root;
    root->left=x2;

  
    root->h=maxx(height(root->left),height(root->right))+1;
      x1->h=maxx(height(x1->left),height(x1->right))+1;

    return x1;
}
//right right
int c2=0;
node leftrotate(node root){
    c2++;
    node x1=root->right;
    node x2=x1->left;
    x1->left=root;
    root->right=x2;


    root->h=maxx(height(root->left),height(root->right))+1;
        x1->h=maxx(height(x1->left),height(x1->right))+1;

    return x1;
}
int balence(node root){
    if(!root)return 0;
    return height(root->left)-height(root->right);
}

node insert(node root,int k,int v){
    if(!root) return cn(k,v);
    if(k>root->key)root->right=insert(root->right,k,v);
    else if(k<root->key) root->left=insert(root->left,k,v);
    else {root->val=v;return root;}
    root->h=maxx(height(root->left),height(root->right))+1;
    int bal=balence(root);
    // left left
    if(bal>1 && k<root->left->key){return rightrotate(root);}
    //right right
    if(bal<-1 && k>root->right->key){return leftrotate(root);}

    //left right
    if(bal>1 && k>root->left->key){
        root->left=leftrotate(root->left);
        return rightrotate(root);
        return root;
    }
//right left
    if(bal<-1 && k<root->right->key){
        root->right=rightrotate(root->right);
        return leftrotate(root);
    }
    return root;
}
int c=-1;
node a[10000];int j=0;
int inorder(node root){
    if(root){
        inorder(root->left);
        a[j++]=root;
        inorder(root->right);
    }
}
int main(){

    char ch;node root=NULL;
    while(ch!='t'){
        cin(ch);
        int k,v;int i;
        switch(ch){
            case 'i':
            inn(k,v);
            root=insert(root,k,v);
            break;
            case 'l':
            in(k);
            j=0;i=0;
            inorder(root);
            for(i=0;i<j;i++){
                node temp=a[i];
                if(temp->key>=k)break;
            }
            if(i<j){
                node temp=a[i];
                printf("%d %d",temp->key,temp->val);
                printf("\n");
            }
            else{
                iout(-1);
            }
            break;
            case 'f':
              in(k);
              i=0,j=0;
              inorder(root);
              for(i=0;i<j;i++){
                node temp=a[i];
                //printf("%d ",temp->key);
                if(temp->key==k)break;
              }
              if(i<j){
                node temp=a[i];
                printf("%d %d",temp->key,temp->val);
                printf("\n");
              }
              else iout(-1);
              break;
             case 's':
             j=0;
             inorder(root);
             iout(j);
             break;
             case 'e':
             j=0;
             inorder(root);
             iout(a[0]==NULL);
             break;
             case'p':
             j=0;
             inorder(root);
             if(a[0]==NULL)iout(-1);
             else{
                f(i,j){
                    printf("%d ",a[i]->key);
                }
                printf("\n");
             }
             break;


            
        }

    }
}