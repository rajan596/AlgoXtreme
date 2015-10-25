package Problems;

import java.util.ArrayList;
import java.util.Arrays;

public class SubSetSumProblem {
	
	ArrayList<Integer> result=new ArrayList<Integer>();
	
	private void findSubSet(int[] a, int i, int j, int sum) {
		Arrays.sort(a);
		
		boolean possible=solve(a,i,j,sum);
		
		if(possible)
			System.out.println("Subsets are Possible");
		else
			System.out.println("Not Possible");
	}
	
	private boolean solve(int[] a, int l, int r, int sum) {
		/* base case */
		if(sum<0)
			return false;
		
		if(sum==0) {
			printSolution(a);
			return true;
		}
		
		boolean possible1=false,
				possible2=false;
		
		//System.out.println("Size : "+result.size());
		
		//printSolution(a);
		
		for(int i=l;i<=r;i++) {
			/* If not taken */
			result.add(0);
			if(sum>0)
			possible1=solve(a,l+1,r,sum);
			result.remove(result.size()-1);
			
			/* If taken */
			result.add(1);
			possible2=solve(a,l+1,r,sum-a[l]);	
			result.remove(result.size()-1);
			
			if(possible1 || possible2) {
				return true;
			}
		}
		
		return false;
	}

	private void printSolution(int[] a) {
		
		System.out.print("Subset : ");
		
		for(int i=0;i<result.size();i++) {
			if(result.get(i)==1) {
				System.out.print(a[i] + " ");
			}
		}
		System.out.println("");
	}

	public static void main(String args[]) {
		int a[]={10,5,6,7,8,200};
		int sum=200;
		
		SubSetSumProblem p1=new SubSetSumProblem();
		p1.findSubSet(a,0,a.length-1,sum);
	}
}
