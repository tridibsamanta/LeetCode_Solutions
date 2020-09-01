/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 556. Next Greater Element III
~ Link      : https://leetcode.com/problems/next-greater-element-iii/
*/

class Solution {
private:

    bool nextPermutation(string& num) {

        if (num.size() == 0)
            return false;

        int n = num.size(), i;

        // Find the rightmost element, which is lesser than the element on its right
        for (i = n - 2; i >= 0; --i) {
            if (num[i] < num[i + 1])
                break;
        }

        // If no such element exists, solution dosen't exist
        if (i == -1)
            return false;

        // Find the rightmost element greater than the element found in previous step
        for (int j = n - 1; j > i; --j) {
            if (num[j] > num[i]) {
                swap(num[j], num[i]);
                break;
            }
        }

        // Reverse the elements from the index - next to the first marked element and the end
        reverse(num.begin() + i + 1, num.end());

        return true;
    }

public:
    int nextGreaterElement(int n) {

        string num = to_string(n);

        if (!nextPermutation(num))
            return -1;

        long res = stol(num);

        if (res > INT_MAX)
            return -1;

        return res;
    }
};
