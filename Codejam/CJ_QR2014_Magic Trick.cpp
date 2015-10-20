//     GOOGLE CODEJAM QUALIFICATION ROUND 2014 => MAGIC TRICK 

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<cstring>
#include<stdlib.h>
#include<vector>
#include<stack>
#include<map>
#include<algorithm>
#include<climits>
#include<set>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

int main()
{
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);


    int t,T;
    cin>>t;
    T=t;

    while(t--)
    {
        int a[5][5],b[5][5],ans1,ans2,i,j;
        set<int> s;

        cin>>ans1;
        for(i=1;i<=4;i++)
            for(j=1;j<=4;j++)
                cin>>a[i][j];

        cin>>ans2;
        for(i=1;i<=4;i++)
            for(j=1;j<=4;j++)
                cin>>b[i][j];

        for(i=1;i<=4;i++)
        {
            for(j=1;j<=4;j++)
            {
                if(a[ans1][i]==b[ans2][j])
                    s.insert(a[ans1][i]);
            }
        }

        int l=0;
        if(!s.empty())
            l=s.size();


        cout<<"Case #"<<T-t<<": ";
        if(l==0)
            cout<<"Volunteer cheated!"<<endl;
        else if(l!=1)
            cout<<"Bad magician!"<<endl;
        else
        {
            set<int>::iterator it=s.begin();
            cout<<*it<<endl;
        }

    }

    return 0;
}
