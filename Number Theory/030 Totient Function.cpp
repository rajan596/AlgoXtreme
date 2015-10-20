#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define print(a) cout<<a
#define T ll t; cin>>t ; while(t--)
#define fin freopen("input.txt","r",stdin)
#define fout freopen("op.txt","w",stdout)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define debug(s,n) cout<<">> "<<s<<" : "<<n<<endl
#define pf(n) cout<<n<<endl
#define in(n) cin>>n

long long int phi(long long int n) {
    long long int result=n;

    for(ll i=2;i*i<=n;i++) {
        if(n%i==0) {
            while(n%i==0)
                n=n/i;
            result-=result/i;
        }
    }
    if(n>1)
        result-=result/n;

    return result;
}

int main(){

    pf(phi(37));

    return 0;
}
