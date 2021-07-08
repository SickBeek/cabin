#include <iostream>
#include <vector>
using namespace std;

class Solution{
	private:

	public:
		vector<string> result;
		string path;
		int target;

		void backtracking(vector<int> &candidates, int index, int sum){
			if (sum==target){
				result.push_back(path);
				return;
			}else if (sum>target){
				return;
			}
			
			for (int i=index;i<candidates.size();i++){
				path.push_back(candidates[i]);
				//sum+=candidates[i];
				backtracking(candidates, i, sum+candidates[i]);
				//backtracking(candidates, i, sum);
				//sum-=candidates[i];
				path.pop_back();
			}
		}

		void combine_sum2(vector<int> &candidates, int index, int sum){
			if (sum==target){
				result.push_back(path);
				return;
			}else if (sum>target){
				return;
			}
			
			for (int i=index;i<candidates.size();i++){
				if (i>index && candidates[i]==candidates[i-1])
					continue;
				path.push_back(candidates[i]);
				backtracking(candidates, i, sum+candidates[i]);
				path.pop_back();
			}
		}

		vector<string> combinationSum(vector<int> &candidates,int key){
			target=key;
			result.clear();
			path.clear();
			backtracking(candidates, 0, 0);
			return result;
		}

};

int main(){
	Solution sol;
	vector<string> res;
	vector<int> candidates={2,3,6,7};

	res=sol.combinationSum(candidates, 7);
	for(auto s: res){
		for(auto f: s){
			cout<<f<<" ";
		}
		cout<<endl;
	}
		cout<<endl;
	return 0;
}
