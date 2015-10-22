/*
 *  Print Common Nodes in Two BSTs
 *  In this method : Use iterative Inorder traversal using stacks
 *  Time complexity : O(n)
 *  Space Complexity : O(log h)
 */
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

void inorder(Node *head) {
    if(head==NULL)
        return;

    inorder(head->left);
    printf("%d ",head->data);
    inorder(head->right);
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

void printCommonNodesinBST(Node *head1,Node *head2) {

    stack<Node *> s1,s2;

    while(1) {
        /* Reach at smallest node in subtree having root head1 */
        if(head1) {
            s1.push(head1);
            head1=head1->left;
        }
        /* Reach at smallest node in subtree having root head2 */
        else if(head2) {
            s2.push(head2);
            head2=head2->left;
        }
        /* Now check for both the nodes in BSTs ( = , > , < ) */
        else if(!s1.empty() && !s2.empty()) {
            head1=s1.top();
            head2=s2.top();

            if(head1->data==head2->data) {
                printf(" %d ",head1->data);

                /* Move forward in both the BSTs */
                s1.pop();
                s2.pop();

                head1=head1->right;
                head2=head2->right;
            }
            /* Move forward in BST 2 */
            else if(head1->data > head2->data) {
                s2.pop();
                head2=head2->right;
            }
            /* move forward in BST 1 */
            else {
                s1.pop();
                head1=head1->right;
            }
        }
        /* Complete Tree traversal in any of the BST or in Both */
        else
            break;
    }
}

int main(){

    /* BST 1 */
    Node *head1=NULL;
    //head1=insertKey(head1,5);
    //head1=insertKey(head1,15);
    //head1=insertKey(head1,2);
    head1=insertKey(head1,20);
    //head1=insertKey(head1,55);

    printf("\nBST 1 : ");
    inorder(head1);

    /* BST 2 */
    Node *head2=NULL;
    //head2=insertKey(head2,5);
    //head2=insertKey(head2,15);
    //head2=insertKey(head2,2);
    head2=insertKey(head2,20);
    head2=insertKey(head2,25);

    printf("\nBST 2 : ");
    inorder(head2);

    printf("\nCommon Nodes : ");
    printCommonNodesinBST(head1,head2);

    return 0;
}
