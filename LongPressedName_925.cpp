/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 925. Long Pressed Name
~ Link      : https://leetcode.com/problems/long-pressed-name/
*/

class Solution {
public:
    bool isLongPressedName(string name, string typed) {

        int n = name.length(), m = typed.length();

        if (m < n)
            return false;

        int idx_name = 0, idx_typed = 0;

        while (idx_name < n && idx_typed < m) {

            if (name[idx_name] != typed[idx_typed])
                return false;

            while (idx_name < n && name[idx_name] == typed[idx_typed]) {
                ++idx_name;
                ++idx_typed;
            }

            while (idx_typed < m && typed[idx_typed] == name[idx_name - 1])
                ++idx_typed;

        }

        return (idx_name < n || idx_typed < m) ? false : true;
    }
};
