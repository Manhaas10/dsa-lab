#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct queue{
    char name[1000][100];
    char time[100][100];
    int p[1000];
    int size;
    int capacity;
};
typedef struct queue* q;
q cpq(int n){
    q pq=malloc(sizeof(struct queue));
    pq->size=0;
    pq->capacity=n;
    return pq;
}

q add(q pq,int pr,char* n,char* t){
    pq->size++;
    strcpy(pq->name[pq->size-1],n);
    strcpy(pq->time[pq->size-1],t);
    int i=pq->size-1;//pq->p[i]=pr;
    while(i>0 && pr>pq->p[i-1]){
        pq->p[i]=pq->p[i-1];
        strcpy(pq->name[i],pq->name[i-1]);
        strcpy(pq->time[i],pq->time[i-1]);
        i--;
    }
     while(i>0 && pr==pq->p[i-1] && strcmp(pq->time[i-1],pq->time[i])==1){
        pq->p[i]=pq->p[i-1];
        strcpy(pq->name[i],pq->name[i-1]);
        strcpy(pq->time[i],pq->time[i-1]);
        i--;
    }
    pq->p[i]=pr;
    strcpy(pq->name[i],n);
    strcpy(pq->time[i],t);
    return pq;
}


void treatp(q pq){
    if(pq->size==0)return;
    printf("%s %d %s\n",pq->name[0],pq->p[0],pq->time[0]);
    for(int i=1;i<pq->size;i++){
        pq->p[i-1]=pq->p[i];
        strcpy(pq->name[i-1],pq->name[i]);
        strcpy(pq->time[i-1],pq->time[i]);
    }
    pq->size--;
}
void checknp(q pq){
    if(pq->size==0)return;
    printf("%s %d %s\n",pq->name[0],pq->p[0],pq->time[0]);
}
q discharge(q pq,char* nn,char* t){
    int i=0;int n=pq->size;
    //printf("%s %s",nn,t);
    while(strcmp(pq->name[i],nn)!=0 || strcmp(pq->time[i],t)!=0 && i<n){i++;}
    if(i!=n){
        for(int j=i;j<n-1;j++){
            strcpy(pq->name[j],pq->name[j+1]);
            strcpy(pq->time[j],pq->time[j+1]);
            pq->p[j]=pq->p[j+1];
        }
    }pq->size--;
    return pq;
}
q upp(q pq,char* n,char* t,int pr){
        //int i=0;int n=pq->size;
    //while(strcmp(pq->name[i],nn)!=0 && strcmp(pq->time[i],t)!=0 && i<n){i++;}
    pq=discharge(pq,n,t);
    pq=add(pq,pr,n,t);
    return pq;
}
void print(q pq){
    if(pq->size==0)return;
    int i=0;int n=pq->size;
    for(int i=0;i<n;i++){
        printf("%s %d %s\n",pq->name[i],pq->p[i],pq->time[i]);
    }
}

int main(){
    char ch;char n[1000],time[100];int p;
    q pq=cpq(10000);
    while(ch!='e'){
        scanf("%c",&ch);
        switch(ch){
            case 'a':
             scanf("%s %d %s",n,&p,time);
             pq=add(pq,p,n,time);
             break; 
            case 't':
            treatp(pq);
            break;
            case 'c':
            checknp(pq);
            break;
            case 'd':
            scanf("%s %s",n,time);
            pq=discharge(pq,n,time);break;
            case 'u':
            scanf("%s %s %d",n,time,&p);
            pq=upp(pq,n,time,p);
            break;
            case 'p':
            print(pq);break;
            case 'e':break;
        }
    }




}
