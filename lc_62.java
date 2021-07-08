import java.util.ArrayList;


public class Main{
	public static void main (String[]args){
		var sol=new Solution();
		System.out.printf("The result is %d.\n", sol.uniquePaths_combination(2,5));
		return;
	}
}

class Solution{
	int dfs(int i, int j,int m,int n){
		if (i>m || j>n) return 0;  //index out of bound->end criterion
		if (i==m && j==n) return 1;  //reach the leaf node->found 1 solution
		return dfs(i+1, j, m, n) + dfs(i, j+1, m, n);
	}

	public int uniquePaths(int m, int n){
		return dfs(1,1,m,n);
	}

	int uniquePaths_2d(int m, int n){
		var dd=new int[m][n];

		int i,j;
		//initialization
		for (i=0;i<m;i++) dd[i][0]=1;
		for (i=0;i<n;i++) dd[0][i]=1;

		for (i=1;i<m;i++){
			for (j=1;j<n;j++){
				dd[i][j]=dd[i-1][j]+dd[i][j-1];
			}
		}
		return dd[m-1][n-1];
	}

	int uniquePaths_1d(int m, int n){
		//var dd=new ArrayList<Integer>(n);
		int []dd=new int[n];
		int i,j;

		for (i=0;i<n;i++) dd[i]=1;

		for (i=1;i<m;i++){
			for (j=1;j<n;j++){
				dd[j]+=dd[j-1];
			}
		}
		return dd[n-1];
	}

	int uniquePaths_combination_error(int m, int n){
		int numerator=1, denominator=1;
		int count=m-1;
		int t=m+n-2;
		
		while (count!=0){
			numerator*=(t--); //A(m-1, m+n-2), risk of overflowing
			count--;
		}

		for (int i=1;i<=m-1;i++){
			denominator*=i;  //A(m-1, m-1)
		}
		return numerator/denominator;
	}

	int uniquePaths_combination(int m, int n){
		long numerator=1;
		int denominator=m-1;
		int count=m-1;
		int t=m+n-2;

		while (count!=0){
			numerator*=(t--);
			while (denominator!=0 && numerator % denominator==0){
				numerator /= denominator;
				denominator--;
			}
			count--;
		}
		return (int)numerator;
	}
}

