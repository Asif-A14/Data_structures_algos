#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
} * head = NULL;

struct Node* newNode(int x) {
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    return t;
}

void create(int len, int* A) {
    struct Node* last;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = head;
    last = head;
    for (int i = 1; i < len; i++) {
        struct Node* t = newNode(A[i]);
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void Display(struct Node* p) {
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
    printf("\n");
}

int flag = 0;

void RDisplay(struct Node* p) {
    if (p != head || flag == 0) {
        flag = 1;
        printf("%d ", p->data);
        RDisplay(p->next);
    }
    flag = 0;
}
int Delete(struct Node*p,int pos){
    int x;
    struct Node*q;
    if(pos==1){
        x=head->data;
        while(p->next!=head)
            p=p->next;
        q=head;
        p->next=q->next;
        head=q->next;
        free(q);
    }else{
        for(int i=1;i<pos-1;i++){
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        x=q->data;
        free(q);

    }
    return x;
}
void insert(int pos, int x) {
    struct Node* t = newNode(x);
    struct Node* p = head;
    if (pos == 0) {
        if (head == NULL) {
            head = t;
            head->next = head;
        } else {
            while (p->next != head) {
                p = p->next;
            }
            p->next = t;
            t->next = head;
            head = t;
        }
    } else {
        for (int i = 1; i < pos - 1; i++) {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

int main() {
    int A[] = {2,3,5,6, 7 };
    create(sizeof(A) / sizeof(A[0]), A);
    insert(0,1);
    insert(4,4);
    Delete(head,1);
    Delete(head,3);
    Display(head);
    return 0;
}
