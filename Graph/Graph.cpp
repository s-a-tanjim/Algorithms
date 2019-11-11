#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#define MAXNODE 30
using namespace std;
class MyGraph
{
    int node,edge,*level;
    bool check[MAXNODE];
    vector<int> Graph[MAXNODE];
    public:
    int *startTime,*endTime,time;    //for dfs


    void setNode(int x){
        node=x;
    }
    int getNode()
    {
        return node;
    }
    int getEdge()
    {
        return edge;
    }
    void setEdge(int x){
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
    int * dfs(int start)
    {
        startTime=new int[MAXNODE];
        endTime=new int[MAXNODE];

        for(int i=0;i<MAXNODE;i++) check[i]=false;
        time=0;
        dfs_(start);
        return startTime;
    }
    void dfs_(int start)
    {
        time++;
        startTime[start]=time;
        check[start]=true;
        for(int i=0;i<Graph[start].size();i++)
        {
            if(!check[Graph[start][i]])
            {
                dfs_(Graph[start][i]);
            }
        }
        time++;
        endTime[start]=time;
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
        delete[] startTime;
        delete[] endTime;
    }
};

int main()
{
    int x,i,j,node,edge,a,b;
    MyGraph g;
    printf("Number of Node: ");
    scanf("%d",&node);
    printf("Number of Edge: ");
    scanf("%d",&edge);
    g.setEdge(edge);
    g.setNode(node);
    g.TakeAdjacencyList();

    cout<<"Press... \n1 for bfs.....\n";
    cout<<"2 for DFS.\n";
    int ans;
    while(1){
        cout<<">>";
        cin>>ans;
        if(ans==1)
        {

        }
        else if(ans==2)
        {
            cout<<"Start: ";
            cin>>a;

            int *x=g.dfs(a);
            cout<<"Starting Time: ";
            for(int i=0;i<g.getNode();i++)
            {
                cout<<x[i]<<"   ";
            }
            cout<<"\nEnding Time: ";

            for(int i=0;i<g.getNode();i++)
            {
                cout<<g.endTime[i]<<"   ";
            }
            cout<<"\n\n\n";
        }

    }
    return 0;
}
