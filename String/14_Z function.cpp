/*
Z-FUNCTION ::
Tutorial : http://e-maxx-eng.github.io/string/z-function.html
Que     : http://codeforces.com/contest/126/problem/B
Animation : http://www.utdallas.edu/~besp/demo/John2010/z-algorithm.htm
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll mod=1e9+7;

#define fileinput freopen("input.txt","r",stdin)
#define fileoutput freopen("output.txt","w",stdout)
#define T ll t ; cin>>t ; while(t--)

void z_function(char s[],ll z[]){
    ll l=0,r=0,i;
    ll n=strlen(s);
    z[0]=0;

    for(i=1;i<n;i++) {
        z[i]=0;
        if(i<=r) {
            z[i]=min(r-i+1,z[i-l]);
        }
        while(i+z[i]<n && s[z[i]]==s[i+z[i]])
            ++z[i];
        if(r < i+z[i]-1) {
            l=i;
            r=i+z[i]-1;
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    char s[1000005];
    cin>>s;

    ll l=strlen(s);
    ll z[l];
    z_function(s,z);

    for(ll i=0;i<l;i++){
        cout<<z[i]<<" ";
    }

    return 0;
}
