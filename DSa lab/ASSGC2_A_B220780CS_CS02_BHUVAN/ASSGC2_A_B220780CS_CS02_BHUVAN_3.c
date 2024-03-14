
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
    struct node* parent;
	char color;
};
typedef struct node* node;
struct rbt{
    node nil;
    node roott;
};
typedef struct rbt* rbt;
node cn(int k){
    node temp=malloc(sizeof(struct node));
    temp->left=NULL;
    temp->parent=NULL;
    temp->right=NULL;
    temp->key=k;
    temp->color='R';
    return temp;
}
rbt crbt(int key){
   rbt crbt=malloc(sizeof(struct rbt));
   crbt->roott=cn(key);
  crbt->nil = malloc(sizeof(struct node)); 
  crbt->nil=NULL;
   return crbt;
}
void leftr(rbt t,node root){
    
node x=root->right;
    root->right=x->left;
    if(x->left!=NULL)x->left->parent=x;
    x->parent=root->parent;
    if(root->parent==NULL)t->roott=x;
    else if(root==root->parent->left)root->parent->left=x;
    else root->parent->right=x;;
	x->left=root;
	root->parent=x;

	//return x;
}
void rightr(rbt t,node root){
 node x=root->left;
    root->left=x->right;
    if(x->right!=NULL)x->right->parent=x;
    x->parent=root->parent;
    if(root->parent==NULL)t->roott=x;
    else if(root==root->parent->right)root->parent->right=x;
    else root->parent->left=x;;
	x->right=root;
	root->parent=x;

	///return x;
}
int l=0,lr=0,rl=0,rr=0;

void insertfix(rbt root,node z){
    while(z->parent->color=='R'){
         //printf("%d",z->parent->key);
        if(z->parent==z->parent->parent->left){
            node y=z->parent->parent->right;
            if(y){
                if(y->color=='R'){
                z->parent->color='B';
                y->color='B';
                if(z->parent->parent!=root->roott)
                {
                    z->parent->parent->color='R';
                z=z->parent->parent;
                }
            }}
            else{
                
                if(z==z->parent->right){
                    z=z->parent;
                    leftr(root,z);}
                    z->parent->color='B';
                    z->parent->parent->color='R';
                   rightr(root,z->parent->parent);
                   break;
                   
                
            }
        }
        else{
            node y=z->parent->parent->left;
            
            if(y){
             if(y->color=='R'){
                
                z->parent->color='B';
                y->color='B';
                if(z->parent->parent!=root->roott)
                {z->parent->parent->color='R';
                z=z->parent->parent;}
            }}
            else{
                
                if(z==z->parent->left){
                    z=z->parent;
                    rightr(root,z);}
                    z->parent->color='B';
                    z->parent->parent->color='R';
                    leftr(root,z->parent->parent);
                    
                
            }

        }
    }
    root->roott->color='B';
    //return root;

}
void insert(rbt root,node z){
 node x=root->roott;

 node y=NULL; 
 while(x!=NULL){
    
    y=x;
    if(z->key<x->key){
        x=x->left;
    }
    else x=x->right;
 }
 z->parent=y;
 if(y==NULL)root->roott=z;
 else if(z->key<y->key)y->left=z;
 else {y->right=z;}
 z->left=NULL;
 z->right=NULL;
 z->color='R';
 insertfix(root,z);

 //return root;

}

void print(node root){
    if(!root){
        printf("( ) ");
        return;
    }
    printf("( %d %c ",root->key,root->color);
    print(root->left);
    print(root->right);
    printf(") ");
}


int main(){
    char a[100];
    sin(a);
        int i=0;int num=0;
        while(a[i]!='\0'){
            num=num*10+a[i]-'0';
            i++;
        }
        rbt t=crbt(num);
       t->roott->color='B';
        print(t->roott);
         printf("\n");
         a[0]='\0';
    while(a[0]!='e'){
        a[0]='\0';
        sin(a);
        if(a[0]!='e')
        {
            int i=0;int num=0;
        while(a[i]!='\0'){
            num=num*10+a[i]-'0';
            i++;
        }
        node z=cn(num);
       // iout(num);
      insert(t,z);
        print(t->roott);

        printf("\n");
        //inorder(root);
        }


    }
    



}




