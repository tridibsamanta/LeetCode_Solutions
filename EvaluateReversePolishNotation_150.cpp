/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 150. Evaluate Reverse Polish Notation
~ Link      : https://leetcode.com/problems/evaluate-reverse-polish-notation/
*/

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> st;
        int s1,s2;
        s1=s2=0;
        int res=0;
        for(vector<string>::iterator iter=tokens.begin();iter!=tokens.end();iter++)
        {
                if (*iter == "+")
                {
                    s1=st.top();
                    st.pop();
                    s2=st.top();
                    st.pop();
                   res=s1+s2;
                   st.push(res);
                }

                else if (*iter == "-")
                {
                    s1=st.top();
                    st.pop();
                    s2=st.top();
                    st.pop();
                   res=s2-s1;
                   st.push(res);
                }
                else if (*iter == "*")
                {
                    s1=st.top();
                    st.pop();
                    s2=st.top();
                    st.pop();
                   res=s1*s2;
                   st.push(res);
                }
                else if (*iter== "/")
                {
                    s1=st.top();
                    st.pop();
                    s2=st.top();
                    st.pop();
                    res=s2/s1;
                    st.push(res);
                }
                else
                {
                    st.push(atoi((*iter).c_str()));
                }
            }
            return st.top();
        }
};
