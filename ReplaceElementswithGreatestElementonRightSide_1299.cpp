/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 1299. Replace Elements with Greatest Element on Right Side
~ Link      : https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
*/

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int len = arr.size();
        int maxRight = arr[len - 1];
        arr[len - 1] = -1;
        for (int i = len - 2; i >= 0; --i) {
            int temp = arr[i];
            arr[i] = maxRight;
            if (temp > maxRight)
                maxRight = temp;
        }
        return arr;
    }
};
