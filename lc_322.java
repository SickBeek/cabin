class Solution{
    public int climbStairs(int []coins, int amount){
            int i, j;
            int dd[]=new int[amount+1];

            for (i=0;i<=amount;i++){
                dd[i]=Integer.MAX_VALUE;
            }

            dd[0]=0;
            for (i=0;i<coins.length;i++){
                for (j=coins[i];j<=amount;j++){
                    dd[j]=Math.min(dd[j], dd[j-coins[i]]+1);
                }
            }
            return dd[amount];
        }
}