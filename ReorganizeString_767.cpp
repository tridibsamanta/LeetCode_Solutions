/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 767. Reorganize String
~ Link      : https://leetcode.com/problems/reorganize-string/
*/

class Solution {
public:
    string reorganizeString(string s) {
        string res = "";
        int n = s.size();

        unordered_map<char, int> freq; // {character, freq}

        for (auto c : s) {
            ++freq[c];
        }

        priority_queue<pair<int, char> > todo; // {freq, character}

        for (auto p : freq) {
            todo.push({p.second, p.first});
        }

        while (todo.size() > 1) {
            int freq1 = todo.top().first;
            char char1 = todo.top().second;

            todo.pop();

            int freq2 = todo.top().first;
            char char2 = todo.top().second;

            todo.pop();

            res.push_back(char1);
            res.push_back(char2);

            if (--freq1 > 0)
                todo.push({freq1, char1});

            if (--freq2 > 0)
                todo.push({freq2, char2});
        }

        if (todo.size() == 1 && todo.top().first == 1) {
            res.push_back(todo.top().second);
            todo.pop();
        }

        return (todo.size() == 0 ? res : "");
    }
};

// Time Complexity: O(s.size() * log ALPHABET_SIZE)
// Auxiliary Space: O(ALPHABET_SIZE)
