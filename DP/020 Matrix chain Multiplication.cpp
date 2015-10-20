/*
matrix chain Multiplication
  1           2        3
[2 , 3]    [3 , 4]  [4 , 5]
 p0 p1      p1 p2    p2 p3
*/

#include<bits/stdc++.h>

using namespace std;

void tracePath(int path[][100] , int i ,int j , int n) {
    int k=path[i][j];


    if(i==j)
        printf("A%d", i );
    else
    {
        printf("(");
        tracePath(path , i , k , n);
        printf(" * ");
        tracePath(path , k+1 , j , n);
        printf(")");
    }
}

int main() {

    /* Input as p0,p1,p2,...., pn */
    int n;
    printf("Enter no. of Matrix : ");
    scanf("%d",&n);

    int p[n+1];

    for(int i=0;i<=n;i++)
        scanf("%d",&p[i]);

    /* Matrix no. starts from 1 to n */
    int dp[100][100];

    /* to trace the path :: stores k where [i,k]* [k+1] is min. */
    int path[100][100];

    /* for length = 1 => cost=0 */
    for(int i=0;i<=n;i++) {
        dp[i][i]=0;
    }

    /* solution */
    /* solve sub problems starting length from  1 to n */
    for(int len=2;len<=n;++len) {
        /* solve dp [ i , j] */
        for(int i=1 ; i + len -1 <= n ; ++i) {
                int j= i + len -1 ;
                dp[i][j]=INT_MAX;
                int ii=i,jj=j;

                /* fine all possible min. values [ i to k ] [ k+1 to j] */
                for(int k=i;k<=j;k++) {
                    /* [i , k ] [ k+1 , j]  */
                    int x= dp[i][k] + dp[k+1][j] + p[i-1] * p[k] * p[j];

                    if(x < dp[i][j]) {
                        dp[i][j]=x;
                        path[i][j]=k;
                    }
                }
        }

    }

    printf("Minimum cost is : %d\n",dp[1][n]);

    for(int i=1;i<=n;i++)  {
        for(int j=1;j<=n;j++) {
            printf("%d\t\t",path[i][j]);
        } printf("\n");
    }

    tracePath(path , 1 , n , n);

    return 0;
}
