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
	public boolean wordBreak(String s, List<String> dic){
		int i,j,n, k;

		n=s.length();
		ind []dd=new int[n+1];
		Arrays.fill(dd,0);

		for (i=0;i<dic.size();i++){
			for (j=dic[i].length();j<n;j++){
				for (k=dd[j-dic[i].length];k<j;k++){
					if (s[k]!=)
				}
			}
		}
	}
}
