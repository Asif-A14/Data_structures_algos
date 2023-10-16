#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *left;
    int data;
    struct Node *right;
}*root=NULL;

struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};
void create(struct Queue *q,int size)
{
    q->size=size;
    q->front=q->rear=0;
    q->Q=(struct Node **)malloc(q->size*sizeof(struct Node*));
}
void enqueue(struct Queue *q,struct Node *x)
{
    if((q->rear+1)%q->size==q->front)
        printf("Queue is Full");
    else
    {
    q->rear=(q->rear+1)%q->size;
    q->Q[q->rear]=x;
    }
}
struct Node * dequeue(struct Queue *q)
{
    struct Node* x=NULL;

    if(q->front==q->rear)
        printf("Queue is Empty\n");
    else
    {
    q->front=(q->front+1)%q->size;
    x=q->Q[q->front];
    }
    return x;
}
int isEmpty(struct Queue q)
{
    return q.front==q.rear;
}
struct Node* newNode(int x)
{
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->left=NULL;
    t->right=NULL;
    return t;
}

void Levelwise(struct Node*p)
{
    struct Queue q;
    create(&q,10);
    enqueue(&q,p);
    while(!isEmpty(q))
    {
        struct Node*t =dequeue(&q);
        enqueue(&q,t->left);
        enqueue(&q,t->right);
        printf("%d ",t->data);
    }
}

int main()
{
    root=(struct Node*)malloc(sizeof(struct Node));
    root->data=1;
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    Levelwise(root);
}