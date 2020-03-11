#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;

bool isValid(string s) {
        stack<char> my_stack;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                my_stack.push(s[i]);
            else if(s[i] == ')' || s[i] == '}' || s[i] == ']')
            {
                if(my_stack.empty())
                    return false;
                else if( (my_stack.top() == '(' && s[i] == ')') || (my_stack.top() == '{' && s[i] == '}') || (my_stack.top() == '[' && s[i] == ']') )
                {
                    my_stack.pop();
                }
                else
                    return false;
            }
            else
               return false;
        }
    return (my_stack.empty()?true:false);
}

int main() {
    string exp;
    cout<<"Enter the expression : ";
    cin>>exp;
    if(isValid(exp))
        printf("true");
    else
        printf("false");
    return 0;
}
