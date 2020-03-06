/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 198. House Robber
~ Link      : https://leetcode.com/problems/house-robber/
*/

import java.util.Scanner;

public class HouseRobber_198 {

    public int rob(int[] nums) {
        int length = nums.length;

        if(length == 0) return 0;
        if(length == 1) return nums[0];

        int dp[] = new int[length];

        dp[0] = nums[0];
        dp[1] = Math.max(nums[0],nums[1]);

        for(int i = 2; i < length; i++) {
            dp[i]=Math.max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp[length-1];
    }

    public static void main(String[] args)
     {
         Scanner sc = new Scanner(System.in);
         int size = sc.nextInt();
         int [] data = new int[size];
         for(int i = 0; i < size; i++) {
            data[i] = sc.nextInt();
         }
         HouseRobber_198 o = new HouseRobber_198();
         System.out.print(o.rob(data));
     }
}
