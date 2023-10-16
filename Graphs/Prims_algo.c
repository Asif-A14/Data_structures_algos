#include<stdio.h>
#define I 2400
        //   0 1 2 3 4 5 6 7
int cost[8][8]={{I, I, I, I, I, I, I, I},
            {I, I, 25, I, I, I, 5, I},
            {I, 25, I, 12, I, I, I, 10},
            {I, I, 12, I, 8, I, I, I},
            {I, I, I, 8, I, 16, I, 14},
            {I, I, I, I, 16, I, 20, 18},
            {I, 5, I, I, I, 20, I, I},
            {I, I, 10, I, 14, 18, I, I}};
int near[8]={I,I,I,I,I,I,I,I};

int t[2][6];

void printPrimMST(){
    printf("Minimum Spanning Tree edges\n");
    int sum=0;
    for(int i=0;i<6;i++){
        int c = cost[t[0][i]][t[1][i]];
        printf("[%d]----[%d] cost:%d\n",t[0][i],t[1][i],c);
        sum+=c;
    }
    printf("Total cost of MST: %d",sum);

}


int main(){
    int i,j,k,n,min,u,v;
    n=8;
    min=I;
    for(i=1;i<n;i++)
        for(j=i;j<n;j++){
            if(cost[i][j]<min){
                min=cost[i][j];
                u=i;
                v=j;
            }
        }
    printf("-----%d \n",v);
    t[0][0]=u;
    t[1][0]=v;
    near[u]=near[v]=0;
    for(i=1;i<n;i++){
        if(near[i]!=0){
            if(cost[i][u]<cost[i][v])
                near[i]=u;
            else 
                near[i]=v;
        }
    }

    for(i=1;i<n-2;i++){
        min=I;
        for(j=1;j<n;j++){
            if(near[j]!=0 && cost[j][near[j]] < min){
                min = cost[j][near[j]];
                k=j;
            }
        }
        t[0][i]=k;
        t[1][i]=near[k];
        near[k]=0;
        for(j=1;j<n;j++){
        if(near[j]!=0 && cost[j][k]<cost[j][near[j]])
            near[j]=k;
        }
    }
    printPrimMST();
    return 0;
}