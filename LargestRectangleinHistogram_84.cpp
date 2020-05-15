/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 84. Largest Rectangle in Histogram
~ Link      : https://leetcode.com/problems/largest-rectangle-in-histogram/
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> S;
        int n = heights.size(), i = 0, currArea = 0, maxArea = 0, tp = -1;
        while (i < n) {
            if (S.empty() || heights[i] >= heights[S.top()])
                S.push(i++);
            else {
                tp = S.top(); S.pop();
                currArea = heights[tp] * (S.empty() ? i : (i - 1 - S.top()));
                if (currArea > maxArea)
                    maxArea = currArea;
            }
        }

        while (!S.empty()) {
            tp = S.top(); S.pop();
            currArea = heights[tp] * (S.empty() ? i : (i - 1 - S.top()));
            if (currArea > maxArea)
                maxArea = currArea;
        }
        return maxArea;
    }
};
