#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
int isn(char ch){
    return (ch>='0' && ch<='9');
}
node build_tree(char* s,int* i){
    if(s[*i]=='('){(*i)++;
    if(s[*i]==')'){(*i)++;return NULL;}
    int num=0;
    while(isn(s[*i])){
        num=num*10+s[*i]-'0';
       (*i)++;
    }
    node root=c_n(num);
   
       root->left=build_tree(s,i);

        root->right=build_tree(s,i);
        if(s[*i]==')')(*i)++;
    return root;}
    return NULL;

}
int b[100000];int s;
void print(node root){
    if (root) {
        print(root->left);
       b[s++]=root->key;
        print(root->right);
    }
    else return;
}
int a[1000000];int j;
void anscestor(node root,int k){
    if(!root)return;
    if(root->key>k){
        a[j++]=root->key;
        //printf("%d\n",root->key);
        anscestor(root->left,k);
    }
    else if(root->key<k){
        a[j++]=root->key;
        anscestor(root->right,k);
    }
    else {
        a[j++]=root->key;
        return;
    }

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
        int k,k1,k2;
        scanf("%c",&ch);
        
        switch(ch){
            case'a':
             scanf("%d",&k);j=0;
             anscestor(root,k);
              for(int kk=j-1;kk>=0;kk--)printf("%d ",a[kk]);
              printf("\n");
              break;
            case'p':
            scanf("%d %d",&k1,&k2);
            s=0;
            print(root);

            for(int m=0;m<s;m++){
                if(b[m]>=k1 && b[m]<=k2)printf("%d ",b[m]);
            }
            printf("\n");
            break;
        }

    }

}