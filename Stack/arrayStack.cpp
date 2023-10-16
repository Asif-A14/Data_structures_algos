//implementation of stack using array
#include<iostream>
#include<stdlib.h>
using namespace std;
struct stack{
    int top;
    int size;
    int *S;
};
void Create(struct stack *st)
{
    printf("Enter size of stack:");
    cin>>st->size;
    st->top=-1;
    st->S=(int*)malloc(st->size*sizeof(int));
}
int peek(struct stack st,int index){
    int x=-1;
    if(st.top-index+1<0)
        printf("Invalid Index \n");
    x=st.S[st.top-index+1];
    return x;
}
void push(struct stack*s,int x)
{
    if(s->top==s->size-1){
        printf("Stack Overflow\n");
    }else{
        s->top++;
        s->S[s->top]=x;
    }
}
int pop(struct stack*s){
    int x=-1;
    if(s->top==-1){
        printf("Stack Undeflow\n");
    }else{
        x=s->S[s->top--];
    }
    return x;
}
//stack is not modified hence call by value
void Display(struct stack st){
    for(int i=st.top;i>=0;i--)
        printf("%d ",st.S[i]);
    printf("\n");
}
int isEmpty(struct stack st){
    if(st.top==-1)
        return 1;
    else
        return 0;
}
int isFull(struct stack st){
    if(st.top==st.size-1)
        return 1;
    else
        return 0;
}
int main(){
    struct stack s;
    //Create(&s);
    s.size=5;
    s.top=-1;
    push(&s,10);
    push(&s,20);
    push(&s,30);
    push(&s,40);
    push(&s,50);
    Display(s);
    printf("%d\n",peek(s,2));
    pop(&s);
    Display(s);
    return 0;
}