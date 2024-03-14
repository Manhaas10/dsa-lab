
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
    struct node* left;
    struct node* right;
    int h;
};
typedef struct node* node;
int height(node root){
    if(root==NULL)return 0;
    return root->h;
}
node cn(int k){
    node temp=malloc(sizeof(struct node));
    temp->left=NULL;
    temp->right=NULL;
    temp->key=k;
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

node insert(node root,int k){
    if(!root) return cn(k);
    if(k>root->key)root->right=insert(root->right,k);
    else root->left=insert(root->left,k);
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

void preorder(node root){
    if(root){
        printf("%d ",root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
int a[1000];int j=0;
void search(node root,int k){
    if(!root){iout(-1);return;}
    while(root)
    {
    if(root->key==k){a[j++]=k;break;}
    else if(root->key>k){a[j++]=root->key;root=root->left;}
    else {a[j++]=root->key;root=root->right;}
    }
}

int main(){
//CHECK ON TOPVIEW SIDE VIEW ETC
char ch;
node root=NULL;
while(ch!='e'){
    cin(ch);
    int k;
    switch(ch){
        case 'i':
         in(k);
         root=insert(root,k);
         break;
         case 's':
         printf("%d %d",c2,c1);
         printf("\n");
         break;
         case'p':
         preorder(root);
         printf("\n");
         break;
         case 'x':
         in(k);
         search(root,k);
         if(j>0 && a[j-1]==k){
            f(i,j)printf("%d ",a[i]);printf("\n");
         }

         else if(j>0)iout(-1);
         j=0;
         break;

    }
}







}