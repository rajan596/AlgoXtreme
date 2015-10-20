/* TOPOLOGICAL SORTING */

#include<bits/stdc++.h>

using namespace std;

stack<int> result;
bool visited[100]={0};

void topSortUtil(vector<int> graph[] , int node ) {
    printf("node : %d\n",node);
    int x;
    for(int i=0;i<graph[node].size() ; i++) {
        x=graph[node][i];
        if(!visited[x]) {
            topSortUtil(graph , graph[node][i] );
        }
    }

    visited[node]=1;
    result.push(node);
}

void topologicalSort(vector< int >graph[] , int n) {

    for(int i=1;i<=n;i++) {
        if(!visited[i]) {
            topSortUtil(graph , i );
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

    while(!result.empty()) {
        a=result.top();
        result.pop();
        printf("%d\n",a);
    }

    return 0;
}
