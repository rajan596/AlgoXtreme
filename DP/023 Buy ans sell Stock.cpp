/*  Given stock prizes and you need to find max profit from 1 transaction
 *
 *  Exa : 100 , 80 , 120 , 130 , 70 , 60 , 100 , 125
 */

#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define print(a) cout<<a
#define T ll t; cin>>t ; while(t--)

int findMaximumProfit(int a[] , int n) {

    int MIN=INT_MAX;
    int benifit , max_benifit=INT_MIN;

    for(int i=0;i<n;i++) {
        MIN = min(MIN , a[i]);
        benifit=a[i] - MIN;
        max_benifit=max(benifit , max_benifit);

    }

    return max_benifit;
}

int main() {

    int a[]={100,80,120,130,70,60,100,125};

    int ans=findMaximumProfit(a, sizeof(a)/sizeof(a[0]));

    printf("Ans : %d\n",ans);

    return 0;
}
