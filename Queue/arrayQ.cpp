#include<stdio.h>
#define size 5
struct queue
{
    int Q[size];
    int front=-1;
    int rear=-1;
};

void enqueue(struct queue*q,int x)
{
    if(q->rear == size - 1)
        printf("Queue is full");
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct queue*q)
{   int x=-1;
    if(q->rear==q->front)
        printf("Queue is empty!!!");
    else
    {
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}

void display(struct queue q)
{
    for(int i=q.front+1;i<=q.rear;i++)
    {
        printf("%d ",q.Q[i]);
    }
    printf("\n");
}



int  main()
{
    struct queue q;
    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,3);
    enqueue(&q,4);
    enqueue(&q,5);
    dequeue(&q);
    display(q);
    enqueue(&q,1);
}