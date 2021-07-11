#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
	int islandsNum(vector<vector<int>> &grid){
		if (grid.empty())
			return 0;

		int m,n, ans, i, j;

		m=grid.size();
		n=grid[0].size();
		ans=0;
		for (i=0;i<m;i++){
			for (j=0;j<n;j++){
				ans+=grid[i][j]-'0';
				dfs(grid, i, j, m, n);
			}
		}
		return ans;
	}

	void dfs(vector<vector<char>> &grid, int i, int j, int m, int n){
		if (i<0||j<0||i>=m|| j>=n || grid[i][j]=='0'){
			return ;

			grid[i][j]='0'; //

			dfs(grid, i+1, j, m, n); //down
			dfs(grid, i-1, j, m, n); //up
			dfs(grid, i, j+1, m, n); //right
			dfs(grid, i, j-1, m, n); //left
		}
	}
};

int main (){
	string s;

	s.push_back('1');
	s.push_back('3');
	s.push_back('2');
	cout<<s<<endl;
	return 0;
}
