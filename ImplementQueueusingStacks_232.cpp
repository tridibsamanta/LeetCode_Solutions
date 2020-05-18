/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 232. Implement Queue using Stacks
~ Link      : https://leetcode.com/problems/implement-queue-using-stacks/
*/

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    stack<int> s1, s2;

    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int element = peek();
        if (element == -1)
            return -1;
        s2.pop();
        return element;
    }

    /** Get the front element. */
    int peek() {
        if (s2.empty() && s1.empty())
            return -1;
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
