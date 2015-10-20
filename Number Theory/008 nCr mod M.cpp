#include<iostream>
using namespace std;
#include<vector>
 
/*
    C(n,r) mod m
    Using recurrence:
    C(i,k) = C(i-1,k-1) + C(i-1,k)
    Time Complexity: O(n*r)
    Space Complexity: O(n*r)
*/
 
long long C(int n, int r, int MOD)
{
    vector< vector<long long> > C(n+1,vector<long long> (r+1,0));
 
    for (int i=0; i<=n; i++)
    {
        for (int k=0; k<=r && k<=i; k++)
            if (k==0 || k==i)
                C[i][k] = 1;
            else
                C[i][k] = (C[i-1][k-1] + C[i-1][k])%MOD;
    }
    return C[n][r];
}
int main()
{
    int n,r,m;
    while (~scanf("%d%d%d",&n,&r,&m))
    {
        printf("%lld\n",C(n, r, m));
    }
}

/* ########################### ANOTHER EFFICIENT METHOD  ################################## */
#include<bits/stdc++.h>
using namespace std;

#define ll long long int

const ll mod=1e9+7;

ll f[100005];
ll invFact[100005];

ll binpow(ll a,ll b,ll m) {
    ll ans=1;

    while(b>0) {
        if(b&1){
            ans=(ans*a)%m;
        }

        b=b>>1;
        a=(a*a)%m;
    }

    return ans;
}

void factorial() {
    f[0]=1;
    for(ll i=1;i<=100000;i++)
        f[i]=(f[i-1]*i)%mod;
}

void invFactorial() {
    invFact[100000]=binpow(f[100000],mod-2,mod);

    for(ll i=1e5;i>=1;i--) {
        invFact[i-1]=(i*invFact[i])%mod;
    }
}

ll nCr(ll n,ll k) {
    ll ans=f[n];
    ans=(ans*invFact[k])%mod;
    ans=(ans*invFact[n-k])%mod;
    return ans;
}

int main(){

    factorial();
    invFactorial();

    ll n,k;
    
    cout<<"nCr is : "<<nCr(n,k)<<endl;

    return 0;
}
