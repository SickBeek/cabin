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
		vector<int> result;
		TreeNode* pre=nullptr;
		int count=0;
		int max_count=0;

	public:
		int findMode(TreeNode* root){
			in_traverse(root);
			return result;
		}

		void in_traverse(TreeNode* root){
			if (!root) return;

			in_traverse(root->left);
			if (!pre){
				count=1;
			}else{
				if (pre->val==root->val){
					count++;
				}else{
					count=1;
				}
			}
			pre=root;

			if (count>=max_count){
				max_count=count;
				result.clear();
				result.push_back(root->val);
			}
			in_traverse(root->right);
		}
};

int main (){
	return 0;
}
