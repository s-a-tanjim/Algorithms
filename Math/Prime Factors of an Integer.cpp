#include<iostream>
#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;

vector<int> primeFactors;
void PrimeFactor(int n)
{
    primeFactors.clear();
    int sq=sqrt(n);
    while(n%2==0)
    {
        primeFactors.push_back(2);
        n/= 2;
    }
    //Only Odd will remain
    for(int i=3; i<=sq; i+=2)
    {
        while(n%i==0)           //Here "i" will always be prime
        {
            primeFactors.push_back(i);
            n/= i;
        }
    }
    if(n>1) primeFactors.push_back(n);      //Only Prime will be left
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        PrimeFactor(n);
        cout<<"1  ";
        for(int i=0;i<primeFactors.size();i++)
            cout<<primeFactors[i]<<"   ";
        cout<<"\n";
    }
    return 0;
}


