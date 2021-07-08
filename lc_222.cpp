#include <iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
};

class Solution {
	public:
		int countNodes(TreeNode* root){
			if (!root) return 0;

			TreeNode* left=root->left;
			TreeNode* right=root->right;
			int left_height, right_height;

			left_height=right_height=0;

			while (left){
				left_height++;
				left=left->left;
			}

			while (right){
				right_height++;
				right=right->right;
			}

			if (left_height==right_height){
				return (2<< left_height)-1;
			}
			return 1+countNodes(root->left)+countNodes(root->right);
		}
};

int main (){
	return 0;
}
