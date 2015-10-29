/*
SAMPLE INPUT : 
5
1 2 1 1 5

SAMPLE OUTPUT : 
Maximum length : 3
1 | 5 | 

*/

#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define print(a) cout<<a
#define T ll t; cin>>t ; while(t--)
#define fin freopen("input.txt","r",stdin)

int main(){
        ll n;
        scanf("%lld",&n);

        ll a[n+1];
        ll dp[n+1];

        for(ll i=0;i<n;i++) {
            scanf("%lld",&a[i]);
            dp[i]=1;
        }

        for(ll i=0;i<n;i++) {
            for(ll j=0;j<i;j++) {
                if(a[j] < a[i])
                    dp[i]=max(dp[i],dp[j] + 1);
            }
        }

        ll l=0,r,mx=-1;

        for(ll i=0;i<n;i++) {
            if(dp[i] > mx){
                mx=dp[i];
                r=i;
            }
        }

        printf("Maximum length : %lld\n",mx);

        /* printing sequence */

        stack<ll> s;
        s.push(a[r]);
        mx=a[r];
        for(ll i=r-1 ; i>=0 ; i--) {

            if(a[i] < mx) {
                mx=a[i];
                s.push(mx);
            }

        }

        while(!s.empty()) {
            printf("%lld | ",s.top());
            s.pop();
        }


    return 0;
}
