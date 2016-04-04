#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define fin freopen("i1.txt","r",stdin)
#define fout freopen("o1.txt","w",stdout)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define pf(n) cout<<n<<endl;
#define pb(x) push_back(x)

ll findCubicRoot(ll x){
    ll l,r,mid,ans;
    l=1;
    r=x;
    ans=1;

    while(l<=r) {
        mid=(l+r)/2;
        if(pow(mid,3)==x)
            return mid;
        else if(pow(mid,3)<x){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return ans;
}

int main(){

    cout<<findCubicRoot(63)<<endl;

    return 0;
}
