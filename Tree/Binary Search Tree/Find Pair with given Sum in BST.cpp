/* Given N : Find pair a , b such that a + b = N */

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

bool hasPairInBST(Node *head , int N) {
    stack<Node *> s1,s2;

    Node *head1=head;
    Node *head2=head;

    while(1) {
        /* Reach at smallest node in subtree having root head1 */
        if(head1) {
            s1.push(head1);
            head1=head1->left;
        }
        /* Reach at biggest node in subtree having root head2 */
        else if(head2) {
            s2.push(head2);
            head2=head2->right;
        }
        /* Now check for both the nodes in BSTs ( = , > , < ) */
        else if(!s1.empty() && !s2.empty()) {
            head1=s1.top();
            head2=s2.top();

            if(head1->data + head2->data == N) {
                if(head1==head2)
                    return 0;
                else {
                    printf("\nResult : %d + %d = %d\n",head1->data,head2->data,N);
                    return 1;
                }
            }
            /* Move backward head2 */
            else if(head1->data + head2->data > N) {
                s2.pop();
                head2=head2->left;
            }
            /* move forward head1 */
            else {
                s1.pop();
                head1=head1->right;
            }
        }
        /* If any of the head completed traversal */
        else
            break;
    }
    return 0;
}

int main(){

    Node *head=NULL;

    head=insertKey(head,20);
    head=insertKey(head,10);
    head=insertKey(head,30);
    head=insertKey(head,25);
    head=insertKey(head,40);
    head=insertKey(head,5);
    head=insertKey(head,15);
    head=insertKey(head,35);

    inorder(head);

    cout<<endl<<"Verdict : "<<hasPairInBST(head , 40) <<endl;

    return 0;
}
