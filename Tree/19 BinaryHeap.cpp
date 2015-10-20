/* MIN BINARY HEAP TREE
  1 based indexing
  If current node n
    * parent at   : n/2
    * left child  : 2*n
    * Right child : 2*n + 1
*/

#include<bits/stdc++.h>

using namespace std;

class BinaryHeap {
    int sz=0;                   // size of heap
    vector<int> heap;           // tree storage in an array

    public:
        BinaryHeap();
        void Insert(int key);  // O(log N)
        void Delete(int key);  // O(log N)
        int Search(int key);   // O(N)
        int MinValue();        // O(1)
        void Print();          // O(N)
        int Size();

        void Swap(int *x,int *y) {
            int temp=*x;
            *x=*y;
            *y=temp;
        }
};

BinaryHeap::BinaryHeap() {
    heap.push_back(INT_MIN);
}

void BinaryHeap::Print() {
    printf("HeapTree : ");
    for(int i=1;i<=sz;i++)
        printf("%d ",heap[i]);
    printf("\n");
}

int BinaryHeap::Size(){
    return sz;
}

int BinaryHeap::MinValue(){
    return heap[1];
}

/* Returns index of key if key is in Heap or returns -1 */
int BinaryHeap::Search(int key) {
    if(sz==0)
        return -1;

    /* BFS */
    queue<int> q;  /* Indexed queue */
    q.push(1);

    while(!q.empty()) {
        int i=q.front();
        q.pop();

        if(heap[i]==key)
            return i;

        if(2*i <= sz)
            q.push(2*i);
        if(2*i + 1 <=sz)
            q.push(2*i + 1);
    }

    if(q.empty())
        return -1;

}

void BinaryHeap::Insert(int key) {
    heap.push_back(key);
    sz=sz+1;
    int parent=sz/2;
    int child=sz;

    while(heap[parent] > heap[child]) {
        /* swap heap[parent] and heap[child]*/
        Swap(&heap[parent] , &heap[child]);
        child=parent;
        parent=parent/2;
    }
}

void BinaryHeap::Delete(int key) {
    int last_node=heap[sz];
    sz--;

    int index=Search(key);

    if(index==-1)
        return ;

    heap[index]=last_node;

    /* Maintain Heap Property */
    int parent,child;
    parent=index;

    vector<int> temp;
    while(2*parent <=sz) {
        if(2*parent <= sz && heap[2*parent] < heap[parent])
            temp.push_back(2*parent);
        if(2*parent + 1 <=sz && heap[2*parent + 1] < heap[parent])
            temp.push_back(2*parent + 1);

        if(temp.size()==1)
            child=temp[0];
        else
            child=(heap[temp[0]] > heap[ temp[1] ] ) ? temp[1] : temp[0] ;

        /* swap */
        Swap(&heap[parent] , &heap[child]);
        parent=child;

    }
}

int main() {
    BinaryHeap b;
    b.Insert(10);
    b.Print();
    b.Insert(20);
    b.Print();
    b.Insert(5);
    b.Print();
    b.Insert(1);
    b.Print();


    b.Delete(1);
    b.Print();
    b.Delete(20);
    b.Print();
    b.Delete(5);
    b.Print();
    b.Delete(10);
    b.Print();
    b.Delete(1);
    b.Print();
    return 0;
}
