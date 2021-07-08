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
		TreeNode* invert_visit(TreeNode* root){
			if (root==nullptr){
				return root;
			}

			stack<TreeNode*> st;
			TreeNode* node;

			st.push(root);
			while (!st.empty()){
				node=st.top();
				if (node!=nullptr){
					st.pop();
					if (node->right) st.push(node->right);
					if (node->left) st.push(node->left);
					st.push(node);
					st.push(nullptr);
				}else {
					st.pop();
					swap(node->left, node->right);
					st.pop();
				}
			}
			return root;
		}

		TreeNode* invert_recursive(TreeNode* root){
			if (!root) return root;

			stack<TreeNode*> st;
			TreeNode* node;

			st.push(root);
			while (!st.empty()){
				node=st.top();
				st.pop();
				swap(node->left, node->right);   //mid
				if (node->right) st.push(node->right);
				if (node->left) st.push(node->left); //left
			}
			return root;
		}

};

int main(){
	return 0;
}
