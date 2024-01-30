/*
LEETCODE LINK : https://leetcode.com/problems/implement-queue-using-stacks/description/

Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
 

Example 1:

Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false

*/

class MyQueue {
private:
    stack<int> input;
    stack<int> output;
    int peekEle=-1;

public:
    MyQueue() {    
    }
    void push(int x) {
        if(input.empty()){
            peekEle=x;
        }
        input.push(x);
    }
    
    //Amortized O(1) -> Mostly O(1) but in some cases O(n) i.e when pushing input to output it is O(n)
    int pop() {
        if(output.empty()){
            //input -> output is O(n)
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        int temp=output.top();
        output.pop();//0(1)
        return temp;
    }
    
    int peek() {
        if(output.empty()){
            return peekEle;
        }
        return output.top();

    }
    
    bool empty() {
        if(input.empty() && output.empty()){
            return true;
        }
        return false;
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
