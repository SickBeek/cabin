#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
};

class Solution{
	public:
		vector<int> largest(TreeNode* root){
			if (!root) return {};
			vector<int> res;
			helper(root, res, 0);
			return res;
		}

		void helper(TreeNode* node, vector<int> &res, int level){
			if (!node) return;

			if (level>=res.size())
				res.push_back(node->val);
			else res[level]=(res[level]>node->val)?res[level]:node->val;

			helper(node->left, res, level+1);
			helper(node->right, res, level+1);
		}
};

int main(){
	return 0;
}
