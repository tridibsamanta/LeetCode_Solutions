/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 45. Jump Game II
~ Link      : https://leetcode.com/problems/jump-game-ii/
*/

/*
class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return 0;

        int dp[n];
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < n; ++i) {

            int jumps = nums[i], pos = i + 1;

            while (jumps-- && pos < n) {

                if (dp[pos] == 0)
                    dp[pos] = dp[i] + 1;

                if (pos == n-1)
                    return dp[n-1];

                ++pos;
            }
        }

        return dp[n-1];
    }
};
*/

// T.C. - O(n^2)
// S.C. - O(n)

class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return 0;

        int jumps = 0, currReach = 0, maxReach = 0;

        for (int i = 0; i < n - 1; ++i) {

            maxReach = max(maxReach, i + nums[i]);

            if (i == currReach) {
                ++jumps;
                currReach = maxReach;

                if (maxReach >= n - 1)
                    break;
            }
        }

        return jumps;
    }
};

// T.C. - O(n)
// S.C. - O(1)
