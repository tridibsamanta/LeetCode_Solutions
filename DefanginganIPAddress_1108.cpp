/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 1108. Defanging an IP Address
~ Link      : https://leetcode.com/problems/defanging-an-ip-address/
*/

class Solution {
public:
    string defangIPaddr(string address) {
        string defanged = "";
        int len = address.length();
        for (int i = 0; i < len; ++i) {
            if (address[i] == '.')
                defanged += "[.]";
            else
                defanged += address[i];
        }
        return defanged;
    }
};
