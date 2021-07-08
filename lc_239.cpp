#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <deque>
using namespace std;

class MyQueue {
	public:
		deque<int> que;
		void pop(int value){
			if (!que.empty() && value == que.front()){
				que.pop_front();
			}
		}

		void push(int value){
			while (!que.empty() && value > que.back()){
				que.pop_back();
			}
			que.push_back(value);
		}

		int front(){
			return que.front();
		}
};

class Solution {
	public:
		vector <int> max_sliding_window(vector<int> &nums, int k){
			vector<int>::size_type left, right;
			int max_num, maxi;
			vector <int> result;

			left=0;
			right=left+k-1;
			max_num=nums[0];
			maxi=0;

			/*
			for (i=left;i<=right;i++){
				if (nums[i]>=max_num){
					max_num=nums[i];
					maxi=i;
				}
			}
			*/
			max_num=max_within(nums, left, right, maxi);
			result.push_back(max_num);
			left++;
			right++;
			if (right<nums.size() && left-1==maxi){
				max_num=max_within(nums, left, right, maxi);
			}

			while (right<nums.size()){
				if (nums[right]>=max_num){
					max_num=nums[right];
					maxi=right;
				}
				result.push_back(max_num);
				left++;
				right++;
				if (right>= nums.size())
					break;
				if (left-1==maxi){
					max_num=max_within(nums, left, right, maxi);
				}
			}
			return result;
		}

		int max_within(vector<int> nums, int left, int right, int &maxi){
			int i, max_num;
			max_num=nums[left];
			maxi=left;

			for (i=left;i<=right;i++){
				if (nums[i]>=max_num){
					max_num=nums[i];
					maxi=i;
				}
			}
			return max_num;
		}


		vector <int> max_sliding_window_que(vector<int> &nums, int k){
			MyQueue que;
			vector <int> result;

			for (int i=0;i<k;i++){
				que.push(nums[i]);
			}

			result.push_back(que.front());

			for (int i=k;i<nums.size();i++){
				//move slide window
				que.pop(nums[i-k]);
				que.push(nums[i]);
				//append the max/front element
				result.push_back(que.front());
			}
			return result;
		}
};

int main (){
	vector<int> tokens={1,3,-1,-3,5,3,6,7};
	//vector<int> tokens={1,-1};
	Solution sol=Solution();
	vector<int> result=sol.max_sliding_window_que(tokens, 2);


	for (auto i:result)
		cout<<i<<",";
	cout<<endl;
	return 0;
}
