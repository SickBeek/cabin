#include <iostream>
#include <vector>

class Solution{
	public:
		int jump(vector<int> &nums){
			if (nums.size()==1) return 0;

			int cur, next, i, result, n;

			cur=next=result=0;
			n=nums.size();
			for (i=0;i<n;i++){
				next=max(next, i+nums[i]);
				if (i==cur){
					if (cur!=n-1){  //not the end
						result++;
						cur=next;
						if (next>=n-1) break;
					}else {
						break;
					}
				}
			}
			return result;
		}

		int jump2(vector<int> &nums){
			if (nums.size()==1) return 0;

			int cur, next, i, result, n;

			cur=next=result=0;
			n=nums.size();
			for (i=0;i<n-1;i++){
				next=max(next, i+nums[i]);
				if (i== cur){
					cur=next;
					result++;
				}
			}
			return result;
		}

};

int main (){
	Solution sol;
	vector<int> nums={2,2,1,1,4};
	
	cout<<sol.jump(nums)<<endl;
	return 0;
}

