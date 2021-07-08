#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
	private:
		vector<int> path;
		vector<vector<int>> result;

	public:
		bool has_path_sum(TreeNode* root, int target){
			if (!root) return false;
			if (!root->left &&!root->right && target==root->val) return true;

			return has_path_sum(root->left, target- root->val) || has_path_sum(root->right, target- root->val);
		}
		
		bool has_path_sum_stack(TreeNode* root, int target){
			if (!root) return false;

			stack<pair<TreeNode*, int>> st;
			pair<TreeNode*, int> node;
			int i, count;
			
			i=count=0;
			//st.push({root, target});
			st.push(pair<TreeNode*, int>(root, target));
			while (!st.empty()){
				node=st.top(); st.pop();
				if (!node.first->left &&!node.first->right && node.second==0) return true;
				if (node.first->left) st.push(pair<TreeNode*, int>(node.first->left, node.second-node.first->val));
				if (node.first->right) st.push(pair<TreeNode*, int>(node.first->right, node.second-node.first->val));
			}
			return false;
		}

		vector<vector<int>> all_path_sum_stack(TreeNode* root, int target){
			if (!root) return {};
			
			stack<pair<TreeNode*, int>> st;
			pair<TreeNode*, int> node;
			vector<int> path;
			vector<vector<int>> result;

			st.push(pair<TreeNode*, int>(root, root->val));
			while (!st.empty()){
				node=st.top(); st.pop();
				path.push_back(node.first->val);

				if (!node.first->left && !node.first->right && node.first->val==target){
					result.push_back(path);
					path.pop_back();  //backtracking
				}

				if (node.first->right) {
					st.push(pair<TreeNode*, int>(node.first->right, node.second+ node.first->right->val));
				}

				if (node.first->left) {
					st.push(pair<TreeNode*, int>(node.first->left, node.second+ node.first->left->val));
					path.push_back(node.first->left->val);
				}
			}
			return result;
		}

		vector<vector<int>> all_path_sum(TreeNode* root, int target){
			path.clear(); result.clear();
			if (!root) return {};

			path.push_back(root->val);
			all_path_recursive(root, target - root->val);
			return result;
		}

		void all_path_recursive(TreeNode* root, int count){
			if (!root->left && !root->right){
				if (count==0){  //right path
					result.push_back(path);
				}
				return;  //not right path
			}

			if (root->left){   //nullptr not included
				path.push_back(root->left->val);
				all_path_recursive(root->left, count - root->left->val);
				path.pop_back();
			}

			if (root->right){   //nullptr not included
				path.push_back(root->right->val);
				all_path_recursive(root->right, count - root->right->val);
				path.pop_back();
			}
		}

};

int main(){
	return 0;
}

