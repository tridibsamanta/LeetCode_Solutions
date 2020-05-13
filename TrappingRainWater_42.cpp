/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 42. Trapping Rain Water
~ Link      : https://leetcode.com/problems/trapping-rain-water/
*/

// *** Approach 1 : Using dynamic programming ***

/*
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0 || height.size() == 1)
		    return 0;
        int res = 0;
        int len = height.size();
        vector<int> leftMax(len), rightMax(len);
        leftMax[0] = height[0];
        for (int i = 1; i < len; ++i)
            leftMax[i] = max(leftMax[i - 1], height[i]);
        rightMax[len -1] = height[len - 1];
        for (int i = len - 2; i >= 0; --i)
            rightMax[i] = max(rightMax[i + 1], height[i]);
        for (int i = 0; i < len; ++i)
            res += min(leftMax[i], rightMax[i]) - height[i];
        return res;
    }
};
*/

// *** Approach 2 : Using two pointers ***

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0 || height.size() == 1)
		    return 0;
        int leftPtr = 0, rightPtr = height.size() - 1, leftMax = 0, rightMax = 0, res = 0;
        while (leftPtr < rightPtr) {
            if (height[leftPtr] < height[rightPtr]) {
                if (height[leftPtr] >= leftMax)
                    leftMax = height[leftPtr];
                else
                    res += leftMax - height[leftPtr];
                ++leftPtr;
            }
            else {
                if (height[rightPtr] >= rightMax)
                    rightMax = height[rightPtr];
                else
                    res += rightMax - height[rightPtr];
                --rightPtr;
            }
        }
        return res;
    }
};
