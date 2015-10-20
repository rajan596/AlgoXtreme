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

void inorder(Node *head) {
    if(head==NULL)
        return;

    inorder(head->left);
    printf("%d ",head->data);
    inorder(head->right);
}

Node* inorderSuccessor(Node *head) {
   Node *temp=head;

   while(temp->left!=NULL) {
            temp=temp->left;
   }
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

Node* deleteKey(Node *head,int data) {
    if(head==NULL)
        return head;

    if(head->data==data)  {
        if(head->left==NULL && head->right==NULL){           /* Case : 1 => no child*/
            free(head);
            return NULL;
        }
        else if(head->left==NULL && head->right!=NULL) {    /* Case : 2 => right child*/
            head=head->right;
        }
        else if(head->left!=NULL && head->right==NULL) {    /* Case : 3 => left child*/
            head=head->left;
        }
        else {                                              /* case : 4  => two childs*/
            Node *temp=inorderSuccessor(head->right);
            head->data=temp->data;
            head->right=deleteKey(head->right,temp->data);
        }

        return head;
    }

    if(head->data<data)
        head->right=deleteKey(head->right,data);
    else
        head->left=deleteKey(head->left,data);

    return head;
}

int main(){

    Node *head=NULL;

    head=insertKey(head,5);
    head=insertKey(head,15);
    head=insertKey(head,2);
    head=insertKey(head,20);
    head=insertKey(head,25);

    inorder(head);
    head=deleteKey(head,2);

    printf("\n");
    inorder(head);

    return 0;
}
