/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1. Two Sum
~ Link      : https://leetcode.com/problems/two-sum/
*/

import java.util.Scanner;

public class TwoSum_1 {

    public int[] twoSum(int[] nums, int target) {
        int len = nums.length;
        int [] result = new int[2];
        for(int i = 0; i < len-1; i++) {
            for(int j = i+1; j < len; j++) {
                if((nums[i]+nums[j])==target) {
                    result[0] = i;
                    result[1] = j;
                }
            }
        }
        return result;
    }

    public static void main(String[] args)
     {
         Scanner sc = new Scanner(System.in);
         int size = sc.nextInt();
         int [] data = new int[size];
         for(int i = 0; i < size; i++) {
            data[i] = sc.nextInt();
         }
         int target = sc.nextInt();
         TwoSum_1 o = new TwoSum_1();
         int [] res = new int[2];
         res = o.twoSum(data,target);
         for(int i = 0; i < 2; i++)
            System.out.print(res[i]+" ");
     }
}

// *** Alternative Solution ***

/*
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap();
        for(int i = 0; i < nums.length; i++){
            map.put(nums[i], i);
        }
        for(int i = 0; i < nums.length; i++)
        {
            int foo = target - nums[i];
            if(map.containsKey(foo) && map.get(foo) != i)
                return new int[] {i, map.get(foo)};
        }
        throw new IllegalArgumentException("No two sum solution");
    }
}
*/
