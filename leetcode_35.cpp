#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		int search_insert(vector<int> &nums, int target){
			int n=nums.size();
			for (int i=0; i <n; i++){
				if (nums[i]>=target){
					return i;
				}
			}
			return nums.size();
		}

		int search_binary(vector<int> &nums, int target){
			int left=0, mid=0, right=nums.size()-1;
			while (left<=right){
				mid=left+((right-left)/2);
				if (nums[mid]>target){
					right=mid-1;
				}
				else if (nums[mid]<target){
					left=mid+1;
				}
				else{
					return mid;
				}
			}
			return left;
		}

		int search_binary_2(vector<int> nums, int target){
			int left=0, mid=0, right=nums.size();
			while (left<right){
				mid=left+((right-left)/2);
				if (nums[mid]>target){
					right=mid;
				}
				else if (nums[mid]<target){
					left=mid+1;
				}
				else{
					return mid;
				}
			}
		}

		int search_insert_duplicate(vector<int>& nums, int target) {
			int low = 0, high = nums.size()-1;

			// Invariant: the desired index is between [low, high+1]
			while (low <= high) {
				int mid = low + (high-low)/2;

				if (nums[mid] < target)
					low = mid+1;
				else
					high = mid-1;
			}

			// (1) At this point, low > high. That is, low >= high+1
			// (2) From the invariant, we know that the index is between [low, high+1], so low <= high+1. Follwing from (1), now we know low == high+1.
			// (3) Following from (2), the index is between [low, high+1] = [low, low], which means that low is the desired index
			//     Therefore, we return low as the answer. You can also return high+1 as the result, since low == high+1
			return low;
		}

		int my_upper_bound(vector<int>& nums, int target) {
			int first=0, it=0, step=0, count=nums.size();
			while (count>0){
				it=first;
				step=count>>1;
				if (nums[it]<=target){
					first=++it;
					count-=step+1;
				}
				else {
					count=step;
				}
			}
		}
};

int main(){
	Solution sol=Solution();
	vector<int> vec={0,1,2,3,4,5,6};
	cout<<sol.search_insert_duplicate(vec, 3)<<endl;
	//cout<<sol.search_binary(vec, 3)<<endl;
	return 0;
}

/*
class solution:
	def search_insert(self, nums, target):
		left=0
		right=len(nums)
		while (left <right):
			mid =left+(right -left )/2
			if (nums[mid]>target):
				right=mid-1
			elif (nums[mid]<target):
				left=mid+1
			else:
				return mid
		return mid
*/

