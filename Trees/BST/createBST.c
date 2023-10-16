#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node*left;
    int data;
    struct Node*right;
}*root=NULL;

void Insert(int key)
{
    struct Node *t, *tail, *p;
    tail=NULL;
    t=root;
    if(root == NULL)
    {
        p = (struct Node*)malloc(sizeof(struct Node));
        p->data = key;
        p->right = p->left = NULL;
        root = p;
        return; 
    }
    while(t)
    {
        tail=t;
        if(t->data == key)
            return;
        else if(t->data < key){
            t = t->right;
        }else{
            t = t->left;
        }
    }
    p = (struct Node*)malloc(sizeof(struct Node));
    p->data = key;
    p->right = p->left = NULL;
    if(key < tail->data)
        tail->left = p;
    else
        tail->right = p;

}

struct Node* Search(int key)
{
    struct Node *t;
    t=root;
    while(t)
    {
        if(key == t->data)
            return t;
        else if( key < t->data )
            t = t->left;
        else
            t = t->right;
    }
    printf("Element NOT found!!!");
    return NULL;
}

struct Node* RInsert(int key,struct Node*p)
{
    struct Node *t;
    if(p == NULL){
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = key;
        t->right = t->left = NULL;
        return t;
    }
    if( key < p->data )
        p->left = RInsert(key,p->left);
    else if( key > p->data )
        p->right = RInsert(key,p->right);
    return p;
}
void InOrder(struct Node *p)
{
    if(p){
        InOrder(p->left);
        printf("%d ",p->data);
        InOrder(p->right);
    }
}

int main(){
    Insert(4);
    Insert(2);
    Insert(3);
    Insert(1);
    Insert(6);
    Insert(7);
    Insert(5);
    root=RInsert(8,root);
    InOrder(root);
    printf("\n");
    ;
    return 0;
}