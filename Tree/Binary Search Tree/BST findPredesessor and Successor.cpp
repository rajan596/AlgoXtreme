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

void findPreSucc(Node *head,int data,Node **pre,Node **succ) {
    if(head==NULL)
        return;
    if(head->data==data) {
        if(head->left!=NULL) {
            Node *temp=head->left;
            while(temp->right!=NULL)
                temp=temp->right;
            *pre=temp;
        }

        if(head->right!=NULL) {
            Node *temp=head->right;
            while(temp->left!=NULL)
                temp=temp->left;
            *succ=temp;
        }
    }
    else if(head->data < data) {
        *pre=head;
         findPreSucc(head->right,data,pre,succ);
    }
    else{
        *succ=head;
        findPreSucc(head->left,data,pre,succ);
    }
}

int main(){

    Node *head=NULL;

    head=insertKey(head,5);
    head=insertKey(head,15);
    head=insertKey(head,2);
    head=insertKey(head,20);
    head=insertKey(head,25);

    Node *pre=NULL,*succ=NULL;

    findPreSucc(head,25,&pre,&succ);

    if(pre!=NULL)
        printf("Predecessor is : %d\n",pre->data);
    else
        printf("Predecessor not available\n");

    if(succ!=NULL)
        printf("Successor is : %d\n",succ->data);
    else
        printf("Successor not available\n");

    return 0;
}
