#include<iostream>
#include<stack>
using namespace std;

class Solution{
	private:
	public:
		vector<TreeNode*> in_order;
		bool isValidBST(TreeNode* root){
			if (in_order.size()<=1) return true;

			for (int i=1; i<in_order.size();i++){
				if (in_order[i-1] >= in_order[i]) return false;
			}
			return true;
		}

		void in_traverse(TreeNode* root){
			if (!root->left && !root->right) return;
			in_traverse(root->left);
			in_order.push_back(root->val);
			in_traverse(root->right);
		}
};

