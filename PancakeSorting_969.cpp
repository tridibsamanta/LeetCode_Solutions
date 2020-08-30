/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 969. Pancake Sorting
~ Link      : https://leetcode.com/problems/pancake-sorting/
*/

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {

        vector<int> res;

        int curr_size = A.size();

        while (curr_size > 1) {

            auto maxIdx = max_element(A.begin(), A.begin() + curr_size);

            res.emplace_back(maxIdx - A.begin() + 1);
            reverse(A.begin(), maxIdx + 1);

            res.emplace_back(curr_size);
            reverse(A.begin(), A.begin() + curr_size);

            --curr_size;
        }

        return res;

    }
};
