#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
	public:
    int LIS(vector<int>& nums) {
		vector<int> tails(nums.size());

		int size, i, j, mid;
		size=0;
		for (auto x :nums){
			i=0; j=size;
			while (i<j){
				mid=(j-i)/2+i;
				if (tails[mid]<x){
					i=mid+1;
				}else {
					j=mid;
				}
			}
			tails[i]=x;
			if (i==size) size++;
		}
		return size;
	}
};

int main (){
	Solution sol;
	vector<int> nums={1,-2,654,123,53,712,12};
	sol.LIS(nums);
	return 0;
}
