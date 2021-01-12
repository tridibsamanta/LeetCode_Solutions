/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 532. K-diff Pairs in an Array
~ Link      : https://leetcode.com/problems/k-diff-pairs-in-an-array/
*/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {

        int n = nums.size(), cnt = 0;

        unordered_map<int, int> hm;

        for (auto i : nums) {
            ++hm[i];
        }

        for (auto i : hm) {
            if (k == 0) {
                if (i.second > 1)
                    ++cnt;
            }
            else if (hm.find(i.first + k) != hm.end()) {
                ++cnt;
            }
        }

        return cnt;
    }
};

/*
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        int cnt = 0;

        for (int i = 0; i < n - 1; ++i) {

            int l = i, r = n - 1;

            if (nums[r] - nums[l] < k) {
                    break;
            }

            while (l < r) {

                if (nums[r] - nums[l] == k) {
                    ++cnt;

                    while (i < n - 1 && (nums[i + 1] == nums[i]))
                        ++i;

                    break;
                }
                else if (nums[r] - nums[l] < k) {
                    break;
                }
                else {
                    --r;
                }
            }
        }

        return cnt;
    }
};
*/
