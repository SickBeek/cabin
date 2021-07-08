#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
	public:
		bool canPartition_wrong_algorithm(vector<int> &nums){
			int i, sumi, j, sumj;

			sort(nums.rbegin(), nums.rend());
			sumi=sumj=0;
			for (i=0;i<nums.size()-1;i++){
				sumi+=nums[i];
				sumj=0;
				for (j=i+1;j<nums.size();j++){
					sumj+=nums[j];
				}
				if (sumj==sumi){
					return true;
				}else if (sumj<sumi){
					return false;
				}
			}
			return false;
		}

		int target;
		vector<int> path;
		bool canPartition_combine_TLE(vector<int> &nums){
			int t=0;
			for (auto n: nums){
				t+=n;
			}

			if (t%2==1) return false;
			target=t/2;
			return combine(nums,0, 0);
		}

		bool combine(vector<int> &nums, int sum, int idx){

			if (path.size()>0 && sum==target){
				return true;
			}

			for (int i=idx;i<nums.size();i++){
				path.push_back(nums[i]);
				if (combine(nums, sum+nums[i], i+1)) return true;
				path.pop_back();
			}
			return false;
		}

	bool canPartition_dp(vector<int> &nums){
		int i,j,sum, half, n;
		
		sum=0;
		n=nums.size();
		for (i=0;i<n;i++){
			sum+=nums[i];
		}

		if (sum%2==1) return false;
		half=sum/2;
		vector<int> dd(half, 0); //initialized as 0 since nums[i]>0

		for (i=0;i<n;i++){
			for (j=half;j>=nums[i];j--){
				dd[j]=max(dd[j], dd[j-nums[i]]+nums[i]);
			}
		}

		return dd[half]==half;
	}
};

int main () {
	Solution sol;
	//vector<int> nums={10,1,1,1,1,1,1,1,1,1,1};
	vector<int> nums={1,2,5};
	cout<<sol.canPartition_dp(nums)<<endl;
	return 0;
}
