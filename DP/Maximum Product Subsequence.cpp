#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define print(a) cout<<a
#define T ll t; cin>>t ; while(t--)
#define fin freopen("input.txt","r",stdin)
#define fout freopen("op.txt","w",stdout)

ll maximumProductSubArray(ll a[] ,ll n) {
     ll mn=a[0],
        mx=a[0],
        ans=a[0];

     for(ll i=1;i<n;i++) {
        ll temp_mx=mx;
        ll temp_mn=mn;

        mx=max(max(temp_mx*a[i] , temp_mn*a[i]) , a[i]);
        mn=min(min(temp_mx*a[i] , temp_mn*a[i]) , a[i]);

        ans=max(mx,ans);
    }

    return ans;
}

int main(){

    ll n;
    cin>>n;

    ll ans=0;
    ll a[n+1];

    for(ll i=0;i<n;i++)
        cin>>a[i];

    ans=maximumProductSubArray(a,n);
    cout<<ans<<endl;

    return 0;
}
