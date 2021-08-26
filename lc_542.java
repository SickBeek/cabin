class Solution {
	public int [][] updateMatrix(int [][]mat){
		int i,j, m, n;

		m=mat.length;
		n=mat[0].length;
		int [][]res=new int [m][n];
	}

	int dfs(int i, int j, int [][]mat, int dis){
		if (!isSafe(i, j, mat.length, mat[0].length)){
			return dis-1;
		}

		int res=-1;
		if (mat[i][j]==0)  res=dis;

		int left=dfs(i, j-1, mat, dis+1);
		int right=dfs(i, j+1, mat, dis+1);
		int up=dfs(i-1, j, mat, dis+1);
		int down=dfs(i+1, j, mat, dis+1);
	}

	boolean isSafe(int i, int j, int m, int n){
		if (i<0 || i>m || j<0 || j>n){
			return false;
		}
		return true;
	}
}

