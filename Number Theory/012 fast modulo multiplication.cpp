#include<iostream>
#include<stdio.h>

using namespace std;

/* FORMULA :
mul(a,b) = 0              :: if b=0 ;
         = 2*mul(a,b/2)     :: if b is even
         = a + 2*mul(a,b/2) :: if b is odd 
*/

long long int fast_modulo_mul(long long int a, long long int b, long long int mod) {
    
     long long int result;
     
     if(b==0) 
        return 0;

     result = fast_modulo_mul(a,b/2,mod);
     result=(result+result) % mod;

     if(b & 1) {   // for odd b
         result=( result + a ) % mod ;
     }        

     return result;
}

int main() {
    long long int a,b,mod;
    cin>>a>>b>>mod;
    cout<< fast_modulo_mul(a,b,mod) <<endl;
    return 0;
}
