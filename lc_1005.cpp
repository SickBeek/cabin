#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
	public:
			static bool cmp(int a, int b){
				return abs(a)>abs(b);
			}

		int largestSum(vector<int> &nums, int k){

			int sum;
			sort(nums.begin(), nums.end(), cmp);
			for (int i=0;i<nums.size();i++){
				if (nums[i]<0 && k>0){
					nums[i]=-nums[i];
					k--;
				}
			}

			if (k%2==1){
				nums.back()=-nums.back();
			}

			sum=0;
			for (int i=0;i<nums.size();i++){
				sum+=nums[i];
			}
			return sum;
		}

		int largestSumAfterKNegations(vector<int>& nums, int k) {
			sort(nums.begin(), nums.end());

			int neg_num, i, j, n, sum;
			bool zero=false;
			sum=0;
			neg_num=i=0;
			n=nums.size();

			for (;i<n;i++){
				if (nums[i]>=0){
					if (nums[i]==0)
						zero=true;
					break;
				}else {
					neg_num++;
				}
			}

			if (k%neg_num ==0){
				for (i=0;i<n;i++) sum+=abs(nums[i]);
			}else if (neg_num>k){
				if (zero || neg_num-k %2 ==0) for(i=0;i<n;i++) sum+=abs(nums[i]);
				else {
					for(i=0;i<n;i++) sum+=abs(nums[i]);
					sum-=2*nums[negnum];
				}
			}
		}
};

int main (){
	Solution sol;
	vector<int> nums={2, -3, -1, 5, -4};

	cout<<sol.largestSum(nums, 2)<<endl;
	return 0;
}
