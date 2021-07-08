import java.util.List;
import java.util.ArrayList;

class Solution{
	public boolean isBalanced(TreeNode root){
		if (height(root) == -1)
			return false;
		return true;
	}

	public int height(TreeNode root){
		if (root==null) return 0;

		int left=height(root.left);
		if (left==-1) return -1;

		int right=height(root.right);
		if (right==-1) return -1;

		if (Math.abs(left-right)>1)
			return -1;
		return Math.max(left, right)+1;
	}
}

public class Main{
	public static void main(String[] args){
		TreeNode root=null;
		var m=new Solution();
		m.isBalanced(root);
	}
}

class TreeNode{
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(){}
	TreeNode(int val){ this.val=val;}

	TreeNode(int val, TreeNode left, TreeNode right){
		this.val=val;
		this.left=left;
		this.right=right;
	}
}
