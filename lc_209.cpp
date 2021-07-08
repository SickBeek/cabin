#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

class Solution {
	public:
		int min_sub_brutal(int target, vector<int> &nums){
			int sum, min_len, i, j, count;
			sum=i=j=0;
			min_len=INT32_MAX;
			count=nums.size();

			for (i=0;i<count;i++){
				sum=0;
				for (j=i;j<count;j++){
					sum+=nums[j];
					//cout<<sum<<endl;
					if (sum>=target){
						if (j-i+1<min_len){
							min_len=j-i+1;
							break;
						}
					}
				}
			}
			return min_len;
		}

		int min_sub_slide_window(int target, vector<int> &nums){
			int sum, min_len, i, j, count, sub_len;
			sum=i=j=0;
			count=nums.size();
			min_len=sub_len=count;

			for (;j<count;j++){
				sum+=nums[j];
				while (sum >=target){
					sub_len=j-i+1;
					min_len = min_len<sub_len?min_len:sub_len;
					sum-=nums[i++]; //key line
				}
			}
			return min_len==count?0:min_len;
		}

		int min_sub_slide_window_opt(int target, vector<int> &nums){
			int sum,i,j,min_len,sub_len,nums_len;
			i=j=sum=0;
			nums_len=nums.size();
			min_len=sub_len=nums_len+1;

			if (nums.size()==0)
				return 0;

			for (;j<nums_len;j++){
				if (nums[j]>=target)
					return 1;

				sum+=nums[j];
				while (sum>=target){
					min_len=(min_len<j-i+1)?min_len:j-i+1;
					sum-=nums[i++];
				}
			}
			//return min_len==nums_len?0:min_len;
			return min_len %(nums_len+1);
		}

		int min_sub_fastest(int target, vector<int> &nums){
			int i=0,j=0;
			int len=nums.size();
			int sum=0;

			while (j<len && sum<target){
				sum+=nums[j];
				j++;
			}

			if (sum<target)
				return 0;

			while (sum-nums[i]>=target){
				sum-=nums[i];
				i++;
			}

			while (j<len){
				sum=sum+nums[j]-nums[i];
				j++;
				i++;
				while (sum-nums[i]>=target){
					sum-=nums[i];
					i++;
				}
			}
			return j-i;
		}
};

int main (){
	Solution sol=Solution();
	vector<int> nums={2,3,1,2,4,3};
	//cout<<INT32_MAX<<endl;
	assert(sol.min_sub_brutal(7, nums)==2);
	assert(sol.min_sub_slide_window(7, nums)==2);
	assert(sol.min_sub_slide_window_opt(7, nums)==2);
	assert(sol.min_sub_fastest(7, nums)==2);
	return 0;
}
