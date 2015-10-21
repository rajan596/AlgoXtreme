/* Calculate possible BSTs having different N keys
 * These values ara called catalen's Number
 */
#include<bits/stdc++.h>

using namespace std;

int BST[100];

int countBSTs(int n) {
    BST[0]=1;   /* if no keys total ways=1 */
    BST[1]=1;   /* if 1 key total ways=1 */

    for(int i=2;i<=n;i++) {
        BST[i]=0;
        for(int j=0;j<i;j++){
            BST[i]+=BST[j]*BST[i-j-1];
        }
    }
}

int main(){

    countBSTs(50);

    cout<<5<<" : "<<BST[5]<<endl;
    cout<<5<<" : "<<BST[5]<<endl;
    cout<<5<<" : "<<BST[5]<<endl;

    return 0;
}
