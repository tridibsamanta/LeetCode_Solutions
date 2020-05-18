/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 225. Implement Stack using Queues
~ Link      : https://leetcode.com/problems/implement-stack-using-queues/
*/

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    queue<int> q1, q2;

    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {

        if (q1.empty())
            return -1;

        while (q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int element = q1.front();
        q1.pop();

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;

        return element;
    }

    /** Get the top element. */
    int top() {

        if (q1.empty())
            return -1;

        while (q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int element = q1.front();
        q2.push(q1.front());
        q1.pop();

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;

        return element;
    }

    /** Returns whether the stack is empty. */
    bool empty() {

        if (q1.empty())
            return true;

        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
