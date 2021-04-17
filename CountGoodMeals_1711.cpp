/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1711. Count Good Meals
~ Link      : https://leetcode.com/problems/count-good-meals/
*/

class Solution {
public:
    #define MOD 1000000007

    int countPairs(vector<int>& deliciousness) {

        unordered_map<int, int> freq;

        int ans = 0;

        for (int i : deliciousness) {

            for (int pw = 1; pw <= (1 << 22); pw *= 2) {

                if (freq[pw - i])
                    ans = (ans + freq[pw - i]) % MOD;
            }

            ++freq[i];
        }

        return ans;
    }
};
