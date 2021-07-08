#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
};

class Solution{
	private:
		void pre_order(TreeNode* root, vector<int>& path, vector<string>& result){
			path.push_back(root->val);

			if (!root->left && !root->right){  // leaf node
				string path_str;
				for (auto it=0;it<path.size()-1;it++){
					path_str+=to_string(path[it]);
					path_str+="->";
				}
				path_str+=to_string(path[path.size()-1]);
				result.push_back(path_str);
				return;
			}
			
			if (root->left) {
				pre_order(root->left, path, result);
				path.pop_back();
			}

			if (root->right) {
				pre_order(root->right, path, result);
				path.pop_back();
			}
		}

		void pre_order_2(TreeNode *root, string path, vector<string> &result){
			path+=to_string(root->val);
			if (!root->left && !root->right){
				result.push_back(path);
				return ;
			}
			if (root->left) pre_order_2(root->left, path+"->", result);
			if (root->right) pre_order_2(root->right, path+"->", result);
		}

	public:
		vector <string> binaryTree_path(TreeNode* root){
			vector<string> res;
			vector<int> path;
			string store;

			pre_order(root, store, res);
			return res;
		}
};

int main (){
	return 0;
}
