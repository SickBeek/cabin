#include <iostream>
#include <assert.h>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode (int ele):val(ele){}
};

class Solution {
	public:
		int result;
		void getDepth(TreeNode* root, int depth){
			result=max(result, depth);   //mid node
			if (!root) return;

			if (!root->left && !root->right) return;  //end criterion

			if (root->left){
				depth++;
				getDepth(root->left, depth);
				depth--;
			}

			//if (root->left) getDepth(root->left);
			//if (root->right) getDepth(root->right);
			
			if (root->right){
				depth++;
				getDepth(root->right, depth);
				depth--;
			}
			return;
		}

		int maxDepth(TreeNode* root){
			result=0;
			if (!root) return result;
			getDepth(root, 1);
			return result;
		}

		int getDepth_balance(TreeNode* root){
			if (!root) return 0;

			int depth_left=getDepth_balance(root->left);
			if (depth_left==-1) return -1;

			int depth_right=getDepth_balance(root->right);
			if (depth_right==-1) return -1;

			//return abs(depth_left -depth_right)>1?-1:max(depth_left, depth_right);
			if (abs(depth_left -depth_right)>1)
				return -1;
			return max(depth_left, depth_right)+1;
		}

		int depth_post(TreeNode* root){
			if (!root) return 0;
			return 1+max(depth_post(root->left), depth_post(root->right));
		}

		bool isBalanced_depth_post(TreeNode* root){
			if (!root) return false;
			int left=depth_post(root->left);
			int right=depth_post(root->right);

			return abs(left-right)<=1 &&
				isBalanced_depth_post(root->left) &&
				isBalanced_depth_post(root->right);
		}

		int get_depth_for_height(TreeNode *cur){
			if (!cur) return 0;

			stack<TreeNode*> st;
			TreeNode* node;
			int depth, result;

			depth=result=0;
			st.push(cur);
			while (!st.empty()){
				node=st.top();
				if (node!=nullptr){
					st.pop();
					st.push(node);
					st.push(nullptr);
					depth++;
					if (node->right) st.push(node->right); //right pop later
					if (node->left) st.push(node->left);  //left pop earlier
				}else {
					st.pop();
					node=st.top();
					depth--;
					st.pop();
				}
				result=max(result, depth);
			}
			return result;
		}

		bool isBalanced(TreeNode* root){
			if (!root) return true;

			/*
			int left=get_depth_for_height(root->left);
			int right=get_depth_for_height(root->right);
			return abs(left-right)<=1 && isBalanced(root->left) && isBalanced(root->right);
			*/

			stack<TreeNode*> st;
			TreeNode* node;
			int left, right;

			st.push(root);
			while (!st.empty()){
				node=st.top(); st.pop();
				left=get_depth_for_height(root->left);
				right=get_depth_for_height(root->right);
				if (abs(left-right)>1) return false;

				if (node->right) st.push(node->right);
				if (node->left) st.push(node->left);
			}
		}
};

int main (){
	vector<int> tree={3,9,20,-1,-1,15,7};
	TreeNode* root=new TreeNode(tree[0]);
	TreeNode* ptr=nullptr;
	return 0;
}
