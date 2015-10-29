#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll mod=1e9+7;

#define fin freopen("input.txt","r",stdin)
#define fout freopen("output.txt","w",stdout)

int countIslands(int mat[100][100] , int n,int m) {
    int islands=0,i,j,k;
    bool counted[100][100]={0};

    /* adjacent 4 vertices */
    int x[]={0, 1 ,0, 1, 1};
    int y[]={0, -1,1, 0, 1};

    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            /* If any island is adjacent to current island mark it counted */
            if(mat[i][j]==1) {
                /* If current island is not counted it means it is new in our list */
                if(!counted[i][j]) {
                    islands++;
                    printf("New island : %d %d\n",i,j);
                }

                /*Mark 4 adjacent islands*/
                for(k=0;k<5;k++){
                    int X=i + x[k];
                    int Y=j + y[k];
                    if(mat[X][Y]==1) {
                        counted[X][Y]=1;
                    }
                }

            }
        }
    }

    return islands;
}

int main()
{
    fin;
    int n,  // no. of columns
        m,  // no. of rows
        i,j,a;
    int mat[100][100]={0};  // 1 based indexing

    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            scanf("%d",&mat[i][j]);
        }
    }

    int ans=countIslands(mat,n,m);
    printf("Total islands are : %d\n",ans);

    return 0;
}
