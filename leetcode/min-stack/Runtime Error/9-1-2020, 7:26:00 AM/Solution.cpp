// https://leetcode.com/problems/min-stack

class MinStack {
public:
    /** initialize your data structure here. */
    std::stack<int> valStack;
    std::stack<int> minStack;
    MinStack() {
    }
    
    void push(int x) {
        if (valStack.size() == 0){
            valStack.push(x);
            minStack.push(x);
        }
        else{
            valStack.push(x);
            if (x < minStack.top())
                minStack.push(x);
        }
    }
    
    void pop() {
        if(valStack.size() != 0){
            if(minStack.top() == valStack.top()){
                minStack.pop();
                valStack.pop();
            }
            else
                minStack.pop();
        }
    }
    
    int top() {
        return valStack.top();
    }
    
    int getMin() {
        return minStack.top();
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