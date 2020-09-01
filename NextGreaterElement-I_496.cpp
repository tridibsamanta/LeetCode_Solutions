/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 496. Next Greater Element I
~ Link      : https://leetcode.com/problems/next-greater-element-i/
*/

/* Efficient Approach*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> nextGreater;
        stack<int> todo;

        for (int i = 0; i < nums2.size(); ++i) {
            int curr = nums2[i];
            while(!todo.empty() && todo.top() < curr) {
                nextGreater[todo.top()] = curr;
                todo.pop();
            }
            todo.push(curr);
        }

        for (int i = 0; i < nums1.size(); ++i) {
            if (nextGreater.count(nums1[i]))
                nums1[i] = nextGreater[nums1[i]];
            else
                nums1[i] = -1;
        }

        return nums1;
    }
};

// T.C.: O(max(nums1.size(), nums2.size())), S.C.: O(n)

/* Brute-force Approach*/
/*
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        for (int i = 0; i < nums1.size(); ++i) {

            bool located = false;
            int j;
            for (j = 0; j < nums2.size(); ++j) {
                if (nums2[j] == nums1[i]) {
                    located = true;
                }
                else if (nums2[j] > nums1[i] && located) {
                    nums1[i] = nums2[j];
                    break;
                }
            }
            if (j == nums2.size())
                nums1[i] = -1;
        }
        return nums1;
    }
};
*/
// T.C.: O(nums1.size() * nums2.size()), S.C.: O(1)
