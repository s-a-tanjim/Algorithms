/*
Prime related functions
1. isPrime()
2. sieve()
3. primeFactors()
4. NOD()
5. SNOD()
6. SOD()
7. eulerPhi()

*/

#include<math.h>
#include<vector>
using namespace std;

bool isPrime(int n)
{
    if(n<2) return false;

    int sq=sqrt((double)n);
    for(int i=2; i<=sq;i++)
        if(n%i==0)  return false;
    return true;
}

vector<int>prime;
bool check[10000005];   /// check[i] = 0 means prime, check[i] = 1 means not prime
int n=10000000;

void sieve()
{
    check[0]=check[1]=1;     // 1 for not prime
    for(int i=4;i<=n;i+=2) check[i]=1;  //Not prime
    prime.push_back(2);
    int sq=sqrt(n);
    for(int i=3;i<=sq;i+=2)
    {
        if(!check[i])   //if prime
        {
            for(long long j=(long long)i*i;j<=n;j+=2*i)
                check[j]=1;         //Multiplicity is not prime
        }
    }
    for(int i=3;i<=n;i+=2)
        if (!check[i])
            prime.push_back(i);
}

vector<int>prime_factors;
void primeFactors(int n)
{
    // int sq=sqrt((double)n);
    for(int i=0;i<prime.size() && prime[i] * prime[i]<=n;i++)
    {
        // if(check[n]==0) break;      //check N is prime or not
        if(n % prime[i]==0)
        {
            while(n % prime[i]==0)
            {
                n/=prime[i];
                prime_factors.push_back(prime[i]);
            }
            // sq=sqrt((double)n);
        }
    }
    if(n!=1)
    {
        prime_factors.push_back(n);
    }
}


int NOD(int n)  /// Number of Divisor
{
    int res=1;
    for(int i=0; i<prime.size() && prime[i] * prime[i]<=n ;i++)
    {
        if(n % prime[i]==0)
        {
            int Count=0;
            while(n % prime[i]==0)
            {
                Count++;
                n/=prime[i];
            }
            res*=(Count+1);
        }
    }
    if(n!=1)    //Remaining prime has power p^1. So multiply with 2
        res*=2;
    return res;
}

int SNOD(int n)     /// Sum of NOD
{
    int res=0;
    int sq=sqrt((double)n);
    for(int i=1;i<=sq;i++)
    {
        res+=(n/i)-i;
    }
    res*=2;
    res+=sq;
    return res;
}

int SOD(int n)      /// Sum of divisor
{
    int res=1;

    for(int i=0; i<prime.size() && (long long)prime[i]*prime[i]<=n;i++)
    {
        if(n%prime[i]==0)
        {
            int temp_sum=1;      //For p^0=1 Case
            int term=1;
            while(n%prime[i]==0)
            {
                n/=prime[i];
                term*=prime[i];
                temp_sum+=term;
            }
            res*=temp_sum;
        }
    }
    if(n!=1)
        res*=(n+1);     // Need to multiply (p^0+p^1)

    return res;
}

int eulerPhi(int n)
{
    int res=n;
    if(n==1) res=0;
    for (int i = 0; i < prime.size() && (long long)prime[i]*prime[i] <= n; i++)
    {
        if( n % prime[i] == 0 )
        {
            while( n % prime[i] == 0 )
            {
                n/= prime[i];
            }
            res /= prime[i];
            res *= prime[i] - 1;
        }
    }
    if ( n != 1 ) {
        res /= n;
        res *= n - 1;
    }
    return res;
}
