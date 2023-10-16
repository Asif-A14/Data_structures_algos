//since queue using linked list have no fixed size it will no be full till the heap have memory.
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
}*front=NULL,*rear=NULL;
void enqueue(int x)
{
    struct Node*t=(struct Node*)malloc(sizeof(struct Node));
    if(t==NULL)
        printf("Queue is full\n");
    else{
        t->data=x;
        t->next=NULL;
        if(front==NULL){
            front=rear=t;
        }else{
            rear->next=t;
            rear=t;
        }
    }
}
int dequeue()
{
    int x=-1;
    if(front==NULL)
        printf("Queue is empty\n");
    else{
        struct Node*p=front;
        front=front->next;
        x=p->data;
        free(p);
    }
    return x;
}
void display(struct Node*p)
{
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    dequeue();
    enqueue(10);
    display(front);
    return 0;
}