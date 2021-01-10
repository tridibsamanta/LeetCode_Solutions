/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 239. Sliding Window Maximum
~ Link      : https://leetcode.com/problems/sliding-window-maximum/
*/

// Approach 1: (Using deque)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        if (k == 1)
            return nums;

        vector<int> res;

        deque<int> dq;

        int n = nums.size(), i = 0, j = 0;

        while (j < n) {

            while (!dq.empty() && (dq.back() < nums[j]))
                dq.pop_back();

            dq.push_back(nums[j]);

            if (j - i + 1 < k) {
                ++j;
            }
            else if (j - i + 1 == k) {

                res.emplace_back(dq.front());

                if (dq.front() == nums[i]) {
                    dq.pop_front();
                }

                ++i;
                ++j;
            }
        }

        return res;
    }
};

// Approach 2: (Using multiset)

/*
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> res;

        multiset<int, greater<int> > mst;

        int n = nums.size(), i = 0, j = 0;

        while (j < n) {

            mst.insert(nums[j]);

            if (j - i + 1 < k) {
                ++j;
            }
            else if (j - i + 1 == k) {

                res.emplace_back(*(mst.begin()));

                mst.erase(mst.find(nums[i]));

                ++i;
                ++j;
            }
        }

        return res;
    }
};
*/
