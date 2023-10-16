//check if there is loop in the given linked list or not;
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
int isLoop(struct Node*head){
    struct Node*q,*p;
    p=q=head;
    do{
        q=q->next;
        p=p->next;
        q=q?q->next:q;
    }while(p && q && p!=q);
    return p==q?1:0;
}

int main(){
    int A[]={1,2,3,4,5};
    create(A,sizeof(A)/sizeof(A[0]));
    struct Node*t1,*t2;
    //t1=head->next->next;
    t2=head->next->next->next->next;
    //t2->next=head;
    //printf("%d ",t1->data);
    if(isLoop(head))
        printf("There is LOOP in given Linked List");
    else
        printf("No LOOP exists");

    //print(head);
}