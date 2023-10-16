#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node*next;
}*top=NULL;

void push(int x)
{
    struct Node*temp=(struct Node*)malloc(sizeof(struct Node));
    if(temp==NULL)
        printf("Stack Overflow");
    else{
        temp->data=x;
        temp->next=top;
        top=temp;
    }
}
int pop()
{   
    int x=-1;
    if(top==NULL)
        printf("Stack Underflow");
    else
    {
        struct Node*p=top;
        top=top->next;
        x=p->data;
        free(p);
        return x;
    }
    return x;
}
int peek(int pos)
{
    struct Node*p=top;
    for(int i=0;i<pos-1;i++)
        p=p->next;
    if(p)
        return p->data;
    return -1;
}
void Display(struct Node*p)
{
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    Display(top);
    int x = pop();
    Display(top);
    printf("%d %d",peek(3),x);
}