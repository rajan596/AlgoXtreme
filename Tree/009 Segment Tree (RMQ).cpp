/*                              *
*       RANGE MAXIMUM QUERY     *
*       SEGMENT TREE            *
*
* QUE : Given an array -- find max element from given range l and r (m queries)
*
*/

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<cstring>
#include<stdlib.h>
#include<map>
#include<algorithm>
#include<climits>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<list>

typedef long long int ll;

using namespace std;

// segment tree initialization
void initialize(ll node,ll b,ll e,ll a[],ll M[])
{
    if(b==e)
        M[node]=a[b];   // leaf nodes

    else
    {
        initialize(2*node,b,(b+e)/2,a,M);
        initialize(2*node+1,(b+e)/2 + 1,e,a,M);

        if(M[2*node]>=M[2*node+1])
        {
            M[node]=M[2*node];
        }
        else
        {
            M[node]=M[2*node+1];
        }
    }
}

// segment tree query
ll query(ll node,ll b,ll e,ll a[],ll M[],ll l,ll r)
{
    ll p1,p2;

    if(l>e || r<b)
        return -1;

    if(b>=l && e<=r)
        return M[node];

    p1=query(2*node,b,(b+e)/2,a,M,l,r);
    p2=query(2*node+1,(b+e)/2 + 1,e,a,M,l,r);

    if(p1==-1)
        return p2;
    if(p2==-1)
        return p1;
    if(p1>=p2)
        return p1;
    else
        return p2;
}

int main()
{
    ll n,a[100001],i,j,m,M[10000];
    scanf("%lld",&n);    // n element

    for(i=0;i<n;i++)
        scanf("%lld",&a[i]);

    scanf("%lld",&m);   // m queries

    // segment tree implemented using array  node=1  lb=0 up=1
    initialize(1,0,n-1,a,M);    // parameters (node, lower bound , upper bound , array , segment tree array )

    while(m--)
    {
        ll l,r,ans;
        scanf("%lld %lld",&l,&r);

        ans=query(1,0,n-1,a,M,l,r);  // (node,b,e,a,M,l,r)
        printf("%lld\n",ans);
    }

    return 0;
}
