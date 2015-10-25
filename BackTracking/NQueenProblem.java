/*
 * N Queen Problem
 * Given N*N Grid . 
 * Q Queens
 * Arrange Queens such that no two Queen can kill each other.
 * 
 * */
package Problems;

public class NQueenProblem {
	char ASSIGN_QUEEN='Q';
	char EMPTY_CELL='-';
	int N;
	char Grid[][]; 
	
	public NQueenProblem(int N) {
		this.N=N;
		Grid=new char[N][];
		
		for(int i=0;i<N;i++) {
			Grid[i]=new char[N];
		}
		
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				Grid[i][j]=EMPTY_CELL;
			}
		}
	}

	private void printSolution() {
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				System.out.print( Grid[i][j] + " ");
			}
			System.out.println("");
		}
	}

	void solveProblem(int queens) {
		boolean possible=solve(queens);
		if(possible)
			printSolution();
		else
			System.out.println("Not Possible");
	}
	
	private boolean solve(int remainedQueens) {
		if(remainedQueens==0) {
			//System.out.println("Completed");
			return true;
		}
		
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				if(isSafe(i,j)) {
					//System.out.println("i j " + i +" " + j);
					Grid[i][j]=ASSIGN_QUEEN;
					
					if(solve(remainedQueens-1)) {
						return true;
					}
					
					Grid[i][j]=EMPTY_CELL;
				}
			}
		}
		
		return false;
	}
	
	private boolean isSafe(int x, int y) {
		
		if(Grid[x][y]==ASSIGN_QUEEN)
			return false;
		
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				if(Grid[i][j]==ASSIGN_QUEEN) {
					
					if(x==i || y==j)
						return false;
					
					if(Math.abs(x-i)==Math.abs(y-j))
						return false;
				}
			}
		}
		
		return true;
	}

	public static void main(String args[]) {
		int N=10;
		int Q=10;
		NQueenProblem nq=new NQueenProblem(N);
		nq.solveProblem(Q);
	}
}
