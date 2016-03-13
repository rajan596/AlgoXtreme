/*
Tries:
*/
#include<bits/stdc++.h>

using namespace std;

class TrieNode{
    public:
    int prefix, // indicates no. of words with given prefix
        value,
        isLeafNode;  //

    TrieNode *child[26];

    TrieNode(){
        value=0;
        prefix=0;
        isLeafNode=0;

        for(int i=0;i<26;i++)
            this->child[i]=NULL;
    }
};

class Tries{
    public:
        int cnt;
        TrieNode *root;

        void insertKey(string s);
        bool deleteKey(string s);
        bool deleteKeyHelper(TrieNode *head,string s,int level);
        int searchKey(string s);
        void printKeys();
        void printKeysHelper(TrieNode *head,string s);

        Tries(){
            cnt=0;
            this->root=new TrieNode();
        }
};

/*
    Print all the keys in given Tries
*/
void Tries::printKeysHelper(TrieNode *head,string s) {
    if(head->isLeafNode){
        cout<<s<<endl;
    }
    for(int i=0;i<26;i++) {
        if(head->child[i]) {
            char c='a'+i;
            printKeysHelper(head->child[i],s+c);
        }
    }
}

void Tries::printKeys() {
    printKeysHelper(root,"");
}

// iterative method
void Tries::insertKey(string s){
    int len=s.length();
    TrieNode *temp=root;

    for(int i=0;i<len;i++){
        int index=s[i]-'a';
        if(!temp->child[index]) {
            temp->child[index]=new TrieNode();
        }
        temp=temp->child[index];
        temp->prefix++;
    }
    temp->isLeafNode=1;
    cout<<"Key added : "<<s<<endl;
}

int Tries::searchKey(string s){
    int len=s.length();
    TrieNode *temp=root;

    for(int i=0;i<len;i++){
        int index=s[i]-'a';
        if(temp->child[index]) {
            temp=temp->child[index];
        }
        else {
            return 0;
        }
    }

    if(temp->isLeafNode){
        return true;
    }
    return false;
}

bool Tries::deleteKeyHelper(TrieNode *head,string s,int level) {

    if(s.length()==level) {
        head->isLeafNode=0;
        return true;
    }

    int index=s[level]-'a';
    TrieNode *t=head->child[index];
    if(t) {
        if(!deleteKeyHelper(t,s,level+1))
            return false;

        if(t->prefix==1) {
            t->prefix=0;
            free(head->child[index]);
            head->child[index]=NULL;
        }else {
            t->prefix--;
        }
        return true;
    }
    return false;
}

bool Tries::deleteKey(string s) {
    return deleteKeyHelper(root,s,0);
}

int main(){

    Tries *t=new Tries();

    t->insertKey("hello");
    t->insertKey("hell");
    t->insertKey("world");
    t->insertKey("hey");
    t->insertKey("work");

    cout<<t->deleteKey("hello")<<endl;

    t->printKeys();

    return 0;
}
