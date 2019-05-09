//Undirected Graph..

#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>   //For Pair
#include <queue>

//#define DISPLAY
#define MAXNODE 50
using namespace std;

//const int MAX = 1e4 + 5;
typedef pair<long long, int> PII;
bool check[MAXNODE];
vector <PII> Graph[MAXNODE];

long long prim(int node)
{
    priority_queue<PII, vector<PII>, greater<PII> > qq;
    long long minimumCost = 0;
    PII p;
    qq.push(make_pair(0, node));    //Initial Weight is 0
    while(!qq.empty())
    {
        // Select the edge with minimum weight
        p = qq.top();
        qq.pop();
        node = p.second;
        // Checking for cycle
        if(check[node])
            continue;
        minimumCost += p.first;
        check[node] = true;
        for(int i = 0;i < Graph[node].size();++i)
        {
            if(!check[Graph[node][i].second])
                qq.push(Graph[node][i]);
        }
    }
    return minimumCost;
}

int main()
{
    int node, edge, x, y;
    long long weight, minimumCost;

    //freopen("input.txt","r",stdin);

    printf("Number of Node: ");
    scanf("%d",&node);
    printf("\nNumber of Edge: ");
    scanf("%d",&edge);
    printf("\nNode A  :  Node B  :  Weight\n");
    for(int i = 0;i < edge;i++)
    {
        cin >> x >> y >> weight;
        Graph[x].push_back(make_pair(weight, y));
        Graph[y].push_back(make_pair(weight, x));
    }

    #ifdef DISPLAY
    for(int i=0;i<=node;i++)
    {
        cout<<i<<" ->  ";
        for(int j=0;j<Graph[i].size();j++)
        {
            cout<<Graph[i][j].second<<"("<<Graph[i][j].first<<")  ";
        }
        cout<<"\n";
    }
    #endif // DISPLAY


    cout<<"\nStarting Node: ";
    cin>>x;
    minimumCost = prim(x);
    cout <<"\nMinimum Cost is: "<< minimumCost << endl;
    return 0;
}

/*
Input Format for text file:
4
5
1 2 20
1 3 30
1 4 33
2 3 35
2 4 17
1
*/
