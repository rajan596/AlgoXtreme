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

//L0 - Ln - L1 - Ln-1 ----

node *SetList(node *head) {

    stack<node *> s;

    node *slow=head,*fast=head;

    // reach at halves of linked list
    while(fast!=NULL && fast->next!=NULL) {
        fast=fast->next->next;
        slow=slow->next;
    }

    // insert another half link list in stack
    while(slow!=NULL) {
        s.push(slow);
        slow=slow->next;
    }

    /* Now insert alternate node of stack in link list*/
    slow=head;
    while(!s.empty()) {
        node *temp=s.top();
        temp->next=slow->next;
        slow->next=temp;
        slow=slow->next->next;
        s.pop();
    }

    slow->next=NULL;

    return head;
}

int main(){
    node *head=NULL;
    append(&head,1);
    append(&head,2);
    append(&head,3);
    append(&head,4);
    append(&head,5);
    append(&head,6);

    // to check memory addresses before
    cout<<&head<<" - "<<&head->next<<endl;
    printf("LIST BEFORE: ");
    printList(head);
    printf("\n");

    SetList(head);
    printf("LIST AFTER : ");
    printList(head);
    printf("\n");
    // to check memory addresses before
    cout<<&head<<" - "<<&head->next<<endl;

    return 0;
}
