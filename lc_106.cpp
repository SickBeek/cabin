#include <vector>
#include <stack>
#include <utility>
#include <unordered_map>
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
	public:
		TreeNode* build_trees_traverse(vector<int> &in, vector<int> post){
			if (post.size()) return nullptr;

			int root_val=post[post.size()-1];
			TreeNode* root=new TreeNode(root_val);
			if (post.size()==1) return root;

			int split;
			for (split=0;split<in.size();split++){
				if (in[split]==root_val) break;
			}
			//split in_order vector
			vector<int> left_in(in.begin(),  in.begin()+split);
			vector<int> right_in(in.begin()+split+1, in.end());

			//delete the last node, which is root for in_order
			post.resize(post.size()-1);
			vector<int> left_post(post.begin(), post.begin()+left_in.size());
			vector<int> right_post(post.begin()+left_in.size(), post.end());

			root->left=build_trees_traverse(left_in, left_post);
			root->right=build_trees_traverse(right_in, right_post);

			return root;
		}

		TreeNode* build_trees_traverse_index(vector<int> &in, int in_begin, int in_end, vector<int> post, int post_begin, int post_end){
			if (post_begin==post_end) return nullptr;

			int root_val=post[post_end-1];
			TreeNode* root=new TreeNode(root_val);
			if (post_end-post_begin==1) return root;

			int split;
			for (split=in_begin;split<in_end;split++){
				if (in[split]==root_val) break;
			}
			//left inorder
			int left_in_begin=in_begin;
			int left_in_end=split;

			int right_in_begin=split+1;
			int right_in_end=in_end;

			//delete the last node, which is root for in_order
			int left_post_begin=post_begin;
			int left_post_end=post_begin+ left_in_end-left_in_begin;

			int right_post_begin=left_post_end+1;
			int right_post_end=right_post_begin+ right_in_end-right_in_begin;

			root->left=build_trees_traverse_index(in, left_in_begin, left_in_end, post, left_post_begin, left_post_end);
			root->right=build_trees_traverse_index(in, right_in_begin, right_in_end, post, right_post_begin, right_post_end);
			return root;
		}

		int post_index=0;
		TreeNode* build_trees_map(vector<int>& in, vector<int> &post){
			if (in.empty() || post.empty()) return nullptr;
			unordered_map<int, int> in_index;

			//<in.value, in.index>
			for (int i=0;i<in.size();i++){
				in_index[in[i]]=i;
			}

			//last node-> root
			post_index=post.size()-1;
			return make_tree(post, in_index, 0, in.size()-1);
		}

		TreeNode* make_tree(vector<int>& post, unordered_map<int, int>& in_index, int in_start, int in_end){
			if (post_index<0 || in_start>in_end){
				return nullptr;
			}

			//data=root->val
			int data=post[post_index--];
			auto root=new TreeNode(data);

			//post order: LRM, right node become root first
			root->right=make_tree(post, in_index, in_index[data]+1, in_end);
			root->left=make_tree(post, in_index, in_start, in_index[data]-1);
			return root;
		}

};

int main (){
	return 0;
}
