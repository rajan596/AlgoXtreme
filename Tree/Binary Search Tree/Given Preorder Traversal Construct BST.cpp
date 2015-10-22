/*
 *  Construct BST from given Pre Order Array
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

void preorder(Node *head) {
    if(head==NULL)
        return;

    printf("%d ",head->data);
    preorder(head->left);
    preorder(head->right);
}

Node *constructBSTUtil(int pre[], int n, int mn,int mx) {
    static int index=0;   /* indicates current index in pre Array */

    /* Base cases */
    if(index >=n || (pre[index] < mn && pre[index]> mx))
        return NULL;

    Node *head=newNode(pre[index]);
    index++;

    head->left=constructBSTUtil(pre, n , mn, head->data);
    head->right=constructBSTUtil(pre, n , head->data , mx);

    return head;
}

Node *constructBSTfromPreOrder(int pre[] , int n) {
    return constructBSTUtil(pre , n , INT_MIN , INT_MAX);
}

int main(){

    /* Case # 1 */
    Node *head1=NULL;
    int pre1[]={15, 5, 3, 12, 10, 6, 7, 13, 16, 20, 18, 23};
    int n1=sizeof(pre1)/sizeof(pre1[0]);

    head1=constructBSTfromPreOrder(pre1,n1);
    preorder(head1);

    return 0;
}
