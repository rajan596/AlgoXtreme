/* BST Inorder Successor */

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

Node *InorderSuccessor(Node *head,int data) {
    static Node *succ=NULL;

    if(head==NULL)
        return head;

    if(head->data==data) {
        Node *temp=head->right;
        if(temp!=NULL) {
            while(temp->left!=NULL)
                temp=temp->left;
            succ=temp;
        }
    }
    else if(head->data<data) {
        InorderSuccessor(head->right,data);
    }else {
        succ=head;
        InorderSuccessor(head->left,data);
    }

    return succ;
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

    Node *temp=InorderSuccessor(head,1);

    if(temp==NULL)
        printf("Successor is not in BST\n");
    else
        printf("Inorder Successor is : %d\n",temp->data);

    return 0;
}
