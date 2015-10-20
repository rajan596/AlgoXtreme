/*
 * Find all the prime Factors of a given no with exponant.
 * Input : 
 * 4             // (test cases)
 * 2 3 10 20     // n 
 * Output : 
 * 2 1          // 2=2^1
 * 3 1          // 3=3^1
 * 2 1 5 1      // 10=2^1 + 5^1 
 * 2 2 5 1      // 20=2^2 + 5^1 
 */

#include<iostream>
#include<conio.h>
#include<stdio.h>

using namespace std;

int prime_factor(long long int n)
{
    long long int m=n;
    int c=0,i;
    for(i=2;n!=1 && i<=m ;i++)
    {
        if(n%i==0)
        {
            c=0;
            while(n%i==0 && n!=1)
            {
                n=n/i;
                c++;
            }
            printf("%d %d\n",i,c);
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        long long int n;
        scanf("%lld",&n);

        prime_factor(n);


    }

    return 0;
}
