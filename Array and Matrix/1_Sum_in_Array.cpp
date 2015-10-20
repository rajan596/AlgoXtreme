/*
if you have an array of size n (n<50) and you have (a0,a1,a2......,an) elements filled in each cell ...can you tell me the number of j where i is the indexes of the array such that sum of elements before that and after that is equal ..
INPUT STYLE : first line contains the value of n and then in next line there are n values the value of (a0,a1,....an) separated by space 
OUTPUT STYLE : print the count of no. of indexes satisfying the given case 
EXAMPLE : 
INPUT : 
4
1 2 3 3
OUTPUT : 
1
because only 3rd element at index no. 2 satisfies the required thing ...
*/
#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	int n[50]={0},
		t,
		count=0,
		before=0,   // sum before perticular element
		after=0;		// sum after pertucular element
	
	cin>>t;
	
	//considering index from 1
	for(int i=1;i<=t;i++)
	{
		cin>>n[i];
		after+=n[i];
	}
	
	for(int i=1;i<=t;i++)
	{
		before=before+n[i-1];
		after=after-n[i];
		
		if (before==after)
			count++;	
	}
	
	cout<<count<<endl;
	
	return 0;
}
