import java.util.Stack;
import java.util.Arrays;

public class Main {
	public static void main (String []args){
		var sol=new Solution();
		int []nums={71,18,52,29,55,73,24,42,66,8,80,2};

		int res[]=sol.mostCompetitive(nums, 3);
		//System.out.println(Arrays.deepToString(res));
		System.out.println(Arrays.toString(res));
	}
}

class Solution{
    public int [] mostCompetitive(int[] nums, int k){
        var st=new Stack<Integer>();
        int []result=new int [k];
        int i,j, n;

        n=nums.length;
        for (i=0;i<n;i++){
            while (!st.empty() && st.peek()>nums[i] && n-i +st.size()>k){ //cant pop while left+st.size() is k
                st.pop();
            }

            if (st.size()<k){
                st.push(nums[i]);
            }
        }

        for (i=k-1;i>=0;i--){
            result[i]=st.pop();
        }
        return result;
    }

    public int [] mostCompetitive_array(int[] nums, int k){
        int []res=new int [k];
        int i,j, n;

		n=nums.length;
		j=0;
		for (i=0;i<n;i++){
			while (j>0 && res[j]>nums[i] && j+n-i>k){
				//res[j]=nums[i];
				j--;
			}
			if (j<k){
				res[j++]=nums[i];
			}
		}
		return res;
	}
}

