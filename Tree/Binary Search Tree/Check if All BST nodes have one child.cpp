/* Given pre order Traversal of an BST as an array
 * Check if all the nodes has only one child
 */
#include<bits/stdc++.h>

using namespace std;

bool hasOnlyOneChild(int a[],int n) {
    /* Suffix arrays to stores min and max values for interval [i , n-1] */
    int mn[n],mx[n];

    mn[n-1]=mx[n-1]=a[n-1];

    for(int i=n-2;i>=0;i--) {
        mx[i]=max(mx[i+1],a[i]);
        mn[i]=min(mn[i+1],a[i]);
    }

    for(int i=0;i<n;i++){
        if(a[i]!=mn[i] && a[i]!=mx[i])
            return 0;
    }
    return 1;
}

int main(){

    int pre[]={8,3,5,7,6};
    int n=sizeof(pre)/sizeof(pre[0]);

    cout<<">> Case 1 : "<<hasOnlyOneChild(pre,n)<<endl;

    int pre1[]={20,10,11,13,12,17};
    int n1=sizeof(pre1)/sizeof(pre1[0]);

    cout<<">> Case 2 : "<<hasOnlyOneChild(pre1,n1)<<endl;

    int pre2[]={20,10,40,11,13,12};
    int n2=sizeof(pre2)/sizeof(pre2[0]);

    cout<<">> Case 3 : "<<hasOnlyOneChild(pre2,n2)<<endl;


    return 0;
}
