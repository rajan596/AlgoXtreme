/* Sample input ::
7 4
1 2
2 3
4 5
5 6
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll mod=1e9+7;

#define fileinput freopen("input.txt","r",stdin)
#define fileoutput freopen("output.txt","w",stdout)

void createSets(ll n,ll parent[],ll Size[]) {
    for(ll i=1;i<=n;i++) {
        parent[i]=i;
        Size[i]=1;
    }
}

ll findParent(ll x,ll parent[]) {
    if(parent[x]==x) return x;
    return findParent(parent[x],parent);
}

void mergeSets(ll a,ll b,ll parent[],ll Size[]) {
    ll x=findParent(a,parent);
    ll y=findParent(b,parent);

    if(x==y) return;

    if(Size[x]>=Size[y]) {
        parent[y]=x;
        Size[x]+=Size[y];
    }else {
        parent[x]=y;
        Size[y]+=Size[x];
    }
}

int main()
{

    ll  n,  // no. of nodes
        m,  // no. of connections
        i,j;

    scanf("%lld %lld",&n,&m);

    ll  parent[n+1], // stores parent of node
        Size[n+1];

    createSets(n,parent,Size);

    for(i=0;i<m;i++) {
        ll a,b;
        scanf("%lld %lld",&a,&b);
        mergeSets(a,b,parent,Size);
    }

    // print result
    ll sets=0;
    for(i=1;i<=n;i++) {
         if(parent[i]==i) {
            printf("Parent Node : %lld , Size : %lld\n",i,Size[i]);
            sets++;
         }
    }

    printf("Total Sets : %lld",sets);

    return 0;
}
