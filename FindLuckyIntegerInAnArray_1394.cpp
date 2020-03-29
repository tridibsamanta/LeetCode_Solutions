/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 1394. Find Lucky Integer in an Array
~ Link      : https://leetcode.com/contest/weekly-contest-182/problems/find-lucky-integer-in-an-array/
*/

class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> mp;
        for(int a : arr)
            ++mp[a];
        int ans = -1;
        for(auto p : mp) {
            if(p.first == p.second)
                ans = p.first;
        }
        return ans;
    }
};
