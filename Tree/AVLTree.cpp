#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int key;
        int height;
        Node *left;
        Node *right;

        Node(int key){
            this->key=key;
            left=right=NULL;
            height=1;
        }
};

class AVLTree{
    public:
    Node *head;

    AVLTree(){
        head=NULL;
    }

    void insertKey(int key);
    Node* insertKeyRecur(Node *head,int key);
    void deleteKey(int key);
    Node* deleteKeyRecur(Node *head,int key);
    void printTree();
    void inorder(Node *head);
    int height(Node *head);
    int balanceFactor(Node *head);
    Node *leftRotate(Node *head);
    Node *rightRotate(Node *head);
    Node *inorderSuccessor(Node *head);
};

void AVLTree::inorder(Node *head){
    if(head==NULL) return;
    inorder(head->left);
    cout<< head->key <<" "<<head->height<<endl;
    inorder(head->right);
}

Node* AVLTree::inorderSuccessor(Node *head){
    while(head->left!=NULL){
        head=head->left;
    }
    return head;
}

void AVLTree::printTree(){
    inorder(head);
}

int AVLTree::height(Node *head){
    if(head==NULL) return 0;
    return head->height;
}

int AVLTree::balanceFactor(Node *head){
    if(head==NULL) return 0;
    return height(head->left)-height(head->right);
}

Node* AVLTree::leftRotate(Node *head){
    // Rotation
    Node *newHead=head->right;
    head->right=newHead->left;
    newHead->left=head;

    head->height=1+max(height(head->left),height(head->right));
    newHead->height=1+max(height(newHead->left),height(newHead->right));

    return newHead;
}

Node* AVLTree::rightRotate(Node *head){
    // Rotation
    Node *newHead=head->left;
    head->left=newHead->right;
    newHead->right=head;

    head->height=1+max(height(head->left),height(head->right));
    newHead->height=1+max(height(newHead->left),height(newHead->right));

    return newHead;
}

Node* AVLTree::insertKeyRecur(Node *head,int key){

    if(head==NULL){
        Node *newNode=new Node(key);
        return newNode;
    }
    else if(head->key<key)
        head->right=insertKeyRecur(head->right,key);
    else
        head->left=insertKeyRecur(head->left,key);

    // AVL Tree balancing
    int balance=balanceFactor(head);
    head->height=1+max(height(head->left),height(head->right));

    if(balance>1){ // L
        if(head->left->key > key){ // LL
            return rightRotate(head);
        }else { // LR
            head->left=leftRotate(head->left);
            return rightRotate(head);
        }
    }
    else if(balance<-1){ // R
        if(head->right->key<key) { // RR
            return leftRotate(head);
        }else {
            head->right=rightRotate(head->right);
            return leftRotate(head);
        }
    }
    else
        return head;
}

void AVLTree::insertKey(int key) {
    head=insertKeyRecur(head,key);
}

Node* AVLTree::deleteKeyRecur(Node *head,int key){
    if(head==NULL){
        return NULL;
    }
    else if(head->key<key){
        head->right=deleteKeyRecur(head->right,key);
    }
    else if(head->key>key){
        head->left=deleteKeyRecur(head->left,key);
    }
    else { // Node to be deleted
        if(head->left==NULL || head->right==NULL){ // Node having atmost 1 child
            if(head->left==NULL)
                return head->right;
            else
                return head->left;
        }
        else{ // Node having 2 childs
            Node *temp=inorderSuccessor(head->right);
            head->key=temp->key;
            head->right=deleteKeyRecur(head->right,temp->key);
        }
    }

    // AVLTree balancing stuff
    int balance=balanceFactor(head);
    head->height=1+max(height(head->left),height(head->right));

    if(balance>1){ // L
        if(balanceFactor(head->left)>=0){ // LL
            return rightRotate(head);
        }else { // LR
            head->left=leftRotate(head->left);
            return rightRotate(head);
        }
    }
    else if(balance<-1){ // R
        if(balanceFactor(head->right)<=0) { // RR
            return leftRotate(head);
        }else { // RL
            head->right=rightRotate(head->right);
            return leftRotate(head);
        }
    }
    else
        return head;

}

void AVLTree::deleteKey(int key){
    head=deleteKeyRecur(head,key);
}

int main(){

    AVLTree *a=new AVLTree();

    a->insertKey(1);
    a->insertKey(2);
    a->insertKey(3);
    a->insertKey(4);
    a->insertKey(5);
    a->insertKey(6);

    a->printTree();
    a->deleteKey(5);
    a->deleteKey(1);
    a->deleteKey(4);

    printf("\n-----\n");
    a->printTree();

    return 0;
}
