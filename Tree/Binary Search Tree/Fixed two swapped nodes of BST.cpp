/* Two nodes are swapped in BST correct it */

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

void correctBSTUtil(Node *head,Node **first,Node **last) {
    static Node *pre=NULL;

    if(head==NULL)
        return;

    correctBSTUtil(head->left,first,last);

    /* Found faulty pair like ( 40 30 ) in ( 10 40 30 20 50 ) */
    if( pre!=NULL && pre->data > head->data) {
        if(*first==NULL) {   /* found first pair */
            *first=pre;
            *last=head;     /* If there is only  1 wrong pair then last=head*/
        }else {             /* found second pair */
            *last=head;
        }
    }
    pre=head;
    correctBSTUtil(head->right,first,last);
}

Node *correctBST(Node *head) {
    Node *first=NULL,*last=NULL;

    correctBSTUtil(head,&first,&last);

    int temp=first->data;
    first->data=last->data;
    last->data=temp;

    return head;
}

int main(){

    Node *head1=NULL;

    head1=newNode(70);
    head1->left=newNode(20);
    head1->right=newNode(50);
    head1->left->left=newNode(10);
    head1->left->right=newNode(30);
    head1->right->left=newNode(60);
    head1->right->right=newNode(80);

    printf("BST Before >>");
    inorder(head1);
    head1=correctBST(head1);

    printf("\nBST After  >>");
    inorder(head1);


    return 0;
}
