/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 525. Contiguous Array
~ Link      : https://leetcode.com/problems/contiguous-array/
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLen = 0, cnt = 0;

        unordered_map<int, int> ump; // {count, first occurrence index}
        ump[0] = -1;

        for (int i = 0; i < nums.size(); ++i) {
            cnt += (nums[i] == 0 ? -1 : 1);

            if (ump.count(cnt))
                maxLen = max(maxLen, i - ump[cnt]);
            else
                ump[cnt] = i;
        }

        return maxLen;
    }
};

/*
 ~ Time Complexity - O(n)
 ~ Space Complexity - O(n)
*/
