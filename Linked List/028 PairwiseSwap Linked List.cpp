#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define print(a) cout<<a
#define T ll t; cin>>t ; while(t--)
#define fin freopen("input.txt","r",stdin)
#define fout freopen("op.txt","w",stdout)

typedef struct node{
    int data;
    struct node *next;
}node;

node* Node(int data){
    node *newNode=(node *)malloc(sizeof(node));
    newNode->data=data;
    newNode->next=NULL;
}

void printList(node *n) {
    while(n!=NULL){
        printf("%d ",n->data);
        n=n->next;
    }
}

void append(node **head,int data) {
    node *newNode=Node(data);
    if(*head==NULL){
        *head=newNode;
        return;
    }

    node *temp=*head;
    while(temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next=newNode;
}

node *pairwiseSwap(node **head) {

    if((*head)==NULL || (*head)->next==NULL)
        return *head;

    node *root=pairwiseSwap(&((*head)->next->next));

    node *temp=(*head)->next;
    (*head)->next=root;
    temp->next=(*head);
    (*head)=temp;

    return *head;
}

int main(){
    node *head=NULL;
    append(&head,1);
    append(&head,2);
    append(&head,3);
    append(&head,4);
    append(&head,5);
    append(&head,6);

    printList(head);
    printf("\n");
    head=pairwiseSwap(&head);
    printList(head);
    printf("\n");

    return 0;
}
