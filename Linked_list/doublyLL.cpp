//write codes for all operation regarding doubly linked list

#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node*prev;
    int data;
    struct Node*next;
}*head=NULL;
void create(int *A,int len){
    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=A[0];
    head->prev=head->next=NULL;
    struct Node*tail=head;
    for(int i=1;i<len;i++){
        struct Node*q=(struct Node*)malloc(sizeof(struct Node));
        q->data=A[i];
        q->next=tail->next;
        q->prev=tail;
        tail->next=q;
        tail=q;
    }
}
void Display(struct Node*p){
    while(p->next){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("%d\n",p->data);
    while(p){
        printf("%d ",p->data);
        p=p->prev;
    }
}
void Insert(int pos,int x){
    struct Node*t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    if(pos==0){
        head->prev=t;
        t->next=head;
        t->prev=NULL;
        head=t;
    }else{
        struct Node*p=head;
        for(int i=1;i<pos-1;i++){
            p=p->next;
        }
        t->next=p->next;
        t->prev=p;
        if(p->next)
            p->next->prev=t;
        p->next=t;
    }
}
int Delete(struct Node*p,int pos){
    //struct Node*temp;
    int x;
    if(pos==1){
        head=head->next;
        if(head)
            head->prev=NULL;
        x=p->data;
        free(p);
    }else{
        for(int i=1;i<pos;i++){
            p=p->next;
        }
        p->prev->next=p->next; 
        if(p->next)
            p->next->prev=p->prev;
        x=p->data;
        free(p);
    }
    return x;
}
void Reverse(struct Node*p){
    struct Node*temp;
    while(p){
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p && p->next==NULL)
            head=p;
    }
}
int main(){
    int A[]={1,2,3,4,5,6};
    create(A,sizeof(A)/sizeof(A[0]));
    Reverse(head);
    Display(head);
    return 0;
}