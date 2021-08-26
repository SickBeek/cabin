class Solution {
	public int[] nextGreater_brutal(int []n1, int[] n2){
		int i, j;
		int []res=new int[n1.length];

		i=j=0;
		for (;i<n1.length;i++){
			for (j=0; j<n2.length;j++){
				if (n2[j]==n1[i]){
					while (j<n2.length){
						j++;
						if (n2[j]>n1[i]){
							res[i]=n2[j];
							break;
						}
						if (j>=n2.length){
							res[i]=-1;
							break;
						}
					}
				}
			}
		}
		return res;
	}

	public int[] nextGreater_stack(int []n1, int[]n2){
		int i, j;
		int []res=new int[n1.length];

		HashMap<Integer, Integer> map=new HashMap<>();
		Stack<Integer> st=new Stack<>();

		for (i=0;i<n1.length;i++){
			if (!map.containsKey(n1[i])){
				map.put(n1[i], i);
			}
			res[i]=-1;
		}

		st.push(0);
		for (i=1;i<n2.length;i++){
			while (!st.empty() && n2[i] > n2[st.peek()]){
				if (map.containsKey(n2[st.peek()])){
					res[map.get(n2[st.peek()])]=n2[i];
				}
				st.pop();
			}
			st.push(i);
		}
		return res;
	}

	public int[] nextGreater_circular(int []nums){
		int i,j, n, count;
		n=nums.length;
		int []res=new int[n];

		for (i=0;i<n;i++){
			res[i]=-2;
		}

		if (n==1){
			return res;
		}

		Map<Integer, Integer> map=new HashMap<>();
		Stack<Integer> st=new Stack<>();
		
		st.push(0);
		i=1; count=0;
		/*
		while (count<=n){
			while (!st.empty()){
				if (nums[st.peek()]<nums[i]){
					res[st.pop()]=nums[i];
					count++;
				}
				if (st.peek()==i){
					res[i]=-1;
					count++;
				}
			}
			if (res[i]==-2){
				st.push(i);
			}
			i++;
			i%=n;
		}
		*/

		for (i=1;i<n;i++){
			while (!st.empty()){
				if (nums[st.peek()]<nums[i]){
					res[st.pop()]=nums[i];
					count++;
				}
			}
			st.push(i);
		}

		for (i=0;i<n;i++){
			while (!st.empty()){
				if (nums[st.peek()]<nums[i]){
					res[st.pop()]=nums[i];
					count++;
				}

				if (st.peek()==i){
					res[i]=-1;
					count++;
				}
			}
			if (count==n){
				break;
			}

			if (res[i]==-2){
				st.push(i);
			}
		}
		return res;
	}
}

