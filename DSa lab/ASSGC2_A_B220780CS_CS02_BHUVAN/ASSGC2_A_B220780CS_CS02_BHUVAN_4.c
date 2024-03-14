
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
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
int isc(char ch){
    return ch>='A'&& ch<='Z';
}
int check_n(char ch){
    return ch>='0'&&ch<='9';
}
struct node{
    int key;
    struct node* left;
    struct node* right;
   // struct node* parent;
	char color;
};
typedef struct node* node;
node cn(int k){
    node temp=malloc(sizeof(struct node));
    temp->left=NULL;
   // temp->parent=NULL;
    temp->right=NULL;
    temp->key=k;
    temp->color='R';
    return temp;
}
int i=0;
node build_tree(char* s){
    node root;
    if(!s[i]) return NULL;
        if(s[i]=='('){(i)++;
        if(s[i]==' '){(i)++;}
        if(s[i]==')'){(i)++;return NULL;}

            int num = 0;
            while (check_n(s[i])) {
                num = num * 10 + (s[i] - '0');
                (i)++;
            }
             if(s[i]==' '){(i)++;}
             
            root=cn(num);
            if(isc(s[i]))root->color=s[i++];
            if(s[i]==' '){(i)++;}
            
            root->left=build_tree(s);
            if(s[i]==' '){(i)++;}

            root->right=build_tree(s);
            if(s[i]==' '){(i)++;}
            if(s[i]==')'){(i)++;}

            return root;
        }
        return NULL;
}
bool isred(node nod) {
    return nod && +(nod->color=='R');
}
int validrbt(node root,int* blackh){
    if(!root){
        *blackh=1;
        return 1;
    }
    int lbh=0,rbh=0;
   int lbv=validrbt(root->left,&lbh);
   int rbv=validrbt(root->right,&rbh);
   if(isred(root)){
    if(isred(root->left)||isred(root->right))return 0;
    if(lbh!=rbh)return 0;
    *blackh=lbh;
   }
   else{
    if(lbh!=rbh)return 0;
    *blackh=lbh+1;
   }
   return 1;

}
int checkrbt(node root) {
    if (!root)return 1; 

    int black_height = 0; 
    return validrbt(root,&black_height);
}

int main(){
    char s[100000];
    scanf(" %[^\n]",s);
node root=build_tree(s);
if(root && root->color=='R')iout(0);
else
iout(checkrbt(root));
//print(root);

}