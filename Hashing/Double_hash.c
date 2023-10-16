#include<stdio.h>
# define SIZE 10
int hash1(int key)
{
    return key%10;
}
int hash2(int key)
{
    return 7-(key%7);
}
int doublehash(int H[], int key)
{
    int index = hash1(key);
    int i=1;
    int t = hash2(key);
    while(H[(index+i*t)%SIZE]!=0)
        i++;
    return (index+i*t)%SIZE;
}
void Insert(int H[],int key)
{
    int i = hash1(key);
    if(H[i]!=0)
        i=doublehash(H,key);
    H[i]=key;
}

int Search(int H[],int key){
    int index = hash1(key);
    int i=1;
    int t = hash2(key);
    while(H[(index+i*t)%SIZE]!=key)
        i++;
    return (index+i*t)%SIZE;
    
}


void Display(int A[],int n){
    for(int i=0;i<n;i++)
        printf("%d ",A[i]);
    printf("\n");
}
int main(){
    int H[10]={0};
    int A[]={5,25,15,35,95};
    for(int i=0;i<8;i++)
        Insert(H,A[i]);
    Display(H,10);
    printf("%d",Search(H,35));
}