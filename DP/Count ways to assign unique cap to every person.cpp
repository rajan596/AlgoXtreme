/*
http://www.geeksforgeeks.org/bitmasking-and-dynamic-programming-set-1-count-ways-to-assign-unique-cap-to-every-person/

Sample Input :
3
3 5 100 1
1 2
2 5 100

Sample Output :
4
*/

#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define print(a) cout<<a
#define T ll t; cin>>t ; while(t--)
#define fin freopen("input.txt","r",stdin)
#define fout freopen("op.txt","w",stdout)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define debug(s,n) cout<<">> "<<s<<" : "<<n<<endl
#define pf(n) cout<<n<<endl;

ll totalCaps=100;
ll n;
vector<ll> capList[101];
ll dp[102][1<<20];  // [cap , mask]
ll allmask;
ll mod=1e9+7;

ll solve(ll mask, ll capID) {

    if(mask==allmask) {
        dp[capID][mask]=0;
        return 1;
    }

    if(capID>totalCaps) {
        return 0;
    }

    if(dp[capID][mask]!=-1)
        return dp[capID][mask];

    ll ways=0;

    /* If this cap is not included */
    ways+=solve(mask , capID + 1);

    /* If this cap is included */

    for(ll i=0;i<capList[capID].size() ; i++) {
        ll person=capList[capID][i];

        if(mask & 1<< (person-1)) {
            continue;
        }
        else {
            ways+=solve(mask | 1<< (person-1) , capID+1);
            ways%=mod;
        }
    }

    dp[capID][mask]=ways;
    return ways;
}

int main(){
    fin;
    cin>>n;

    for(ll i=1;i<=n;i++) {
        ll nos;
        cin>>nos;

        for(ll j=0;j<nos;j++) {
            ll cap;
            cin>>cap;

            capList[cap].push_back(i);
        }
    }

    for(ll i=0;i<=100;i++) {
        for(ll j=0;j< (1<<20) ; j++) {
            dp[i][j]=-1;
        }
    }

    allmask=(1<<n)-1;
    cout<<solve(0,1)<<endl;

    return 0;
}
