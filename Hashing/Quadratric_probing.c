#include<stdio.h>
#define SIZE 10

int hash(int key)
{
    return key%10;
}
int probe(int H[],int key)
{
    int index = hash(key);
    int i=0;
    while(H[(index+i*i)%SIZE]!=0)
        i++;
    return (index+i*i)%SIZE;
}
void Insert(int H[],int key)
{
    int i = hash(key);
    if(H[i]!=0)
        i=probe(H,key);
    H[i]=key;
}

int Search(int H[],int key){
    int index = hash(key);
    int i=0;
     while(H[(index+i*i)%SIZE]!=key)
        i++;
    return (index+i*i)%SIZE;
    
}

void Display(int A[],int n){
    for(int i=0;i<n;i++)
        printf("%d ",A[i]);
    printf("\n");
}
int main(){
    int H[10]={0};
    int A[]={24,45,23,16,25,34,55,35};
    for(int i=0;i<8;i++)
        Insert(H,A[i]);
    Display(H,10);
    printf("%d",Search(H,35));
}