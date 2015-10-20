/* BST K'th Smallest Element */

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

/* Simple in order  traversal with exacltly visiting K nodes */
Node *KthSmallestNode(Node *head,int k) {
    static Node *ans=NULL;      /* Global node for this function */
    static int visitedNodes=0;

    if(head==NULL)
        return NULL;

    KthSmallestNode(head->left,k);
    visitedNodes++;
    if(visitedNodes==k) {
        ans=head;
    }
    KthSmallestNode(head->right,k);

    return ans;
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

    Node *temp=KthSmallestNode(head,5);

    if(temp==NULL)
        printf("Not found .....!!!\n");
    else
        printf("Kth element is : %d\n",temp->data);

    return 0;
}
