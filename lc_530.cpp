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
	private:
		int result;
		TreeNode* pre=nullptr;

	public:
		int min_diff(TreeNode* root){
			in_traverse(root);
			return result;
		}

		void in_traverse(TreeNode* root){
			if (!root) return;
			in_traverse(root->left);
			if (pre!=nullptr){
				result=min(result, abs(root->val - pre->val));
			}
			pre=root;
			in_traverse(root->right);
		}
};

int main (){
	return 0;
}
