#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *left;
    int data;
    struct Node*right;
}*root=NULL;

struct Node*RInsert(struct Node*p,int key)
{
    if(p==NULL){
        struct Node*temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=key;
        temp->left = temp->right = NULL;
        return temp;
    }
    if(key < p->data)
        p->left = RInsert(p->left,key);
    else if(key > p->data)
        p->right = RInsert(p->right,key);
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

struct Node* Search(struct Node*p,int key)
{
    if(p){
        if(p->data > key){
            return Search(p->left,key);
        }else if(p->data < key){
            return Search(p->right,key);
        }else{
            return p;
        }
    }
    return NULL;
}

int Height(struct Node *p)
{
    int x,y;
    if(p){
        x = Height(p->left);
        y = Height(p->right);
        return x > y ? x+1 : y+1;
    }
    return 0;
}
struct Node*InSucc(struct Node*p){
    while(p && p->left){
        p=p->left;
    }
    return p;
}
struct Node*InPre(struct Node*p){
    while(p && p->right){
        p=p->right;
    }
    return p;
}
struct Node* Delete(struct Node*p , int key)
{
    struct Node *q;
    if(p==NULL){
        return NULL;
    }
    if(p->left == NULL && p->right == NULL){
        if(p == root)
            root = NULL;
        free(p);
        return NULL;
    }
    if(key < p->data){
        p->left = Delete(p->left, key);
    }else if(key > p->data){
        p->right = Delete(p->right, key);
    }else{
        if(Height(p->left) > Height(p->right)){
            q = InPre(p->left);
            p->data = q->data;
            p->left = Delete(p->left, q->data);
        }else{
            q = InSucc(p->right);
            p->data = q->data;
            p->right = Delete(p->right, q->data);
        }
    }
    return p;
}

int main(){
    root=RInsert(root,10);
    RInsert(root,50);
    RInsert(root,30);
    RInsert(root,40);
    RInsert(root,35);
    RInsert(root, 38);
    struct Node* tep = Delete(root, 30);
    printf("%d \n\n",tep->data);
    Inorder(root);
    printf("\n");
    struct Node*t=Search(root,38);
    if(t!=NULL){
        printf("Elment %d found",t->data);
    }else   
        printf("Element not found");
}