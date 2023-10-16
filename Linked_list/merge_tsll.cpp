//merging two sorted linked list into singel sorted linked list
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

Node* create(int *A,int len,struct Node*head){
    head=(Node*)malloc(sizeof(struct Node));
    head->data=A[0];
    struct Node*p=head;
    struct Node*q;
    head->next=NULL;
    for(int i=1;i<len;i++){
        q=(Node*)malloc(sizeof(struct Node));
        q->data=A[i];
        q->next=NULL;
        p->next=q;
        p=q;
    }
    return head;
}
void print(struct Node*p){
    while (p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
Node*concate_LL(struct Node*head1,struct Node*head2){
    struct Node*p=head1;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=head2;
    head2=NULL;
    return head1;
}
Node*merge_sll(struct Node*p,struct Node*q){
    struct Node*third,*last;
    if(p==NULL){
        return q;
    }
    if(q==NULL){
        return p;
    }
    if(p->data<q->data){
        third=last=p;
        p=p->next;
        third->next=NULL;
    }else{
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while(p && q)
    {
        if(p->data<q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p)last->next=p;
    if(q)last->next=q;
    return third;
}
int main(){
    int A[]={};
    int B[]={1,2,5,7};
    struct Node*l1=NULL,*l2=NULL;
    l1=create(A,sizeof(A)/sizeof(A[0]),l1);
    l2=create(B,sizeof(B)/sizeof(B[0]),l2);
    printf("First\n");
    print(l1);
    printf("\nSecond\n");
    print(l2);
    printf("\nSorted Merge\n");
    l1=merge_sll(l1,l2);
    print(l1);
    return 0;
}