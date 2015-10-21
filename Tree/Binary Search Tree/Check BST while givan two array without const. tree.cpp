/*
Given two arrays which represent a sequence of keys.
Imagine we make a Binary Search Tree (BST) from each array.
We need to tell whether two BSTs will be identical or not without actually constructing the tree.
*/
#include<bits/stdc++.h>

using namespace std;

bool isSameBST(int a[],int b[],int n1,int n2) {
    if(n1==0 && n2==0)          /* BST if array is empty */
        return 1;

    if(a[0]!=b[0]  || n1!=n2)   /* different root or different length array */
        return 0;

    if(n1==1)                  /* Only 1 element in both array and are same */
        return 1;

    int left_a[n1],right_a[n1],la=0,ra=0;
    int left_b[n2],right_b[n2],lb=0,rb=0;

    /* left sub tree in left_a and right sub tree in right_a having root a[0] */
    for(int i=1;i<n1;i++) {
        if(a[i]>a[0])
            right_a[ra++]=a[i];
        else
            left_a[la++]=a[i];
    }

    /* left sub tree in left_b and right sub tree in right_b having root b[0] */
    for(int i=1;i<n2;i++) {
        if(b[i]>b[0])
            right_b[rb++]=b[i];
        else
            left_b[lb++]=b[i];
    }

    return isSameBST(left_a,left_b,la,lb) && isSameBST(right_a,right_b,ra,rb);
}

int main(){

    int a[] = {8, 3,  6,  1, 4, 7, 10, 14, 13};
    int b[] = {8, 10, 14, 3, 6, 4, 1,  7,  13};
    int n1=sizeof(a)/sizeof(a[0]);
    int n2=sizeof(b)/sizeof(b[0]);

    cout<<" Is same BST ?  "<<isSameBST(a,b,n1,n2)<<endl;


    int a1[] = {8, 3,  16,  1, 4, 7, 10, 14, 6};
    int b1[] = {8, 10, 14, 3, 6, 4, 1,  7,  16};
    int n11=sizeof(a1)/sizeof(a1[0]);
    int n12=sizeof(b1)/sizeof(b1[0]);

    cout<<" Is same BST ?  "<<isSameBST(a1,b1,n11,n12)<<endl;


    return 0;
}
