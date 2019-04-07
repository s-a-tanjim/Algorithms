// graph of divisions with distance
#include<iostream>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<vector>
#include<utility>
#define MAX_NODE 8
using namespace std;


int main()
{
    int i,j, node,edge;
    vector<string> citiesName;
    typedef pair<int, int> PII;
    vector < PII > graphCost[MAX_NODE];

    cout<<"Number of city: ";
    cin>>node;
    cout<<"Enter city name: "<<endl;
    for(i=0;i<node;i++)
    {
        cout<<">> ";
        string x;
        cin>>x;
        citiesName.push_back(x);
        cout<<endl;
    }
    //for(i=0;i<node;i++) cout<<citiesName[i]<<endl;
    cout<<endl<<endl<<endl;

    cout<<"Number of Edges: ";
    cin>>edge;


    int st,en,cost;
    string city1,city2;
    PII x;
    for(i=0;i<edge;i++)
    {
        cout<<"City1: ";
        cin>>city1;
        cout<<"City2: ";
        cin>>city2;
        cout<<"Cost: ";
        cin>>cost;
        for(st=0;citiesName[st]!=city1;st++);
        for(en=0;citiesName[en]!=city2;en++);
        x.first=en;
        x.second=cost;
        graphCost[st].push_back(x);
        x.first=st;
        graphCost[en].push_back(x);
        cout<<endl<<endl;
    }
    system("cls");
    for(i=0;i<node;i++)
    {
        int x=graphCost[i].size();
        if(x) cout<<citiesName[i]<<" -> ";
        for(j=0;j<x;j++)
        {
            if(j) cout<<" , ";
            cout<<citiesName[graphCost[i][j].first]<<" ("<<graphCost[i][j].second<<") ";
        }
        cout<<endl<<endl;
    }

}
