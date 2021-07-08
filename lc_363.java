import java.util.ArrayList;

public class Main{
	public static void main (String[]args){
		var sol=new Solution();
		System.out.printf("The result is %d.\n", sol.uniquePaths_combination(2,5));
		return;
	}
}

class Solution{
	int maxSum;
	int subSum;

	int maxSumSubMatrix(int[][] matrix, int k){
		maxSum=0;
	}

	boolean combine(int[][] matrix, int idx, int k, int sum){
		if (subSum==k){
			return true;
		}else if (subSum<k){
			subSum=Math.max(subSum, sum);
		}

		for (int i=idx;i<matrix.length;i++){
			for (int j=idx;j<matrix[0].length;j++){
				subSum=0;
				for (int m=idx;m<=i;m++){
					for (int n=idx;n<=j;n++){
						subSum+=matrix[m][n];
					}
				}
			}
		}
	}
}
