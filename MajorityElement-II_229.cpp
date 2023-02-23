/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 140. Word Break II
~ Link      : https://leetcode.com/problems/majority-element-ii/
*/

/*
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (auto val : nums) {
            ++freq[val];
        }

        vector<int> res;

        for (auto p : freq) {
            if (p.second > (nums.size() / 3))
                res.emplace_back(p.first);
        }

        return res;
    }
};
*/
// Time Complexity - O(n)
// Auxiliary Space - O(n)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majority1 = -1, majority2 = -1, count1 = 0, count2 = 0;

        for (int i = 0; i < n; ++i) {
            if (majority1 == nums[i]) {
                ++count1;
            }
            else if (majority2 == nums[i]) {
                ++count2;
            }
            else if (count1 == 0) {
                majority1 = nums[i];
                ++count1;
            }
            else if (count2 == 0) {
                majority2 = nums[i];
                ++count2;
            }
            else {
                --count1;
                --count2;
            }
        }

        count1 = count2 = 0;

        for (int i = 0; i < n; ++i) {
            if (majority1 == nums[i])
                ++count1;
            else if (majority2 == nums[i])
                ++count2;
        }

        vector<int> res;

        if (count1 > n / 3)
            res.emplace_back(majority1);
        if (count2 > n / 3)
            res.emplace_back(majority2);

        return res;
    }
};

// Time Complexity - O(n)
// Auxiliary Space - O(1)
