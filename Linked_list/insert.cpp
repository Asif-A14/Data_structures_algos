//insert a node at any point in the given linked list
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
}*head=NULL;

Node* newNode(int n){
    struct Node*q=(Node*)malloc(sizeof(struct Node));
    q->data=n;
    q->next=NULL;
    return q;
}
void create(int *A,int len){
    head=(Node*)malloc(sizeof(struct Node));
    head->data=A[0];
    struct Node*p=head;
    struct Node*q;
    head->next=NULL;
    for(int i=1;i<len;i++){
        q=newNode(A[i]);
        p->next=q;
        p=q;
    }
}
int count(struct Node*p){
    int c=0;
    while(p){
        p=p->next;
        c++;
    }
    return c;
}
void insert(int n,int pos){
    struct Node*t=newNode(n);
    struct Node*p=head;
    if(pos==1){
        t->next=head;
        head=t;
    }else{
        for(int i=1;i<pos-1;i++){
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
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
//    int A[]={1,2,3,4,5,6};
//    create(A,sizeof(A)/sizeof(A[0]));
//    print(head);
//    RDisplay(head);
//    printf("%d ",count(head));
    insert(1,1);
    insert(2,2);
    insert(3,3);
    insert(4,4);
    RDisplay(head);
}