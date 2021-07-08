#include <iostream>
#include <assert.h>
#include <stack>
#include <map>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode ():val(0), next(nullptr){}
	ListNode (int x):val(x), next(nullptr){}
	ListNode (int x, ListNode *next):val(0), next(next){}
	//~ListNode()
};


class Solution {
	public:
		vector<vector<int>> three_sum_set(vector<int> &nums){
			vector<vector<int>> result;
			vector<int>::size_type i,j;

			sort(nums.begin(), nums.end());

			//a=nums[i], b=nums[j], c=0-a-b
			for (i=0;i<nums.size();i++){
				if (nums[i] > 0){
					continue;
				}
				if (i>0 && nums[i]==nums[i-1]){   // deduplicate a
					continue;
				}

//				while (nums[i]==nums[i+1]){
//					i++;
//				}

				unordered_set<int> store;
				for (j=i+1;i<nums.size();j++){
					if (j>i+2 && nums[j]==nums[j-1] && nums[j-1]==nums[j-2]){  //deduplicate b
						continue;
					}

					int c=0-nums[i] -nums [j];
					if (store.find(c) != store.end()){
						result.push_back({nums[i], nums[j], c});
						store.erase(c);
					}else {
						store.insert(c);
					}
				}
			}
			return result;
		}

		vector <vector<int>> three_sum_2pointers(vector <int> &nums){
			vector<vector <int>> result;
			sort(nums.begin(), nums.end());
			vector<int>::size_type i, left, right;

			for (i=0;i<nums.size();i++){
				if (nums[i]>0){
					return result;
				}

				if (i>0 && nums[i]==nums[i-1]){
					continue;
				}

				left=i+1;
				right=nums.size()-1;
				while (left < right){
					if (nums[i]+nums[left]+nums[right>0]){
						right--;
					}else if (nums[i]+nums[left]+nums[right]<0){
						left++;
					} else {
						result.push_back({nums[i],nums[left], nums[right]});

						//de-duplication
						while (left<right && nums[right]==nums[right-1])   right--;
						while (left<right && nums[left]==nums[left+1])   left++;
					}
				}
			}
		}

		vector<vector<int>> threeSum(vector<int>& nums) {
			sort(nums.begin(),nums.end());
			vector<vector<int>> res;

			vector<int>::size_type i;
			for(;i < nums.size() && nums[i] <=0; ++i)
				if(i ==0 || nums[i-1] != nums[i]){
					twoSumII(nums,i,res);
				}

			return res;
			
		}

		void twoSumII(vector<int>& nums, int i , vector<vector<int>> &res){
			int lo, hi;
			lo = i + 1;
			hi = nums.size() - 1;

			while (lo < hi) {
				int sum = nums[i] + nums[lo] + nums[hi];
				if (sum < 0) {
					++lo;
				} else if (sum > 0) {
					--hi;
				} else {
					res.push_back({ nums[i], nums[lo++], nums[hi--] });
					while (lo < hi && nums[lo] == nums[lo - 1])
						++lo;
					while (lo < hi && nums[hi] == nums[hi + 1])
						--hi;
				}
			}
		}

		vector <vector<int>> fourSum(vector <int> &nums, int target){
			if (nums.size()<=3)
				return {};

			sort(nums.begin(), nums.end());
			if (nums[0]>target)
				return {};

			vector<vector<int>> result;
			vector<int>::size_type i,j, left, right;
			int sum;
			i=0;

			for (;i<nums.size()-3;i++){
				while (i>0 && nums[i]==nums[i-1]){  //de-duplicate
					i++;
				}

				for (j=i+1;j<nums.size()-2;j++){
					while (j>i+1 && nums[j]==nums[j-1]){   //de-duplicate
						j++;
					}

					left=j+1;
					right=nums.size()-1;
					while (left<right){
						sum=nums[i]+nums[j]+nums[left]+nums[right];
						if (sum<target){
							left++;
						}else if (sum>target){
							right--;
						}else {
							result.push_back({nums[i],nums[j],nums[left],nums[right]});
							while (left<right &&nums[left]==nums[left+1]) left++;
							while (left<right &&nums[right]==nums[right-1]) right--;
							left++;  right--;
						}
					}
				}
			}
			cout<<"end"<<endl;
			return result;
		}

    vector<vector<int>> fourSum_early_return(vector<int>& nums, int target) {
        vector<vector<int>> sum;
        sort(nums.begin(),nums.end());
        int n = nums.size();
		vector<int>::size_type i,j;

        if(n<=3){return sum;}

        for (i = 0;i<n-3;i++){
            // 改良条件1
            if(i>0 && nums[i] == nums[i-1]) continue;
            if(target<0 && nums[i]>0) break;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if(nums[n-3]+nums[n-2]+nums[n-1]+nums[n-4]<target) break;
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;

            for (j=i+1;j<nums.size()-2;j++){
            // 改良条件2
                if(target-nums[i]<0 && nums[j]>0) break;
                if(j>i+1 && nums[j] == nums[j-1]) continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if(nums[i]+nums[j]+nums[n-1]+nums[n-2]<target) continue;

                for (long k=j+1,l=nums.size()-1;k<l;){
                    if(target-nums[i]-nums[j]<0 && nums[k]>0) break;
                    int a = nums[i];
                    int b = nums[j];
                    int c = nums[k];
                    int d = nums[l];
                    int value = a+b+c+d;
                    if (value == target ){
                        sum.push_back(vector<int>{a,b,c,d});
                        while(k<l && nums[k]==c) k++;
                        while(k<l && nums[l]==d) l--;
                    }
                    else if(value<target){k++;}
                    else if(value>target){l--;}
                }
            }
        }
        return sum;
    }

	int four_sum_4_arrays(vector<int> &nums1, vector<int> &nums2,vector<int> &nums3,vector<int> &nums4){
		unordered_map<int, int> umap;
		int target=0;

		for (int a: nums1)
			for (int b: nums2)
				umap[a+b]++;
		
		int count=0;
		for (int c : nums3)
			for (int d: nums4)
				if (umap.find(target-(c+d))!= umap.cend())  // found
					count+=umap[target-(c+d)];
		return count;
	}
};

int main (){
	Solution sol=Solution();
	vector<int> nums={-5,-4,-3,-2,-1,0,0,1,2,3,4,5};
//	nums={1,0,-1,0,-2,2};
	int target=0;
	auto result= sol.fourSum(nums, target);

	cout<<"{";
	for (auto r:result){
		cout<<"[";
		for (auto s:r)
			cout<<s<<",";
		cout<<"],";
	}
	cout<<"}";
	return 0;
}
