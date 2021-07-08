#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution{

	vector<vector<string>> result;
	public:
		void combine(int n, int row, vector<string>& board){
			if (row==n){
				result.push_back(board);
				return;
			}
			
			for (int i=0;i<n;i++){
				if (isValid(row, i, board)){
					board[row][i]='Q';
					combine(n, row+1, board);
					board[row][i]='.';
				}
			}
		}

		bool isValid(int row,int col,vector<string>& board, int n){
			int i, j;

			for (i=0;i<row;i++){
				if (board[i][col]=='Q'){
					return false;
				}
			}

			i=row-1, j=col-1; //45 degree
			while (i>=0 && j>=0){
				if (board[i][j]=='Q'){
					return false;
				}
			}

			
			i=row-1, j=col+1;  //135 degree
			while (i>=0 && j<n){
				if (board[i][j]=='Q'){
					return false;
				}
			}

			return true;
		}
	
};

int main(){
	return 0;
}

