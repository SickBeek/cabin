#include <iostream>
#include <assert.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;

#define Element int

struct TreeNode{
	Element val;
	TreeNode* left;
	TreeNode* right;
	TreeNode (Element v): val(v), left(nullptr), right(nullptr){}
};

class Tree{
	private:
		TreeNode *root;
	public:
		void traverse_pre(TreeNode * ro, vector<int> &vec){
			if (ro==nullptr)
				return;
			vec.push_back(ro->val);
			traverse_pre(ro->left, vec);
			traverse_pre(ro->right, vec);
		}

		vector<int> traverse_pre_stack(TreeNode* root){
			stack<TreeNode*> st;
			vector<int> result;
			TreeNode *node;

			if (root==nullptr)
				return result;

			while (!st.empty()){
				node=st.top();
				st.pop();
				result.push_back(node->val);
				if (node->right!=nullptr) st.push(node->right);
				if (node->left!=nullptr) st.push(node->left);
			}
			return result;
		}

		vector<int> traverse_in_stack(TreeNode* root){
			stack<TreeNode*> st;
			vector<int> result;
			TreeNode *node=root;

			while (node != nullptr || !st.empty()){
				if (node!=nullptr){    //get the left most node
					st.push(node);
					node=node->left;
				}else {
					node=st.top(); st.pop();
					result.push_back(node->val);  //mid node
					node=node->right;			//right node
				}
			}
			return result;
		}

		vector<int> traverse_post_stack(TreeNode* root){
			vector<int> result;
			TreeNode* node;
			stack<TreeNode*> st;

			if (root==nullptr) return result;
			st.push(root);
			while (!st.empty()){
				node=st.top(); st.pop();
				if (node->left!=nullptr) st.push(node->left);
				if (node->right!=nullptr) st.push(node->right);
			}
			reverse(result.begin(), result.end());
			return result;
		}

		/*
		vector<int>  traverse_post_stack_N-tree(TreeNode* root){
			vector<int> result;
			stack<TreeNode *> st;
			TreeNode* node;

			if (root==nullptr)
				return result;

			st.push(root);
			while (!st.empty()){
				node=st.top(); st.pop();
				result.push_back();
				for (auto c: root->children){
					st.push(c);
				}
			}
			reverse(result.begin(), result.end());
			return result;
		}
		*/

		vector<int> traverse_in_visit(TreeNode *root){
			vector<int> result;
			stack<TreeNode*> st;
			TreeNode *node;

			if (root==nullptr)
				return result;

			st.push(root);
			while (!st.empty()){
				node=st.top();
				if (node!=nullptr){
					st.pop();
					if (node->right!=nullptr){
						st.push(node->right);    //add right node
					}

					st.push(node);   //add mid node
					st.push(nullptr);
					
					if (node->left!=nullptr) st.push(node->left);
				}else{
					st.pop(); //pop nullptr mark
					node=st.top();
					st.pop();
					result.push_back(node->val);
				}
			}
			return result;
		}

		vector<vector<int>> traverse_level_order(TreeNode *root){
			vector<vector<int>> result;

			if (root==nullptr)
				return result;

			queue<TreeNode*> st;
			TreeNode* node;
			queue<TreeNode*>::size_type size=0;

			st.push(root);
			while (!st.empty()){
				vector<int> level;
				size=st.size();
				for (int i=0;i<size;i++){
					node=st.front();
					level.push_back(node->val);
					if (node->left!=nullptr) st.push(node->left);
					if (node->right!=nullptr) st.push(node->right);
					st.pop();
				}
				result.push_back(level);
			}
			return result;
		}

};

int main (){
	return 0;
}
