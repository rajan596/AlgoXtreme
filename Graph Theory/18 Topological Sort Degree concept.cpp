/*
* TOPOLOGICAL SORTING
*  O ( |V| + |E|) Complexity
*
* Reference : https://courses.cs.washington.edu/courses/cse373/02au/lectures/lecture19l.pdf
*/

#include<bits/stdc++.h>

using namespace std;

queue<int> q;
int degree[100]={0};   /* In degree of vertices or node */
vector<int> result;

void topologicalSort(vector<int> graph[] , int n) {
    /* Find in degree of each vertices */
    for(int i=1;i<=n;i++) {
        for(int j=0;j<graph[i].size() ; j++) {
            int x=graph[i][j];
            degree[x]++;
        }
    }

    /* Enqueue 0 degree vertices */
    for(int i=1;i<=n;i++) {
        if(degree[i]==0) {
            q.push(i);
        }
    }

    /* If there is no vertices having degree 0 then graph has cycle*/
    if(q.empty()){
        printf("Graph has cycle ... Sort isnot possible\n");
        return;
    }

    while(!q.empty()) {
        int x=q.front();
        q.pop();
        result.push_back(x);

        /* As x node is deleted from graph decrement adjacent node's degree by 1 */
        for(int i=0;i<graph[x].size() ; i++) {
            int y=graph[x][i];
            degree[y]--;
            if(degree[y]==0)
                q.push(y);
        }
    }
}

int main() {

    freopen("input.txt","r",stdin);
    /* n=no.of vertices*/
    int n,edges,a,b;
    scanf("%d %d",&n,&edges);
    vector<int> graph[n+1];  /* Adjacency matrix of graph */

    for(int i=0;i<edges ; i++) {
        scanf("%d %d",&a,&b);
        graph[a].push_back(b);
    }

    topologicalSort(graph , n);

    for(int i=0;i<result.size() ; i++) {
        printf("%d ",result[i]);
    }

    return 0;
}
