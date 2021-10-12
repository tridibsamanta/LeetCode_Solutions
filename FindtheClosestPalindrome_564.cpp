/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 564. Find the Closest Palindrome
~ Link      : https://leetcode.com/problems/find-the-closest-palindrome/
*/

/*
    Intuition:

    I) Find the palindrome just less than n
    II) Find the palindrome just greater than n
    III) Return the palindrome having min. difference with n
*/

class Solution {
public:
    string roundUpNext(string s, int n) {
	    int i = n / 2;

	    while (i >= 0) {
		    if (s[i] != '9')
			    break;
		    --i;
	    }

	    if (i < 0) {
		    s = "1" + string (n, '0');
	    }
	    else {
		    ++s[i];

		    for (int j = i + 1; j < n; ++j)
			    s[j] = '0';
	    }

	    int j = s.size() - 1; i = 0;

	    while (i < j) {
		    s[j--] = s[i++];
	    }

	    return s;
    }

    string roundUpPrev(string s, int n) {
	    int i = n / 2;

	    while (i >= 0) {
		    if (s[i] != '0')
			    break;
		    --i;
	    }

	    if (i == 0 && s[i] == '1')
		    return string (n - 1, '9');

		--s[i];

		for (int j = i + 1; j < n; ++j)
			s[j] = '9';

	    int j = s.size() - 1; i = 0;

	    while (i < j) {
		    s[j--] = s[i++];
	    }

	    return s;
    }

    string generateNextPalindrome(string s) {
        int m = s.size();
	    string t = s;
	    int i = 0, j = m - 1;

	    while (i < j) {
    		t[j--] = t[i++];
	    }

	    if (t > s)
		    return t;

	    if (m & 1) {
		    if (t[m / 2] == '9')
			    t = roundUpNext(t, m);
		    else
			    ++t[m / 2];
	    }
	    else {
		    if (t[m / 2] == '9')
			    t = roundUpNext(t, m);
		    else {
			    ++t[m / 2];
			    ++t[m / 2 - 1];
		    }
	    }

        return t;
    }

    string generatePrevPalindrome(string s) {
        if (s == "11")
            return "9";

        int m = s.size();
	    string t = s;
	    int i = 0, j = m - 1;

	    while (i < j) {
    		t[j--] = t[i++];
	    }

	    if (t < s)
		    return t;

	    if (m & 1) {
		    if (t[m / 2] == '0')
			    t = roundUpPrev(t, m);
		    else
			    --t[m / 2];
	    }
	    else {
		    if (s[m / 2] == '0')
			    t = roundUpPrev(s, m);
		    else {
			    --t[m / 2];
			    --t[m / 2 - 1];
		    }
	    }

        return t;
    }

    string nearestPalindromic(string n) {
        string next = generateNextPalindrome(n);
        string prev = generatePrevPalindrome(n);

        long long num = stoll(n);
        long long next_pal = stoll(next);
        long long prev_pal = stoll(prev);

        long long diff1 = num - prev_pal;
        long long diff2 = next_pal - num;

        return ((diff2 < diff1) ? next : prev);
    }
};
