/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 692. Top K Frequent Words
~ Link      : https://leetcode.com/problems/top-k-frequent-words/
*/

class Solution {
public:
    struct compare {
        bool operator()(const pair<int, string> &val1, const pair<int, string> &val2) {
            if (val1.first == val2.first)
                return (val1.second < val2.second);
            else
                return (val1.first > val2.first);
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;

        for (auto s : words) {
            ++freq[s];
        }

        priority_queue<pair<int, string>, vector<pair<int, string> >, compare> kFrequent;

        for (auto i : freq) {
            kFrequent.push({i.second, i.first});

            if (kFrequent.size() > k)
                kFrequent.pop();
        }

        vector<string> kFrequentStrings;

        while (!kFrequent.empty()) {
            kFrequentStrings.insert(kFrequentStrings.begin(), kFrequent.top().second);
            kFrequent.pop();
        }

        return kFrequentStrings;
    }
};

// Time Complexity - O(n * log k)
// Auxiliary Space - O(n)
