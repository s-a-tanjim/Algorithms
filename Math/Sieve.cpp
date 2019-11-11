#include<math.h>
#include<vector>

vector<int>prime;
bool check[10000005];///check[i] = 0 means prime, check[i] = 1 means not prime
int n=10000000;
void sieve()
{
    check[0]=check[1]=1;     // 1 for not prime
    int sq=sqrt(n);
    for(int i=4;i<=n;i+=2) check[i]=1;  //Not prime
    prime.push_back(2);
    for(int i=3;i<=sq;i+=2)
    {
        if(!check[i])   //if prime
        {
            for(long long j=(long long)i*i;j<=n;j+=2*i)
                check[j]=1;         //Multiplicity ( গুণিতক ) is not prime
        }
    }
    for(int i=3;i<=n;i+=2)
        if (!check[i])
            prime.push_back(i);
}
