#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution{
	public:
		int depth_max=INT_MIN;
		int left_most;

		void pre_order(TreeNode* root, int depth){
			if (!root->left && !root->right){
				if (depth>depth_max){
					depth_max=depth;
					left_most=root->val;
				}
				return;
			}
			if (root->left) pre_order(root->left, depth+1);
			if (root->right) pre_order(root->right, depth+1);
		}

		int find_bottom_left(TreeNode *root){
			pre_order(root, 0);
			return left_most;
		}
};

int main(){
	Solution sol;
	return 0;
}

