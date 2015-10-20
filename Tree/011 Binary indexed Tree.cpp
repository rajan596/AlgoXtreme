/*   BINARY INDEXED TREE || FENWICK TREE
*    Given an array and 2 type of queries 1. update any element 2. find sum upto any index of an array  
*    BENIFITS :  complexity : O(logn) both update and findsum   and less code  
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

#define all(c) (c).begin(),(c).end()
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define vll vector<ll>
#define pb(a) push_back(a)

const ll mod=1e9+7;

// binary indexed tree stored in 1d array
ll BIT[10001]={0},n;  // BIT starts from 1 index

// update or add element at some index 
void update(ll index,ll value)
{
    ll i=index;

    while(i<=n)
    {
        BIT[i]+=value;

        i= i + (i& (-i));
    }
}

// find sum upto index (a1 + a2 + .. + ai)
ll findSum(ll index)
{
    ll i=index,sum=0;

    while(i>0)
    {
        sum+=BIT[i];

        i-=i&(-i);

    }

    return sum;
}

int main()
{
    ll i,j,k,a[100001]={0},l,r;

    cin>>n;

    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        update(i,a[i]);  //( index , value )
    }

    ll m;   // m queries
    cin>>m;

    while(m--)
    {
        ll q;
        cin>>q;

        if(q==1)  // update array
        {
            cin>>i>>k;
            update(i,k);
        }
        else    // print sum upto index n
        {
            cin>>r;

            cout<<findSum(r)<<endl;
        }
    }

    return 0;
}
