#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#define MAXNODE 15
using namespace std;
class MyGraph
{
    int node,edge,*level;
    vector<int> Graph[MAXNODE];
public:
    void SetNode(int x){
        node=x;
    }
    void SetEdge(int x){
        edge=x;
    }
    void TakeAdjacencyList()    //Bi-Directional Graph
    {
        int a,b;
        printf("Node A  :  Node B\n");
        for(int i=0;i<edge;i++){
            scanf("%d %d",&a,&b);
            Graph[a].push_back(b);
            Graph[b].push_back(a);
        }
    }
    int *bfs(int Start)
    {
        level=new int[MAXNODE];
        bool check[MAXNODE];
        for(int i=0;i<MAXNODE;i++) check[i]=false;
        queue<int>qq;
        qq.push(Start);
        check[Start]=true;
        level[Start]=0;
        int top,i;
        while(!qq.empty())
        {
            top=qq.front();
            qq.pop();
            for(i=0;i<Graph[top].size();i++){
                if(!check[Graph[top][i]]){
                    check[Graph[top][i]]=true;
                    qq.push(Graph[top][i]);
                    level[Graph[top][i]]=level[top]+1;
                }
            }
        }
        return level;
    }
    void GraphDisplay()
    {
        printf("Graph is:\n");
        for(int i=0;i<node;i++)
        {
            printf("\n%d ->  ",i);
            for(int j=0;j<Graph[i].size();j++)
            {
                printf("%d  ",Graph[i][j]);
            }
        }
        printf("\n\n");
    }

    ~MyGraph()
    {
        delete[] level;
    }
};

int main()
{
    int x,i,j,node,edge,a,b;
    MyGraph g;
    printf("Number of Node: ");
    scanf("%d",&node);
    vector<int>v[node];
    printf("Number of Edge: ");
    scanf("%d",&edge);
    g.SetEdge(edge);
    g.SetNode(node);
    g.TakeAdjacencyList();


    while(1){
        printf("Start: ");
        scanf("%d",&a);
        printf("End: ");
        scanf("%d",&b);
        if(a==-1) break;
        int *level=g.bfs(a);
        int dis=level[b];
        printf("Shortest Distance from %d to %d is:  %d\n",a,b,dis);
    }
    return 0;
}
