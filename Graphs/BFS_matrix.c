#include<stdio.h>
#include"Queue.h"
void BFS(int A[][7],int start)
{
    int visited[7]={0};
    printf("%d",start);
    visited[start]=1;
    enqueue(start);
    int i,j;
    while(!isEmpty()){
        i=dequeue();
        for(j=1;j<7;j++){
            if(A[i][j]==1 && !visited[j]){
                printf("->%d",j);
                visited[j]=1;
                enqueue(j);
            }
        }
    }
}

void DFS(int A[][7],int v){
    static int visited[7]={0};
    if(!visited[v]){
        printf("->%d",v);
        visited[v]=1;
        for(int j=1;j<7;j++){
             if(A[v][j]==1 && !visited[j])
                DFS(A,j);
        }
    }
}



int main(){
    int A[7][7]={{0,0,0,0,0,0,0},
                {0,0,1,1,0,0,0},
                {0,1,0,0,1,0,0},
                {0,1,0,0,1,0,0},
                {0,0,1,1,0,1,1},
                {0,0,0,0,1,0,0},
                {0,0,0,0,1,0,0}};
    
    BFS(A,1);
    printf("\n");
    DFS(A,2);
    return 0;
}