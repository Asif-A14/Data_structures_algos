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
void print(struct Node*p){
    while (p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
void RDisplay(struct Node*p){
    if(p){
        printf("%d ",p->data);
        RDisplay(p->next);
    }
}

int main(){
    int A[]={1,2,3,4,5,6};
    create(A,sizeof(A)/sizeof(A[0]));
    print(head);
    RDisplay(head);
}