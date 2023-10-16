#include<stdio.h>
#define size 5
struct queue
{
    int Q[size];
    int front=0;
    int rear=0;
};

void enqueue(struct queue*q,int x)
{
    if((q->rear+1)%size == q->front)
        printf("Queue is full\n");
    else
    {
        q->rear=(q->rear+1)%size;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct queue*q)
{   int x=-1;
    if(q->rear==q->front)
        printf("Queue is empty!!!\n");
    else
    {
        q->front=(q->front+1)%size;
        x=q->Q[q->front];
    }
    return x;
}

void display(struct queue q)
{
    int i=q.front+1;
    do{
        printf("%d ",q.Q[i]);
        i=(i+1)%size;
    }while(i!=(q.rear+1)%size);
    printf("\n");
}



int  main()
{
    struct queue q;
    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,3);
    enqueue(&q,4);
    dequeue(&q);
    enqueue(&q,5);
    dequeue(&q);
    enqueue(&q,5);
    dequeue(&q);
    enqueue(&q,5);
    display(q);
}