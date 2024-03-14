#include <stdio.h>
#include <stdlib.h>
int stack[1000];
int top=-1;
struct node {
    int key;
    struct node* next;
};
typedef struct node* node;
node c_n(int k){
    node temp=(node)malloc(sizeof(struct node));
    temp->key=k;
    temp->next=NULL;
    return temp;
}
node in(node head,int k){
    if(!head)return c_n(k);
    node temp=head;
    node new=c_n(k);
    while(temp->next)temp=temp->next;
    temp->next=new;
    new->next=NULL;
    return head;
}
node del(node head,int i){
if(!head){printf("-1\n");return NULL;}
    int j=1;node temp=head,prev=head;int kk=0,f=0;
    if(i==1){
        printf("%d\n",head->key);
        head=head->next;return head;
    }
    while(j!=i && temp){
        prev=temp;
        temp=temp->next;
        j++;
    }
    if(j==i && temp){
        printf("%d\n",temp->key);
        prev->next=temp->next;
    }
    else printf("-1\n");
    return head;
}
node dup(node head){
    if(!head){printf("-1\n");return NULL;}
    node temp1,temp2;
    temp1=head;
    while(temp1 && temp1->next){
        temp2=temp1;
        while(temp2->next){
            if(temp1->key==temp2->next->key){
               
                temp2->next=temp2->next->next;
            }
            else temp2=temp2->next;

        }
        temp1=temp1->next;
    }
   // printf("\n");
    return head;
}
int ispali(node head){
    if(!head)return -1;
    node temp=head;
    while(temp){
        stack[++top]=temp->key;
        temp=temp->next;
    }
    temp=head;
    while(top!=-1 && temp){
        if(temp->key!=stack[top--])return 0;
        temp=temp->next;
    }
return 1;

}
void display(node head){
    if(!head){printf("-1\n");return;}
    node temp=head;
    while(temp){
        printf("%d ",temp->key);
        temp=temp->next;
    }
    printf("\n");
   
   
}
int main(){
    node head=NULL;
   char ch;
   while(ch!='e'){
    int k=0;
    scanf("%c",&ch);
    switch(ch){
        case'a':
          scanf("%d",&k);
          head=in(head,k);
          break;
        case'r':
          scanf("%d",&k);
          head=del(head,k);
          break;
        case'd':
          head=dup(head);
          display(head);
          break;
        case'p':
          k=ispali(head);
          if(k==-1)printf("-1\n");
          else if(k==0)printf("N\n");
          else printf("Y\n");
          break;
        case's':
          display(head);
          break;
        case'e':break;
    }
   }
}
