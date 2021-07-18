import java.util.Stack;
import java.util.Arrays;

public class Main {
	public static void main (String []args){
		var sol=new Solution();
		int []nums={71,18,52,29,55,73,24,42,66,8,80,2};

		int res[]=sol.mostCompetitive(nums, 3);
		System.out.println(Arrays.toString(res));
	}
}

class Solution{
    public bool isPerfectSquare(int num){
		int i;

		if (num==1 || num== 4){ return num;}

		for (i=3;i<n/2;i++){
			if (i*i==num){
				return true;
			}else if (i*i>num){
				return false;
			}
		}
		return false;
	}

	bool isPerfect_BS(int num){
		if (num==1 || num== 4 || num==9){ return num;}

		int left, right, mid;
		long temp;

		left=3;
		right=num/2;

		while (left<=right){
			mid=(right-left)/2+right;
			temp=(long)mid*mid;
			if (temp==num){
				return true;
			}else if (temp<num){
				left=mid+1;
			}else{
				right=mid-1;
			}
		}
		return false;
	}
}

