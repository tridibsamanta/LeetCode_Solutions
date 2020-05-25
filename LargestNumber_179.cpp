/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 179. Largest Number
~ Link      : https://leetcode.com/problems/largest-number/
*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {

        vector<string> arr;

        for (auto num : nums)
            arr.push_back(to_string(num));

        sort(arr.begin(), arr.end(), checkGreater);

        string largestNumber;
        for (auto str : arr)
            largestNumber += str;

        return (largestNumber[0] == '0') ? "0" : largestNumber;
    }
private:
    static bool checkGreater(string s1, string s2) {
        return (s1 + s2 > s2 + s1);
    }
};
