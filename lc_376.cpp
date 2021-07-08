#include <iostream>
#include <vector>
using namespace std;

class Solution{
	public:
		int wiggle_max_len(vector<int>& nums){
			if (nums.size()<=1) return nums.size();

			int cur_diff, pre_diff, result, i;

			cur_diff=pre_diff=0;
			result=1;
			for (i=1;i<nums.size();i++){
				cur_diff=nums[i]-nums[i-1];

				//peak
				if ((cur_diff>0 && pre_diff<=0) || (pre_diff>=0 && cur_diff<0)){
					result++;
					pre_diff=cur_diff;
				}
			}
			return result;
		}

};

int main () {
	Solution sol;
	vector<int> seq={1,17,5,10,13,15,10};

	cout<<sol.wiggle_max_len(seq)<<endl;
	return 0;
}

