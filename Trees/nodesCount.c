#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node *left;
    int data;
    struct Node *right;
}*root=NULL;

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

// int Count(struct Node*p)
// {
//     int x,y;
//     if(p){
//         x=Count(p->left);
//         y=Count(p->right);
//         return x+y+1;
//     }
//     return 0;
// }

// int degree2(struct Node*p)
// {
//     int x,y;
//     if(p){
//         x=degree2(p->left);
//         y=degree2(p->right);
//         if(p->left && p->right)
//             return x+y+1;
//         else
//             return x+y;
//     }
//     return 0;
// }
//sum of all nodes of trees
int Sum(struct Node*p)
{
    int x,y;
    if(p){
        x=Sum(p->left);
        y=Sum(p->right);
        return x+y+p->data;
    }
    return 0;
}

//height of the tree
int fun(struct Node*p)
{
    int x,y;
    if(p){
        x=fun(p->left);
        y=fun(p->right);
        if(x>y)
            return x+1;
        else
            return y+1;
    }
    return 0;
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
    root->right->right->left=newNode(8);
    Preorder(root);
    printf("\n%d",fun(root));
}