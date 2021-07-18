class Solution {
	public List<List<Integer>> fourSum(int []nums, int target){
		int i,j ,left, right, sum, n;
		List<List<Integer>> res=new ArrayList<>();

		Arrays.sort(nums);
		n=nums.length;
		for (i=0;i<=n-4;i++){
			while (i<n-1 && nums[i]==nums[i+1]){
				i++;
			}
			for (j=i+1;j<=n-3;j++){
				while (j<n-1 && nums[j]==nums[j+1]){
					j++;
				}
				left=j+1; right=n-1;
				while (left<right){
					sum =nums[i]+nums[j]+nums[left]+nums[right];
					if (sum>target){
						right--;
					}else if (sum<target){
						left++;
					}else {
						res.add(Arrays.asList(nums[i], nums[j], nums[left], nums[right]));
						while (right > left && nums[right]==nums[right-1]) right--;
						while (right > left && nums[left]==nums[left+1]) left++;

						right--; left++;
					}
				}
			}
		}
		return res;
	}
}

