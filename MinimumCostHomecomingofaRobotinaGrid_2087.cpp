/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 2087. Minimum Cost Homecoming of a Robot in a Grid
~ Link      : https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/
*/

class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int cost = 0;

        // Robot is initially located at its home cell
        if (startPos[0] == homePos[0] && startPos[1] == homePos[1]) {
            return cost;
        }

        // Move Down
        if (startPos[0] < homePos[0]) {
            for (int i = startPos[0] + 1; i <= homePos[0]; ++i) {
                cost += rowCosts[i];
            }
        }
        // Move Up
        else if (startPos[0] > homePos[0]) {
            for (int i = startPos[0] - 1; i >= homePos[0]; --i) {
                cost += rowCosts[i];
            }
        }

        // Move Right
        if (startPos[1] < homePos[1]) {
            for (int i = startPos[1] + 1; i <= homePos[1]; ++i) {
                cost += colCosts[i];
            }
        }
        // Move Left
        else if (startPos[1] > homePos[1]) {
            for (int i = startPos[1] - 1; i >= homePos[1]; --i) {
                cost += colCosts[i];
            }
        }

        return cost;
    }
};

// Time Complexity - O(row + column)
// Auxiliary Space - O(1)
