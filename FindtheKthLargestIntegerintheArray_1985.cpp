/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1985. Find the Kth Largest Integer in the Array
~ Link      : https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/
*/

/* Approach 1 (Using sort() with custom comparator) */
/*
class Solution {
public:
    static bool compare(const string num1, const string num2) {
	    if (num1.size() != num2.size())
		    return num1.size() > num2.size();

	    return num1 > num2;
    }

    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), compare);

        return nums[k - 1];
    }
};
*/
// Time Complexity - O(n * log n * m), where n = nums.length & m = nums[i].length
// Auxiliary Space - O(1)

/* Approach 2 (Using min-heap) */

class Solution {
public:
    struct compare {
        bool operator()(const string num1, const string num2) {
	        if (num1.size() != num2.size())
		        return num1.size() > num2.size();

	        return num1 > num2;
        }
    };

    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, compare> pq;

        for (auto currNum : nums) {
            pq.push(currNum);

            if (pq.size() > k)
                pq.pop();
        }

        return pq.top();
    }
};

// Time Complexity - O(n * log k * m), where n = nums.length & m = nums[i].length
// Auxiliary Space - O(k)
