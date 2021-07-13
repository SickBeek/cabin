public class Main {
    public static void main(String []args){
        return 0;
    }
}

class Solution {
    public int findPeak(int []nums){
        if (nums.length==1){ return 0; }

        if (nums.length==2){
            if (nums[0]>=nums[1])
                return 0;
            return 1;
        }

        int l, r, max_peak, max_idx, n;

        n=nums.length;
        if (nums[0]>=nums[n-1]){
            max_peak=nums[0];
            max_idx=0;
        }else {
            max_peak=nums[n-1];
            max_idx=n-1;
        }

        l=1; r=n-2;
        while (l<=r){
            if (nums[l-1]<=nums[l] && nums[l]>=nums[l+1]){  //is peak
                if (nums[l]>=max_peak){
                    max_peak=nums[l];
                    max_idx=l;
                }
                l++; l++;
            }else {
                l++;
            }

            if (nums[r-1]<=nums[r] && nums[r]>=nums[r+1]){  //is peak
                if (nums[r]>=max_peak){
                    max_peak=nums[r];
                    max_idx=r;
                }
                r--; r--;
            }else {
                r--;
            }
        }
        return max_idx;
    }
}



