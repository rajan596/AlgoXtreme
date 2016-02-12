/*
Reference : http://www.geeksforgeeks.org/strongly-connected-components/

PART : 1
    1. Use DFS on Given Graph and fill the stack S in last visit node first(bottom in stack) order

PART : 2
    2. Transpose Graph GT
    3. Defill Stack S and use DFS to print Components
    4. Keep Track of visited nodes
*/

#include<bits/stdc++.h>

using namespace std;

class Graph {
    int V; // no. of vertices
    list<int> *adj;

    public:
        Graph(int V);
        void addEdge(int a,int b);  // edge from a to b
        void printSCC();
        Graph getTranspose();
        void fillOrder(int i, bool visited[] , stack<int> &s);
        void DFSUtil(int node , bool visited[]);
};

Graph::Graph(int V) {
    this->V=V;
    adj=new list<int>[V];
}

void Graph::addEdge(int a,int b) {
    adj[a].push_back(b);
}

void Graph::fillOrder(int i, bool visited[] , stack<int> &s) {

    visited[i]=1;

    list<int>::iterator it;
    for(it=adj[i].begin() ; it!=adj[i].end() ; ++it ) {
        if(!visited[*it]) {
            fillOrder(*it , visited , s);
        }
    }

    s.push(i);
}

void Graph::DFSUtil(int node, bool visited[]) {

    visited[node]=1;
    cout<< node << " ";

    list<int>::iterator it;

    for(it=adj[node].begin() ; it!=adj[node].end() ; ++it) {
        if(!visited[ *it ])
            DFSUtil( *it , visited);
    }
}

Graph Graph::getTranspose() {

    Graph gr(V);

    for(int i=0;i<V;i++) {
        list<int>::iterator it;

        for(it=adj[i].begin() ; it!=adj[i].end() ; ++it ) {
            gr.addEdge(*it,i);
        }
    }

    return gr;

}

void Graph::printSCC() {

    bool *visited=new bool[V];
    stack<int> s;

    /* PART : 1 */
    for(int i=0;i<V;i++) {
        visited[i]=0;
    }

    for(int i=0;i<V;i++) {
        if(!visited[i])
            fillOrder(i,visited,s);
    }

    /* PART : 2 */
    Graph gr=getTranspose();

    for(int i=0; i<V; ++i) {
        visited[i]=0;
    }

    int cnt=0;
    while(!s.empty()) {
        int node=s.top();
        s.pop();
        if(!visited[node]) {
            printf("\nComponents : ");
            gr.DFSUtil(node , visited);
            cnt++;
        }
    }

    printf("\nTotal components : %d \n",cnt);

}

int main() {
    Graph g(5);

    g.addEdge(1,0);
    g.addEdge(0,2);
    g.addEdge(2,1);
    g.addEdge(0,3);
    g.addEdge(3,4);
    g.printSCC();

    return 0;
}
