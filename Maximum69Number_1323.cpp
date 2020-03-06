/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1323. Maximum 69 Number
~ Link      : https://leetcode.com/problems/maximum-69-number/
*/

class Solution {
public:
    int maximum69Number (int num) {

    std::string str = std::to_string(num);
    int n = str.length();
    int k = 1;

    for (int i = 0; i < n; i++) {


        if (k < 1)
            break;


        if (str[i] != '9') {


            str[i] = '9';

            k--;
        }
    }
    int mynum = stoi(str);
    return mynum;
    }
};

// *** ALTERNATE SOLUTION IN JAVA ***

/*
class Solution {
    public int maximum69Number (int num) {
        char[] c = Integer.toString(num).toCharArray();
        for(int i = 0; i<c.length; i++){
            if(c[i]=='6'){
                c[i] = '9';
                break;
            }
        }
        return Integer.parseInt(new String(c));
    }
}
*/
