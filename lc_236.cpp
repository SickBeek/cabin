#include <iostream>
#include <stack>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
};

class Solution{
	public:
		TreeNode* (TreeNode* cur, TreeNode* p, TreeNode* q){
			if (!cur || cur==p || cur==q){
				return cur;
			}

			TreeNode* left=traverse(cur->left, p, q);
			TreeNode* right=traverse(cur->right, p, q);

			if (left && right) return cur;
			if (!left || right) return right;
			return left; //include case: (!left && !right)
		}
};

int main (){
	return 0;
}
