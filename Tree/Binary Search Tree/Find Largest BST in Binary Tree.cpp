/* Find Largest BST in Binary Tree*/

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

class TreeInfo{
    public:
        bool isBST;
        int sz,mn,mx;

        TreeInfo() {
            isBST=1;
            sz=0;
            mn=INT_MAX;
            mx=INT_MIN;
        }
};

TreeInfo findLargestBSTUtil(Node *head) {
    TreeInfo LeftTree,RightTree,temp;

    if(head==NULL)      /* return sz=0 and BST=1 for leaf nodes */
        return temp;

    LeftTree=findLargestBSTUtil(head->left);
    RightTree=findLargestBSTUtil(head->right);

    /* if this root forms is part of any BST */
    if((head->data > LeftTree.mx) && (head->data < RightTree.mn) &&
       LeftTree.isBST && RightTree.isBST) {

       temp.isBST=1;
       temp.sz= 1 + LeftTree.sz + RightTree.sz;
       if(temp.sz==1) {
            temp.mn=head->data;
            temp.mx=head->data;
       }
       else {
            temp.mn=LeftTree.mn;
            temp.mx=RightTree.mx;
       }
    }
    else {
       temp.isBST=0;
       temp.sz=max(LeftTree.sz , RightTree.sz);
    }

    return temp;
}

int findLargestBST(Node *head) {
    TreeInfo tf=findLargestBSTUtil(head);
    return tf.sz;
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

    printf("Largest BST Size : %d\n",findLargestBST(head));

    Node *head2=NULL;

    head2=newNode(10);
    head2->left=newNode(50);
    head2->right=newNode(20);
    head2->left->left=newNode(25);
    head2->left->right=newNode(70);

    printf("Largest BST Size : %d\n",findLargestBST(head2));


    return 0;
}
