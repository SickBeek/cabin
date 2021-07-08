#include<iostream>
#include<stack>
using namespace std;

class Solution{
	private:
	public:
		TreeNode* merge_trees(TreeNode* t1, TreeNode* t2){
		}

		TreeNode* pre_order(TreeNode* t1, TreeNode* t2){
			if (!t1 && !t2) return nullptr;
			if (!t1) return t2;
			if (!t2) return t1;

			t1->val+=t2->val;
			t1->left=pre_order(t1->left, t2->left);
			t1->right=pre_order(t1->right, t2->right);
			return t1;
		}
};
