#include<bits/stdc++.h>

int SOD(int n)
{
    int sum=1, sq=sqrt(n);
    for(int i=2 ; i<=sq ; i++)
    {
        int current_sum = 1, term = 1;
        while( n%i == 0 )
        {
            n/= i;
            term*= i;
            current_sum+= term;
        }
        sum*= current_sum;
    }
    if( n>1 )   //For prime or other case
        sum*=(n+1);

    return sum;
}



int main()
{
    int n;

    std::cout<<SOD(12)<<"\n";
    return 0;
}
