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
		bool symmetric(TreeNode* root){
			if (!root) return true;
			return compare(root->left, root->right);
		}

		bool compare(TreeNode* left, TreeNode* right){
			if (left==nullptr && right!=nullptr) return true;
			if (!left || !right || left->val!=right->val) return false;
			return compare(left->left, right->right) && compare(left->right, right->left);
		}

		bool symmetric_stack(TreeNode* root){
			if (!root) return true;

			stack<TreeNode*> st;
			TreeNode* left, *right;

			st.push(root->left);
			st.push(root->right);
			while (!st.empty()){
				left=st.top(); st.pop();
				right=st.top(); st.pop();

				if (!left && !right) continue;
				if (!left || !right || left->val!=right->val) return false;
				st.push(left->left);
				st.push(right->right);
				st.push(left->right);
				st.push(right->left);
			}
			return true;
		}
};

int main(){
	return 0;
}
