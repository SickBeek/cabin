#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
};

class Solution{
	public:
		TreeNode* delete_node(TreeNode* root, int target){
			if (!root) return nullptr;

			if (root->val== target){
				if (!root->left) return root->right;  //!left || !left && !right
				else if (!root->right) return root->left;  // !right
				else {
					TreeNode* cur=root->right;
					while (cur->left){
						cur=cur->left;  //left most node of the right subtree
					}

					cur->left=root->left;
					TreeNode* tmp=root;
					root=root->right;
					delete tmp;
					return root;
				}
			}

			if (root->val > target) root->left=delete_node(root->left, target);
			if (root->val > target) root->right=delete_node(root->right, target);
			return root;
		}

		TreeNode* delete_node_iter(TreeNode* root, int target){
			if (!root) return nullptr;

			TreeNode* cur, *pre;

			cur=root;
			pre=nullptr;
			while (cur){
				pre=cur;
				if (cur->val==target){
					pre=cur;
					break;
				}else if (target < cur->val){
					cur=cur->left;
				}else {
					cur=cur->right;
				}
			}

			if (!pre){
				return root;
			}else {
				if (!cur->left){
					pre->right=cur->right;
					delete cur;
				}else if(!cur->right) {
					pre->left=cur->left;
					delete cur;
				}else {
					TreeNode* del=cur->right;
					while (del->left){
						del=del->left;
					}
					del->left=cur->left;
					pre->right=cur->right;
					delete cur;
				}
			}
			return root;
		}
};

int main (){
	return 0;
}
