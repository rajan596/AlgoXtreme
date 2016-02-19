/*
Rabin Karp Sub STring Matching Algorithm
Rolling Hash Function ::

new_hash=((old_hash-s[old])/p)+(pow(p,m-1)*s[new]);
*/

#include<bits/stdc++.h>

using namespace std;

class RabinKarp
{
        long long mod=1e18+7;
        long long p=101;

    public:
        int findPattern(string text,string pattern);
        long long calculateHash(string text,int length);
        long long reCalculateHash(string text,int l,int r,long long oldHash);
        long long binpow(long long a,long long b);
};

long long RabinKarp::binpow(long long a,long long b){
    if(b==0)
        return a%mod;
    long long ans=1;
    while(b>0) {
        if(b&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b=b/2;
    }
    return ans%mod;
}

long long RabinKarp::calculateHash(string text,int length){
    long long H=0;
    long long POWER=1;

    for(int i=0;i<length;i++) {
        H=(H%mod+(POWER*text[i])%mod)%mod;
        POWER=(POWER*p)%mod;
    }
    return H%mod;
}

// Hash of text[l,..,r] from oldHash
long long RabinKarp::reCalculateHash(string text,int l,int r,long long oldHash){
    oldHash=(oldHash-text[l-1])%mod;
    oldHash=(oldHash/p)%mod;
    oldHash=(oldHash%mod + (binpow(p,r-l)%mod*text[r]%mod)%mod)%mod;
    return oldHash%mod;
}

int RabinKarp::findPattern(string text,string pattern){
    int n=text.length();
    int m=pattern.length();

    if(m>n)
        return -1;

    long long hashPattern=calculateHash(pattern,m);
    long long hashText=calculateHash(text,m);

    for(int i=0;i+m<=n;i++){
        if(hashPattern==hashText && text.substr(i,m)==pattern){
            return i;
        }
        if(i+m<n){
            hashText=reCalculateHash(text,i+1,i+m,hashText);
        }
    }
    return -1;
}

int main(){
    RabinKarp r;
    cout<<r.findPattern("HelloHowAreYou","Are")<<endl;
    cout<<r.findPattern("HelloHowAreYou","lloHow")<<endl;
}
