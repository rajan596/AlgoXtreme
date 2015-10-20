/* BST Deletion */

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

bool isBSTUtil(Node *head , int LowerLimit, int Upperlimit) {
    if(head==NULL)
        return 1;

    return (head->data > LowerLimit && head->data < Upperlimit) &&
            isBSTUtil(head->left,LowerLimit,head->data) &&
            isBSTUtil(head->right,head->data,Upperlimit);
}

bool isBST(Node *head) {
    if(isBSTUtil(head , INT_MIN , INT_MAX))
        return 1;
    else
        return 0;
}

int main(){

    Node *head=NULL;

    head=insertKey(head,5);
    head=insertKey(head,15);
    head=insertKey(head,2);
    head=insertKey(head,20);
    head=insertKey(head,25);

    if(isBST(head)) {
        printf("Yes ... This Binary Tree is BST");
    }
    else
        printf("Nope... This is not BST.....:-(");


    return 0;
}
