#include <vector>
#include <stack>
#include <utility>
#include <unordered_map>
using namespace std;

#define VISITED 2
#define WATER 0
#define LAND 1

class Solution{
	public:
		bool isSafe(int i, int j, int m, int n){
			if  (i<0 || j<0 || i>=m || j>=n) return false;
			return true;
		}

		void mark(vector<vector<int>> &g, int &i, int &j, int &area){
			if (!isSafe(i, j, g.size(), g[0].size()) || g[i][j]==WATER || g[i][j]==VISITED) return;
			g[i][j]=VISITED;
			++area;
			mark(g, ++i, j, area); //down
			mark(g, --i, ++j, area); //right
			mark(g, --i, --j, area); //up
			mark(g, ++i, --j, area); //left
			++j; //center
		}

		int count(vector<vector<int>> grid, int i, int j, int width, int height){
			if (i>width || j>height || grid[i][j]==WATER || grid[i][j]==VISITED){
				return 0;
			}

			return 1+count(grid, i+1, j, width, height)+count(grid, i-1, j, width, height)+count(grid, i, j+1, width, height)+count(grid, i, j-1, width, height);
		}

		int maxAreaOfIsland(vector<vector<int>> &grid){
			int maxArea=0;
			for (int i=0;i<grid.size();i++){
				for (int j=0;j<grid.size();j++){
					if (grid[i][j]==LAND){
						int area=0;
						mark(grid, i, j, area);
						maxArea=max(area, maxArea);
					}
				}
			}
			return maxArea;
		}

};

int main (){
	return 0;
}
