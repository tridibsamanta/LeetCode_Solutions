/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 134. Gas Station
~ Link      : https://leetcode.com/problems/gas-station/
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int startIdx = 0, currTankCapacity = 0, sum = 0;

        for (int i = 0; i < gas.size(); ++i) {
            currTankCapacity += gas[i] - cost[i];

            if (currTankCapacity < 0) {
                startIdx = i + 1;
                sum += currTankCapacity;
                currTankCapacity = 0;
            }
        }

        sum += currTankCapacity;

        return (sum < 0 ? -1 : startIdx);
    }
};

// T.C. - O(n)
// S.C. - O(1)
