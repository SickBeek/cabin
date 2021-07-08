#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution{
	private:
		vector<vector<int>> result;
		vector<int> path;

		vector<vector<int>> combination(int n, int k, int start){
			if (path.size()==k){
				result.push_back(path);
				return;
			}

			for (int i=start;i<=n; i++){
				path.push_back(i);
				combination(n,k, i+1);
				path.pop_back();
			}
		}

	public:

		void combine(int n, int k, int start_index){
			combination(n, k, 1);
			return result;
		}

};

int main(){
	return 0;
}
