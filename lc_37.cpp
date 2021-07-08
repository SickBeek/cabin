#include <iostream>
#include <vector>
#include <string>

class Solution{

		bool combine (vector<vector<char>> &board){
			if (row==8 && col==9){
				return true;
			}

			for (int i=0;i<9;i++){
				for (int j=0;j<9;j++){
					if (board[i][j]!='.') continue;

					for(char k='1';k<='9';k++){
						if (isValid(i, j, board, k)){
							board[i][j]=k;
							if (combine(board)) return true;
							board[i][j]='.';
						}
					}
					//all 9 chars
				return false;
					
				}
			}
			return false;

		}

	public:
		void sudoku(vector<vector<char>> &board){
			combine(board);
		}

		bool isValid(int row, int col, vector<vector<char>> &board, char ch){
			int r, c, i, j;

			r=row/3 *3;
			c=col/3 *3;
			
			for (i=0;i<9;i++){ //same row
				if (i==col)
					continue;
				if (board[row][i]==ch){
					return false;
				}
			}

			for (i=0;i<9;i++){  //same col
				if (i==row)
					continue;
				if (board[i][col]==ch){
					return false;
				}
			}

			for (i=r;i<r+3;i++){  //within the block
				for (j=c;j<c+3;j++){
					if (i==row && j=col){
						continue;
					}
					if (board[i][j]==ch){
						return false;
					}
				}
			}

			return true;
		}
};

int main {
	Solution sol;

	return 0;
}
