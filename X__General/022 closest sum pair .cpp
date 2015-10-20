/*
Given a sorted array find pairs such that their sum is closest to the given value
*/

#include<bits/stdc++.h>
using namespace std;

void findSolution(int a[], int n , int value) {
    int l,r,x,y;
    
    l=0;
    r=n-1;
    int diff=INT_MAX;
    
    while(l<r) {
        /* If current pair is closest than previous  */
        if( abs (a[l] + a[r] - value) < diff ) {
            diff= abs (a[l] + a[r] - value ) ;
            x=a[l];
            y=a[r];
        }
        
        if(diff==0)
            break;
        
        /* If current sum is larger than given value reduce sum by r-- */
        if( a[l] + a[r] > value )
            r--;
        /* If current sum is less than given value increase sum by l++ */
        else if( a[l] + a[r] < value)
            l++;
            
    }

    printf("Closest pair : %d %d",x,y);
}

int main()
{
    int a[]={ 1 , 2 , 3 , 4 , 5};
    int value=11;
    
    findSolution( a, sizeof(a)/sizeof(a[0]) , value );
    
    return 0;
}
