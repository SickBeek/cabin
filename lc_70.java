import java.util.ArrayList;
import java.util.Arrays;

public class Main{
	public static void main (String[]args){
		var sol=new Solution();
		return;
	}
}

class Solution{
    public int climbStairs(int n){
        int i, j;
        int dd[]=new int[n+1];

        dd[0]=dd[1]=1;
        for (i=1;i<=n;i++){
            for (j=1;j<=2;j++){
                if (i-j>=0){
                    dd[i]+=dd[i-j];
                }
             }
        }
        return dd[n];
    }
}