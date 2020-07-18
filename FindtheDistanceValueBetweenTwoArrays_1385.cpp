/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 1385. Find the Distance Value Between Two Arrays
~ Link      : https://leetcode.com/problems/find-the-distance-value-between-two-arrays/
*/

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res = 0;
        for (int i = 0; i < arr1.size(); ++i) {
            int count = 0;
            for (int j = 0; j < arr2.size(); ++j) {
                if (abs(arr1[i] - arr2[j]) > d)
                    ++count;
                else
                    break;
            }
            if (count == arr2.size())
                ++res;
        }
        return res;
    }
};
