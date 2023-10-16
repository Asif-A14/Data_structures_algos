#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left,*right;
}*root=NULL;
struct Node* newNode(int t){
    struct Node*temp=malloc(sizeof(struct Node));
    temp->data=t;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

struct stack{
    struct Node **Q;
    int size;
    int top;
};
void create(struct stack *s,int size){
    s->Q=malloc(size*sizeof(struct Node*));
    s->size=size;
    s->top=-1;
}

void push(struct stack*s,struct Node *n){
    if(s->top==s->size-1){
        printf("Stack is full");
    }else{
        s->top++;
        s->Q[s->top]=n;
    }
}

struct Node* pop(struct stack *s){
    struct Node*t=NULL;
    if(s->top==-1)
        printf("Stack is empty");
    else{
        t=s->Q[s->top];
        s->top--;
    }
    return t;
}
void print(struct stack *s){
    for(int i=0;i<s->top+1;i++){
        printf("%d ",s->Q[i]->data);
    }
}
int isEmpty(struct stack s){
    if(s.top==-1){
        return 1;
    }
    return 0;
}
void  IPreorder(struct Node*p)
{
    struct stack s;
    create(&s,5);
    while(p || !isEmpty(s)){
        if(p){
            printf("%d ",p->data);
            push(&s,p);
            p=p->left;
        }else{
            p=pop(&s);
            p=p->right;
        }
    }
}

void  IInorder(struct Node*p)
{
    struct stack s;
    create(&s,5);
    while(p || !isEmpty(s)){
        if(p){
            push(&s,p);
            p=p->left;
        }else{
            p=pop(&s);
            printf("%d ",p->data);
            p=p->right;
        }
    }
}


int main(){
    root=(struct Node*)malloc(sizeof(struct Node));
    root->data=1;
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    IInorder(root);
}