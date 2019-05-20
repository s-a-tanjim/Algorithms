int gcd(int a,int b)        //Recursive way
{
    ///take care of negative number
    if(b==0) return a;
    return gcd(b,a%b);
}

int _gcd(int a,int b)       //iterative way
{
    ///take care of negative number
    int temp;
    while(b)
    {
        temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}

int lcm(int a,int b)
{
    /// take care of stack-overflow cases
    return (a/gcd(a,b))*b;
}
