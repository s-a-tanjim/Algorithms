#include<stdio.h>
#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

vector<int>prime;
bool check[10000005];
int n=10000000;
void sieve()
{
    check[0]=check[1]=1;     // 1 for not prime
    int sq=sqrt(n);
    for(int i=4;i<=n;i+=2) check[i]=1;  //Not prime
    for(int i=3;i<=sq;i+=2)
    {
        if(check[i]==0)   //if prime
        {
            for(int j=i*i;j<=n;j+=i)
                check[j]=1;         //Multiplicity ( গুণিতক ) is not prime
         }
    }
    prime.push_back(2);
    for(int i=3;i<n;i+=2)
        if(!check[i]) prime.push_back(i);
}
