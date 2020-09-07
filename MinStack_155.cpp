/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 155. Min Stack
~ Link      : https://leetcode.com/problems/min-stack/
*/

class MinStack {
public:

    stack<long> s;
    long minElement;

    MinStack() {
        while (!s.empty())
            s.pop();

        minElement = -1;
    }

    void push(long x) {

        if (s.empty()) {
            s.push(x);
            minElement = x;
        }
        else {
            if (x < minElement) {
                s.push(2 * x - minElement);
                minElement = x;
            }
            else
                s.push(x);
        }
    }

    void pop() {

        if (s.empty())
            return;

        if (s.top() < minElement)
            minElement = 2 * minElement - s.top();

        s.pop();

    }

    int top() {

        if (s.top() > minElement)
            return s.top();

        return minElement;
    }

    int getMin() {
        return minElement;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
