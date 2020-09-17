/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 167. Two Sum II - Input array is sorted
~ Link      : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        vector<int> res;

        int n = numbers.size();

        int l = 0, r = n - 1;

        while (l < r) {

            if (numbers[l] + numbers[r] == target) {
                res.emplace_back(l + 1);
                res.emplace_back(r + 1);
                break;
            }

            int l_val = numbers[l], r_val = numbers[r];

            if (numbers[l] + numbers[r] < target) {
                // Skipping the duplicates
                while (l < r && numbers[l] == l_val)
                    ++l;
            }
            else {
                // Skipping the duplicates
                while (l < r && numbers[r] == r_val)
                    --r;
            }
        }

        return res;
    }
};
