/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 468. Validate IP Address
~ Link      : https://leetcode.com/problems/validate-ip-address/
*/

class Solution {
public:
    bool validateOctet(string octet) {
        if ((octet.size() > 1 && octet[0] == '0') || (stoi(octet) > 255))
            return false;
        else
            return true;
    }

    bool isIPv4(string ip) {
        if (ip.size() < 7 || ip.size() > 15)
            return false;

        int prevDotIndex = -1, dotCount = 0;

        for (int i = 0; i < ip.size(); ++i) {
            if (ip[i] == '.') {
                ++dotCount;

                if (i - prevDotIndex == 1)
                    return false;

                prevDotIndex = i;
            }
            else if (!(ip[i] >= '0' && ip[i] <= '9'))
                return false;
        }

        if (dotCount != 3)
            return false;

        string num = "";

        for (int i = 0; i < ip.size(); ++i) {
            if (ip[i] == '.') {
                if (!validateOctet(num))
                    return false;

                num.clear();
            }
            else {
                num.push_back(ip[i]);
            }
        }

        return validateOctet(num);
    }

    bool isIPv6(string ip) {
        if (ip.size() < 15 || ip.size() > 39)
            return false;

        int prevColonIndex = -1, colonCount = 0;

        for (int i = 0; i < ip.size(); ++i) {
            if (ip[i] == ':') {
                ++colonCount;

                if (i - prevColonIndex == 1)
                    return false;

                prevColonIndex = i;
            }
            else if (!((ip[i] >= '0' && ip[i] <= '9') ||
                       (ip[i] >= 'a' && ip[i] <= 'f') ||
                       (ip[i] >= 'A' && ip[i] <= 'F')))
                return false;
        }

        if (colonCount != 7)
            return false;

        string str = "";

        for (int i = 0; i < ip.size(); ++i) {
            if (ip[i] == ':') {
                if (str.size() > 4)
                    return false;

                str.clear();
            }
            else {
                str.push_back(ip[i]);
            }
        }

        return (str.size() > 0 && str.size() <= 4);
    }

    string validIPAddress(string queryIP) {
        if (queryIP.find('.') != string::npos)
            return (isIPv4(queryIP) ? "IPv4" : "Neither");
        else if (queryIP.find(':') != string::npos)
            return (isIPv6(queryIP) ? "IPv6" : "Neither");
        else
            return "Neither";
    }
};

// Time Complexity - O(queryIP.length)
// Auxiliary Space - O(1)
