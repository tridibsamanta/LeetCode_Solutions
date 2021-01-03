/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 485. Max Consecutive Ones
~ Link      : https://leetcode.com/problems/max-consecutive-ones/
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int cnt = 0, curr_cnt = 0;

        for (int i = 0; i < nums.size(); ++i) {

            if (nums[i] == 1) {
                ++curr_cnt;
                cnt = max(cnt, curr_cnt);
            }
            else {
                curr_cnt = 0;
            }
        }

        return cnt;
    }
};

/*
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int cnt = 0, curr_cnt = 0;

        for (int i = 0; i < nums.size(); ++i) {
            curr_cnt = (curr_cnt + nums[i]) * nums[i];
            cnt = max(cnt, curr_cnt);
        }

        return cnt;
    }
};
*/
