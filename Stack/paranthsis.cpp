//verify whether the given parenthesis is perfet or not using stackt.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct stack{
    int top;
    int size;
    char *S;
};

void push(struct stack*s,char x){
    if(s->top==s->size-1){
        printf("Stack Overflow\n");
    }else{
        s->top++;
        s->S[s->top]=x;
    }
}
char pop(struct stack*s){
    char x;
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
        printf("%c ",st.S[i]);
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
int isBalance(char *exp)
{
    struct stack s;
    s.size=strlen(exp);
    s.S=(char*)malloc(s.size*sizeof(char));
    s.top=-1;
    int m=0;
    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
        {
            push(&s,exp[i]);
        }
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
        {   if(isEmpty(s))
            {
                return 0;
            }
            char x = pop(&s);
            if(exp[i]==')' && x!='('){
                return 0;
            }else if(exp[i]=='}' && x!='{'){
                return 0;
            }else if(exp[i]==']' && x!='['){
                return 0;
            }
        }
    }
    if(isEmpty(s))
        return 1;
    return 0;
}
int main(){
    char s[]="{([{[({})]}])}[]";
    if(isBalance(s))
        printf("Balanced paranthesis");
    else
        printf("Unbalanced paranthesis");
    
    return 0;
}