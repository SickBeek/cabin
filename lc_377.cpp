#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
	public:
		int combinationSum4(vector<int>& nums, int k) {

        int i,j;
        vector<int> dd(k+1, 0);

        dd[0]=1;
        for (i=0;i<=k;i++){ //bag
            for (j=0;j<nums.size();j++){ //items

				//idx>=0 && check overflow
                if (i-nums[j]>=0 && dd[i]<INT_MAX-dd[i-nums[j]]){
                    dd[i]+=dd[i-nums[j]];
                }
            }
			for (auto d:dd) cout<<d<<" "; cout<<endl;
        }
        return dd[k];
    }
};

int main (){
	Solution sol;
	vector<int> nums={1,2,3};

	sol.combinationSum4(nums, 4);
	return 0;
}
