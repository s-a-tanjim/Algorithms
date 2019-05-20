#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#define MAXNODE 20
using namespace std;

int graph[MAXNODE][MAXNODE];
int main()
{

    int i,x,a,b,node,edge;
    printf("Number of nodes: ");
    scanf("%d",&node);
    printf("Number of Edge: ");
    scanf("%d",&edge);
    printf("Node A : Node B\n");
    for(i=0;i<edge;i++)
    {
        scanf("%d %d",&a,&b);
        graph[a][b]=1;
        graph[b][a]=1;
    }
    /*for(i=0;i<node;i++)
    {
        for(int j=0;j<node;j++)
        {
            printf("%d  ",graph[i][j]);
        }
        printf("\n");
    }*/

        printf("Start: ");
        scanf("%d",&a);
        printf("End: ");
        scanf("%d",&b);
        queue<int>qq;
        qq.push(a);
        bool check[MAXNODE];
        for(i=0;i<MAXNODE;i++) check[i]=false;
        int level[MAXNODE];
        level[a]=0;
        check[a]=true;

        while(!qq.empty())
        {
            int x=qq.front();
            qq.pop();
            for(i=0;i<node;i++){
                if(graph[x][i]==1 && check[i]==false){
                    qq.push(i);
                    check[i]=true;
                    level[i]=level[x]+1;
                }
            }
        }
        printf("Distance from %d to %d is: %d\n",a,b,level[b]-level[a]);



    return 0;
}
