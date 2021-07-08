#include<iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Solution{
	public:
		int removeElement(vector<int> &nums, int val){
			vector<int>::size_type remove=0, i=0;
			vector<int>::size_type n=nums.size();

			if (n==1 && nums[0]==val){
				return 0;
			}

			for (;i <n;i++){
				if (nums[i]==val){
					remove++;
					i++;
					while (nums[i]!=val){
						if (i>=n)
							return i-1;
						nums[i-remove]=nums[i++];
					}
				}
				if (nums[i]==val){
					i--;
				}
			}
			return i-remove;
			//return nums.size();
		}

		int remove_brutal(vector<int> nums, int val){
			vector<int>::size_type count=0, size=nums.size();

			for (int i=0; i<size; i++){
				if (nums[i]==val){
					for (int j=i+1; j<size; j++){
						nums[j-1]=nums[j];
					}
					i--;
					size--;
				}
			}
			return size;
		}

		int remove_slow_fast(vector<int> nums, int val){
			vector<int>::size_type slow_index=0, fast_index=0;
			for (;fast_index<nums.size();fast_index++){
				if (nums[fast_index]!=val){
					nums[slow_index++]=nums[fast_index];
				}
			}
			return slow_index;
		}
};

int main (){
	//s=Solution();
	Solution s;
	vector<int> nums1={1,2,3,4,3,5,6};
	cout<<"Returned length:"<<s.removeElement(nums1, 3)<<endl;
	return 0;
}
