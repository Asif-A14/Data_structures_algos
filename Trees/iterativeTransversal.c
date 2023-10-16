#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node *left;
    int data;
    struct Node *right;
}*root=NULL;

struct stack
{
    int top;
    int size;
    struct Node **S;
};

void Create(struct stack *st,int size)
{
    st->top=-1;
    st->size=size;
    st->S=(struct Node**)malloc(st->size*sizeof(struct Node*));
}
void push(struct stack*s,struct Node* x)
{
    if(s->top==s->size-1){
        printf("Stack Overflow\n");
    }else{
        s->top++;
        s->S[s->top]=x;
    }
}
struct Node* pop(struct stack*s)
{
    struct Node* x=NULL;
    if(s->top==-1){
        printf("Stack Undeflow\n");
    }else{
        x=s->S[s->top--];
    }
    return x;
}
int isEmpty(struct stack s)
{
    if(s.top==-1){
        return 1;
    }
    return 0;
}
void Preorder(struct Node*p)
{
    if(p)
    {
        printf("%d ",p->data);
        Preorder(p->left);
        Preorder(p->right);
    }
}
struct Node* newNode(int x)
{
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->left=NULL;
    t->right=NULL;
    return t;
}
void IPreorder(struct Node*p)
{
    struct stack s;
    Create(&s,10);
    while(p || !isEmpty(s))
    {
        if(p)
        {
           printf("%d ",p->data);
           push(&s,p);
           p=p->left;
        }
        else
        {
            p=pop(&s);
            p=p->right;

        }
    }
}

void IInorder(struct Node*p)
{
    struct stack s;
    Create(&s,10);
    while(p || !isEmpty(s))
    {
        if(p)
        {
           push(&s,p);
           p=p->left;
        }
        else
        {
            p=pop(&s);
            printf("%d ",p->data);
            p=p->right;

        }
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
    Preorder(root);
    printf("\n");
    // IPreorder(root);
    // printf("\n");
    // IInorder(root);
}