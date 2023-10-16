#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node*left;
    int data;
    int height;
    struct Node*right;
}*root=NULL;

int NodeHeight(struct Node*p)
{
    int hl,hr;
    hl = p && p->left? p->left->height:0;
    hr = p && p->right? p->right->height:0;
    return hl > hr? hl+1 : hr+1;
}
int BalanceFactor(struct Node*p)
{
    int hl,hr;
    hl = p && p->left? p->left->height:0;
    hr = p && p->right? p->right->height:0;
    return hl - hr;
}
struct Node* LLrotation(struct Node*p)
{
    struct Node*pl = p->left;
    struct Node*plr = pl->right;
    pl->right = p;
    p->left = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(p==root)
        root = pl;
    return pl;
}
struct Node* LRrotation(struct Node*p)
{
    struct Node*pl = p->left;
    struct Node*plr = pl->right;
    pl->right = plr->left;
    p->left = plr->right;
    plr->left = pl;
    plr->right = p;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    plr->height = NodeHeight(plr);

    if(p==root)
        root = plr;
    return plr;
}
struct Node * RRrotation(struct Node *p)
{
    struct Node*pr = p->right;
    struct Node*prr = pr->right;
    pr->left = p;
    p->right = prr;
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if(p==root)
        root = pr;
    return pr;
}
struct Node * RLrotation(struct Node *p)
{
    return NULL;
}

struct Node* Insert(struct Node*p,int key){

    if(p==NULL){
       struct Node *t = (struct Node*)malloc(sizeof(struct Node));
        t->data = key;
        t->height = 1;
        t->right = t->left = NULL;
        return t;
    }
    if(p->data < key)
        p->right = Insert(p->right, key);
    else if(p->data > key)
        p->left = Insert(p->left, key);

    p->height = NodeHeight(p);

    if(BalanceFactor(p) == 2 && BalanceFactor(p->left)==1)
        return LLrotation(p);
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->left)==-1)
        return LRrotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->left)== -1)
        return RRrotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->left)==1)
        return RLrotation(p);
    return p;
}
void Inorder(struct Node*p)
{
    if(p)
    {
        Inorder(p->left);
        printf("%d ",p->data);
        Inorder(p->right);
    }
}

int main(){
    root=Insert(root,50);
    Insert(root,10);
    Insert(root,20);
    Inorder(root);
    return 0;
}