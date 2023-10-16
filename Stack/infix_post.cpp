#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct stack
{
    int top;
    char S[20];
};
void push(struct stack*s,char x)
{
    if(s->top==19){
        printf("Stack Overflow\n");
    }else{
        s->top++;
        s->S[s->top]=x;
    }
}
char pop(struct stack*s)
{
    char x;
    if(s->top==-1){
        printf("Stack Undeflow\n");
    }else{
        x=s->S[s->top--];
    }
    return x;
}
//stack is not modified hence call by value
void Display(struct stack st)
{
    for(int i=st.top;i>=0;i--)
        printf("%c ",st.S[i]);
    printf("\n");
}
int isEmpty(struct stack st)
{
    if(st.top==-1)
        return 1;
    else
        return 0;
}
int isOperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/')
        return 0;
    else
        return 1;
}
int prec(char x)
{
    if(x=='+' || x=='-')
        return 1;
    else if(x=='*' || x=='/')
        return 2;
    return 0;
}
char *InToPost(char *infix)
{
    struct stack s;
    s.top=-1;
    //push(&s,'$');
    int i=0,j=0;
    int len=strlen(infix);
    char *postfix = (char*)malloc((len+1)*sizeof(char));
    while(infix[i]!='\0'){
        if(isOperand(infix[i]))
            postfix[j++]=infix[i++];
        else
        {
            if(prec(infix[i])>prec(s.S[s.top]))
                push(&s,infix[i++]);
            else{
                postfix[j++]=pop(&s);
            }
        }
    }
    while(!isEmpty(s))
    {
        postfix[j++]=pop(&s);
    }
    postfix[j]='\0';
    return postfix;
}
int main(){
    char infix[] ="a+b*c-d/e";
    printf("Infix Expression:\t%s",infix);
    char *postfix = InToPost(infix);
    printf("\nPostfix Expression:\t%s",postfix);
    return 0;
}