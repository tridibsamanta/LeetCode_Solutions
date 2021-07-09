/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1710. Maximum Units on a Truck
~ Link      : https://leetcode.com/problems/maximum-units-on-a-truck/
*/

// Approach 1
/*
class Solution {
public:
    static bool desc_second(vector<int> box1, vector<int> box2) {
        return box1[1] > box2[1];
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {

        sort(boxTypes.begin(), boxTypes.end(), desc_second);

        int totalUnits = 0;

        for (int i = 0; i < boxTypes.size(); ++i) {
            if (boxTypes[i][0] >= truckSize) {
                totalUnits += (truckSize * boxTypes[i][1]);
                break;
            }
            else {
                totalUnits += (boxTypes[i][0] * boxTypes[i][1]);
                truckSize -= boxTypes[i][0];
            }
        }

        return totalUnits;
    }
};
*/
// T.C. - O(n * log n)
// S.C. - O(1)

// Approach 2

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {

        int bucket[1001];
        memset(bucket, 0, sizeof(bucket));

        for (int i = 0; i < boxTypes.size(); ++i) {
            bucket[boxTypes[i][1]] += boxTypes[i][0];
        }

        int totalUnits = 0;

        for (int i = 1000; i >= 1; --i) {
            if (bucket[i] >= truckSize) {
                totalUnits += truckSize * i;
                break;
            }
            else {
                totalUnits += bucket[i] * i;
                truckSize -= bucket[i];
            }
        }

        return totalUnits;
    }
};

// T.C. - O(n)
// S.C. - O(n)
