import java.util.ArrayList;
import java.util.List;
class Solution {
	//List<List<Integer>> res=new ArrayList<>();

	protected List<List<Integer>> res=new ArrayList<>();
	protected List<Integer> path=new ArrayList<>();
	int count=0;

	public List<List<Integer>> combination(int[]nums){
		combine(nums, 0);
		count=0;
		return res;
	}

	public void combine(int[]nums, int idx){
		if (path.size()==3){
			if (isTri(path.get(0), path.get(1), path.get(2))){
				count++;
			}
			return ;
		}

		for (int i=idx;i<nums.length;i++){
			path.add(nums[i]);
			combine(nums, i+1);
			path.remove(path.size()-1);
		}
	}
	
	public boolean isTri(int a, int b, int c){
		if (a+b<c) return false;
		if (a+c<b) return false;
		if (b+c<a) return false;
		return true;
	}

	public triangleNumber(int[] nu){
		Arrays.sort(nu);

		int cnt=0, n=nu.length;
		int l=0, r;

		for (int i=n-1;i>=2;i--){
			l=0; r=i-1;
			while (l<r){
				if (nu[l] + nu[r] > nu[i]){
					cnt+=r-l;
					r--;
				}else {
					l++;
				}
			}
		}
		return cnt;
	}
}

