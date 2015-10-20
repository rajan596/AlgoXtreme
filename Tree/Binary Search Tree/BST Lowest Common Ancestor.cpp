/* BST Lowest common Ancestor */

#include<bits/stdc++.h>

using namespace std;

typedef struct Node{
    struct Node *left=NULL;
    struct Node *right=NULL;
    int data;
}Node;

Node* newNode(int data) {
    Node *temp=new Node;
    temp->left=NULL;
    temp->right=NULL;
    temp->data=data;

    return temp;
}

/* To avoid double pointer we are just setting head's left and right pointer
   and returning head pointer */
Node* insertKey(Node *head,int data) {
    if(head==NULL) {
        return newNode(data);
    }
    if(head->data<data)
        head->right=insertKey(head->right,data);
    else
        head->left=insertKey(head->left,data);

    return head;
}

Node *LCA(Node *head,int data1,int data2) {
    if(head==NULL)
        return head;

    if(head->data==data1 || head->data==data2)
        return head;

    if(head->data < data1 && head->data < data2)
        return LCA(head->right,data1,data2);

    if(head->data > data1 && head->data > data2)
        return LCA(head->left,data1,data2);

    Node *left=LCA(head->left,data1,data2);
    Node *right=LCA(head->right,data1,data2);

    if(left==NULL)
        return right;
    else if(right==NULL)
        return left;
    else{
        return head;
    }

}

int main(){

    Node *head=NULL;

    head=insertKey(head,5);
    head=insertKey(head,15);
    head=insertKey(head,2);
    head=insertKey(head,20);
    head=insertKey(head,25);
    head=insertKey(head,1);
    head=insertKey(head,4);

    Node *lca=LCA(head,2,4);

    printf("Lowest Common Ancestor is : %d\n",lca->data);

    return 0;
}
