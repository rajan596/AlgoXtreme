/*
* DFS (Depth first search) in graph theory
* 
* Reference : https://codeaccepted.wordpress.com/2014/04/08/depth-and-breadth-first-search/?blogsub=subscribed#subscribe-blog
*/
#include<stdio.h>
#include<conio.h>

int adjlist[101][101]={0},  // stores adjacent nodes
    done[101]={0},          // check if node is traversed ?
    degree[101]={0};        // degree of a node


void dfs(int pos)
{
    if(done[pos]==1)        // if node is encountered then return
        return;

    printf("%d\n",pos);
    done[pos]=1;
    for(int j=0;j<degree[pos];j++)
    {
        dfs(adjlist[pos][j]);
    }
}

int main()
{
    int n,m,i=0,a,b;

    scanf("%d %d",&n,&m);     //n : total no. of nodes  //m : total no. of edges

    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b); // a and b adjacent nodes

        adjlist[a][degree[a]]=b;
        degree[a]++;

        adjlist[b][degree[b]]=a;
        degree[b]++;

    }

    dfs(1);    // depth first search & starting from node (1)

    return 0;
}
