#include<stdio.h>
#include<conio.h>

int adjlist[101][101]={0},  // stores adjacent nodes
    done[101]={0},          // check if node is traversed ?
    degree[101]={0};        // degree of a node


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

    // breadth first search
    int q[101]={0},f=0,r=0;  // q : queue ; f : front ; r : rear
    int pos=0;

    q[r++]=1;              // starting with node 1
    done[1]=1;             // if node is pushed in queue then done[]=1

    while(r!=f)
    {
        pos=q[f++];        // pop node from queue
        printf("%d\n",pos);


        for(int j=0;j<degree[pos];j++)
        {
            if(!done[adjlist[pos][j]])
            {
                q[r++]=adjlist[pos][j]; // push adjacent nodes
                done[adjlist[pos][j]]=1;
            }
        }
    }

    return 0;
}
