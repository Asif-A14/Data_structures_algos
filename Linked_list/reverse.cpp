//code for reversing a linked list through different methods
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
}*head=NULL;

void create(int *A,int len){
    head=(Node*)malloc(sizeof(struct Node));
    head->data=A[0];
    struct Node*p=head;
    struct Node*q;
    head->next=NULL;
    for(int i=1;i<len;i++){
        q=(Node*)malloc(sizeof(struct Node));
        q->data=A[i];
        q->next=NULL;
        p->next=q;
        p=q;
    }
}
void Display(struct Node*p){
    while (p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
void reverse(){
    struct Node*p,*q,*r;
    p=head;
    q=NULL;
    while(p){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    head=q;
}
void reverse1(){
    struct Node*prev,*curr,*nxt;
    curr=head;
    prev=NULL;
    while(curr){
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    head=prev;
}
void Rreverse(struct Node*p,struct Node*q){
    if(p){
        Rreverse(p->next,p);
        p->next=q;
    }else{
        head=q;
    }
}

int main(){
    int A[]={1,2,3,4,5,6};
    create(A,sizeof(A)/sizeof(A[0]));
    Display(head);
    reverse();
    Display(head);
    reverse1();
    Display(head);
    Rreverse(head,NULL);
    Display(head);
}