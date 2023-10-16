//write codes for all operation regarding cicular doubly linked list

#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node*prev;
    int data;
    struct Node*next;
}*head=NULL;
void Create(int *A,int len){
    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=A[0];
    head->next=head;
    head->prev=head;
    struct Node*tail=head;
    for(int i=1;i<len;i++){
        struct Node*t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->prev=tail;
        t->next=head;
        tail->next=t;
        tail=t;
    }
    head->prev=tail;
}
void Display(struct Node*p){
    do{
        printf("%d ",p->data);
        p=p->next;
    }while(p!=head);
    printf("\n");    
}
//inserting after the pos node
void Insert(int pos,int x){
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    if(pos == 0){
        t->next=head;
        t->prev=head->prev;
        head->prev->next=t;
        head->prev=t;
        head=t;
    }else{
        struct Node*p=head;
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        t->prev=p;
        t->next=p->next;
        p->next->prev=t;
        p->next=t;
    }
}
//Deleting the node at pos position
int Delete(struct Node*p,int pos){
    struct Node*temp;
    int x;
    if(pos==1){
        head=p->next;
        if(head){
            head->prev=p->prev;
            p->prev->next=head;
        }
        x=p->data;
        free(p);
    }else{
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        p->prev->next=p->next;
        p->next->prev=p->prev;
        x=p->data;
        free(p);
    }

    return x;
}
int main(){
    int A[]={1,3,4,5};
    Create(A,sizeof(A)/sizeof(A[0]));
    Insert(5,2);
    Delete(head,5);
    Display(head);
    return 0;
}