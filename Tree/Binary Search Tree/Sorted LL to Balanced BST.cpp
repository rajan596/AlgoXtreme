/*
 * Sorted Linked List to Balanced BST
 */
#include<bits/stdc++.h>

using namespace std;

/* For BST */
typedef struct NodeBST{
    struct NodeBST *left=NULL;
    struct NodeBST *right=NULL;
    int data;
}NodeBST;

/* for Linked List */
typedef struct NodeLL{
    int data;
    struct NodeLL *next;
}NodeLL;

/* For BST */
NodeBST* newNodeBST(int data) {
    NodeBST *temp=new NodeBST;
    temp->left=NULL;
    temp->right=NULL;
    temp->data=data;

    return temp;
}

/* for LL */
NodeLL* newNodeLL(int data){
    NodeLL *newNode=new NodeLL;
    newNode->data=data;
    newNode->next=NULL;
}

void preorder(NodeBST *head) {
    if(head==NULL)
        return;
    printf("%d ",head->data);
    preorder(head->left);
    preorder(head->right);
}

void append(NodeLL **head,int data) {
    NodeLL *newNode=newNodeLL(data);
    if(*head==NULL){
        *head=newNode;
        return;
    }

    NodeLL *temp=*head;
    while(temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next=newNode;
}

int len(NodeLL *head){
    if(head==NULL) return 0;
    return len(head->next) + 1;
}

NodeBST* SortedLLtoBalancedBSTUtil(NodeLL **head,int n){

    NodeBST *root=newNodeBST(0);
    /* Base Case */
    if(n<=0)
        return NULL;
    /* Left Sub Tree */
    root->left=SortedLLtoBalancedBSTUtil(head,n/2);

    /* Set root */
    root->data=(*head)->data;
    (*head)=(*head)->next;

    /* Right Sub Tree */
    root->right=SortedLLtoBalancedBSTUtil(head,n-n/2-1);

    return root;
}

NodeBST *SortedLLtoBalancedBST(NodeLL *head) {
    int n=len(head);
    return SortedLLtoBalancedBSTUtil(&head,n);
}

int main(){

    NodeLL *head=NULL;
    append(&head,10);
    append(&head,20);
    append(&head,30);
    append(&head,40);
    append(&head,50);
    append(&head,60);

    NodeBST *head1=SortedLLtoBalancedBST(head);

    preorder(head1);

    return 0;
}
