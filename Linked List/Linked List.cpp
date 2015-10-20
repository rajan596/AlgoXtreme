#include<bits/stdc++.h>

using namespace std;

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

void frontInsertion(node **head,int data) {
    node *newNode=Node(data);
    newNode->next=(*head);
    *head=newNode;
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

void sortedInsertion(node **head,int data){
    node *temp=*head;

    if(temp==NULL){
        frontInsertion(head,data);
        return;
    }
    if(temp->data >= data){
        frontInsertion(head,data);
        return;
    }

    while(temp->next!=NULL && temp->next->data < data  )
        temp=temp->next;

    node *newNode=Node(data);
    newNode->next=temp->next;
    temp->next=newNode;
}

void deleteNode(node **head,int key){
    node *temp=*head;
    if((*head)->data == key && *head!=NULL){
        (*head)=(*head)->next;
        free(temp);
        return;
    }

    while(temp->next==NULL && temp->next->data !=key){
        temp=temp->next;
    }

    temp->next=temp->next->next;
    free(temp);
}

int len(node *head){
    if(head==NULL) return 0;
    return len(head->next) + 1;
}

bool searchNode(node *head,int data){
    if(head==NULL) return false;
    else if(head->data == data) return true;
    else return searchNode(head->next,data);
}

node* getNthNode(node *head,int n){
    if(head==NULL || n-1==0) return head;
    return getNthNode(head->next,n-1);
}

/* Nth node from tail */
int GetNode(Node *head,int positionFromTail)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
    
   struct Node *p1=head,*p2=head;
    
   while(positionFromTail--) {
       p2=p2->next;
   }
   
    while(p2->next!=NULL){
        p2=p2->next;
        p1=p1->next;
    }
    
    return p1->data;
}

void reverseList(node **head){
    node *current,*pre,*nxt;
    current=*head;
    pre=NULL;
    nxt=current->next;

    while(current->next!=NULL){
        current->next=pre;
        pre=current;
        current=nxt;
        nxt=nxt->next;
    }
    current->next=pre;
    *head=current;
}

void recursiveReverseList(node **head){
    node *first,*rest;

    if(*head==NULL || (*head)->next==NULL) return;
    first=*head;
    rest=first->next;

    recursiveReverseList(&rest);
    first->next->next=first;
    first->next=NULL;
    *head=rest;
}

void detectLoop(node *head){
    node *fast=head;
    node *slow=head;

    while(fast!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            printf("\nLoop detected\n");
            return;
        }
    }
    printf("\nNo Loop Detected\n");
}

bool isPalindrome(node *head){
    stack<node *> s;
    node *temp=head;

    while(temp!=NULL){
        s.push(temp);
        temp=temp->next;
    }

    temp=head;

    while(temp!=NULL){
        node *temp2;
        temp2=s.top();
        s.pop();

        if(temp!=temp2) return false;
    }
    return true;
}

/* merge 2 lists and create another list */
void mergeList(node *head1,node *head2,node **head3){
    node *temp1=head1;
    node *temp2=head2;

    while(temp1!=NULL || temp2!=NULL) {
        if(temp2==NULL || temp1->data <= temp2->data) {
            append(head3,temp1->data);
            temp1=temp1->next;
        }
        else if(temp1==NULL || temp1->data > temp2->data) {
            append(head3,temp2->data);
            temp2=temp2->next;
        }
    }
}

/* Merge 2 lists in 1 list */
Node* MergeLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method 
    
   struct Node *t1=headA,*t2=headB,*dt2;
    
   if(headA==NULL) {
       return headB;
   } 
    
    if(headB==NULL)
        return headA;
    
    if(headA->data > headB->data) {
        dt2=t2->next;
        t2->next=headA;
        headA=headB;
        t2=dt2;
    }
    
    while(1) {
        if(t1->next==NULL) {
            t1->next=t2;
            return headA;
        }
        else if(t2==NULL) {
            return headA;
        }
        else if(t1->next->data >= t2->data) {
            dt2=t2->next;
            t2->next=t1->next;
            t1->next=t2;
            t2=dt2;
        }
        else {
            t1=t1->next;
        }
    }
    
}

int FindMergeNode(Node *headA, Node *headB)
{
    // Complete this function
    // Do not write the main method. 
    
    int l1=0,l2=0;
    
    struct Node *t1=headA,*t2=headB;
    
    while(t1!=NULL) {
        l1++;
        t1=t1->next;
    }
    
    while(t2!=NULL) {
        l2++;
        t2=t2->next;
    }
    
    t1=headA;
    t2=headB;
    
    if(l1>l2) {
        int x=l1-l2;
        while(x--) {
            t1=t1->next;
        }
    }
    
    if(l1<l2) {
        int x=l2-l1;
        while(x--) {
            t2=t2->next;
        }
    }
    
    while(t1!=t2) {
        t1=t1->next;
        t2=t2->next;
    }
    
    return t1->data;
}



int main() {
    node *head=NULL; //just a pointer

    frontInsertion(&head,12);
    frontInsertion(&head,10);
    frontInsertion(&head,8);
    append(&head,14);
    append(&head,16);
    sortedInsertion(&head,9);
    sortedInsertion(&head,11);
    deleteNode(&head,22);

    // Search
    int p=10;
    printf("Is %d in Link List ? %s\n",p,searchNode(head,p)==true?"YES":"NO");

    // Length of Link list
    printList(head);
    printf("\nLength : %d",len(head));

    // Nth Node
    node *a;
    a=getNthNode(head,12);
    if(a!=NULL) printf("\nNth node : %d\n",a->data);

    // reverse list
    reverseList(&head);
    printf("\n");
    printList(head);
    printf("\n");
    recursiveReverseList(&head);
    printList(head);

    detectLoop(head);
    bool flag=isPalindrome(head);
    printf("\nIs Palindrome ? %s",flag==true?"YES":"NO");

    // Merge 2 link list
    node *head1=NULL,*head2=NULL,*head3=NULL;
    append(&head1,10);
    append(&head1,30);
    append(&head1,50);
    append(&head1,70);
    append(&head2,20);
    append(&head2,40);
    append(&head2,60);

    mergeList(head1,head2,&head3);
    printf("\nMerged List :: ");
    printList(head3);

    return 0;
}
