/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 60. Permutation Sequence
~ Link      : https://leetcode.com/problems/permutation-sequence/
*/

/*
Intuition:

Let's assume, n = 3 and k = 5

result = "", nums = [1, 2, 3]

Remove digits one by one from the nums array,
and put it in the result string. Thus when the nums array
is empty, our result string size will be n.

Make k 0-based indexed, i.e. k -= 1. Here k becomes 4.

(i) Let's find the left-most digit -

1, {2, 3} -> 2! permutations -> 2 [0 to 1]
2, {1, 3} -> 2! permutations -> 2 [2 to 3]
3, {1, 2} -> 2! permutations -> 2 [4 to 5]  <-- k'th permutation lies here

Thus current digit must be 3.
How to get its index in nums array ?
index = k / 2! = 4 / 2 = 2

result += nums[index]
result = "3", nums = [1, 2]

Next permutation index (k) = 4 % 2! = 0

(ii) Let's find the next digit -

1, {2} -> 1! permutations -> 1 [0 to 0] <-- k'th permutation lies here
2, {1} -> 1! permutations -> 1 [1 to 1]

Thus current digit must be 1.
index = k / 1! = 0 / 1 = 0

result += nums[index]
result = "31", nums = [2]

Next permutation index (k) = 0 % 1! = 0

(iii) Let's find the next digit -

Now we have a single digit left in nums.
index = k / 0! = 0 / 1 = 0

result += nums[index]
result = "312", nums = []

Now as the nums array is empty, the result string contains all the digits
which were initially present in the nums array when it was created.

T.C. - O(n^2), to form n digits and erase also takes linear time.
*/

class Solution {
public:
    string getPermutation(int n, int k) {

        if (n == 1)
            return "1";

        string kth_perm = "";

        vector<int> nums;
        int fact = 1;
        for (int i = 1; i < n; ++i) {
            nums.emplace_back(i);
            fact *= i;
        }
        nums.emplace_back(n);

        --k; // 0-based indexing

        while (true) {

            // get digit index
            int idx = k / fact;

            // append the digit
            kth_perm += to_string(nums[idx]);

            // remove the appended digit
            nums.erase(nums.begin() + idx);

            // exhausted all the digits
            if (nums.size() == 0)
                break;

            // index of the remaining sequence
            k = k % fact;

            // recalculate number of permutations
            fact = fact / nums.size();
        }

        return kth_perm;
    }
};
