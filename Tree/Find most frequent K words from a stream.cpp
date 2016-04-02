#include<bits/stdc++.h>

using namespace std;

#define MAX_CHARS 26

class TrieNode{
    public:
        int frequency,indexMinHeap;
        bool isEnd;
        TrieNode *child[MAX_CHARS];

        TrieNode(){
            frequency=0;
            indexMinHeap=-1;
            isEnd=0;
            for(int i=0;i<MAX_CHARS;i++)
                child[i]=NULL;
        }
};

class MinHeapNode{
    public:
        int frequency;
        char *word;
        TrieNode *root; // pointer to corresponding Trie Node

        MinHeapNode(){
            frequency=0;
            word=NULL;
            root=NULL;
        }
};
class MinHeap{
    public:
        int capacity;
        int cnt;
        MinHeapNode *arr;

        MinHeap(int k){
            capacity=k;
            cnt=0;
            arr=new MinHeapNode[capacity];
        }

        void insertHeap(TrieNode *root, int indexMinHeap, char *word);
        void printHeap();
        void minHeapify(int idx);
        void buildHeap();
};

class Trie{
    public:
        TrieNode *TrieHead;

        Trie(){
            TrieHead=new TrieNode();
        }

        void insertWord(char *word,MinHeap *m);
        void insertWordutil(TrieNode *head,char *word,int index,int len,MinHeap *m);
};

void Trie::insertWord(char *word,MinHeap *m){
    insertWordutil(TrieHead,word,0,strlen(word),m);
}

void Trie::insertWordutil(TrieNode *head,char *word,int index,int len,MinHeap *m){

    // base cases
    if(word[index]=='\0'){
        //cout<<word<< " - " << head->frequency<<endl;
        head->frequency++;
        head->isEnd=1;
        m->insertHeap(head,head->indexMinHeap,word);
        return;
    }

    int idx=tolower(word[index])-'a';

    if(head->child[idx]==NULL){
        head->child[idx]=new TrieNode();
    }
    insertWordutil(head->child[idx],word,index+1,len,m);

}

void MinHeap::insertHeap(TrieNode *root,int indexMinHeap,char *word){
    // word is not present in Heap
    if(indexMinHeap==-1) {
        // heap is not full
        if(cnt < capacity) {
            // apend current node at the end of heap
            arr[cnt].frequency=1;
            arr[cnt].root=root;
            arr[cnt].word=new char[strlen(word)];
            strcpy(arr[cnt].word , word);
            root->indexMinHeap=cnt;
            //printf("Word inserted....%s\n",word);
            cnt++;
            buildHeap();
        }
        // heap is full
        else{
            if(arr[0].frequency < root->frequency){
                //printf("Replaced %s(%d) with %s(%d)...\n",arr[0].word,arr[0].frequency,word,root->frequency);
                arr[0].root->indexMinHeap=-1; // word removed from heap
                // copy new node to head
                arr[0].frequency=root->frequency;
                arr[0].root=root;
                delete [] arr[0].word;
                arr[0].word=new char[strlen(word)];
                strcpy(arr[0].word,word);

                root->indexMinHeap=0;
                minHeapify(0);
            }
        }
    }
    // word is present in heap
    else{
        //printf("Updated....%s(%d)\n",word,root->frequency);
        arr[indexMinHeap].frequency++;
        minHeapify(indexMinHeap);
    }
}

void MinHeap::minHeapify(int idx){
    int l=2*idx;
    int r=2*idx+1;
    int smallest=idx;

    if(l<cnt && arr[l].frequency < arr[smallest].frequency){
        smallest=l;
    }

    if(r<cnt && arr[smallest].frequency > arr[r].frequency){
        smallest=r;
    }

    if(smallest!=idx){
        // swap nodes ans change index pointer in corresponding Trie Nodes
        arr[idx].root->indexMinHeap=smallest;
        arr[smallest].root->indexMinHeap=idx;

        MinHeapNode temp=arr[idx];
        arr[idx]=arr[smallest];
        arr[smallest]=temp;

        minHeapify(smallest);
    }
}

void MinHeap::buildHeap(){
    int n=cnt-1;
    for(int i=(n-1)/2;i>=0;i--){
        minHeapify(i);
    }
}

void MinHeap::printHeap(){
    for(int i=0;i<cnt;i++){
        cout<< arr[i].word << " : " << arr[i].frequency <<endl;
    }
}

class Solution{
    public:
        MinHeap *m;
        Trie *t;

        Solution(int k){
            m=new MinHeap(k);
            t=new Trie();
        }

        void printMostFrequentKWords();
};

void Solution::printMostFrequentKWords(){
    FILE *fp=fopen("file101.txt","r");
    if(fp==NULL)
        return;

    char buffer[1024];
    while(fscanf(fp,"%s",buffer)!=EOF){
        t->insertWord(buffer,m);
        //cout<<buffer<<endl;
    }

    m->printHeap();
}

int main(){

    Solution *s=new Solution(9);
    s->printMostFrequentKWords();

    return 0;
}
