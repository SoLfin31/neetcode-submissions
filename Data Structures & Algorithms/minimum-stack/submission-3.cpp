class MinStack {
private :
    stack<int> minStack,nodeMinStack;
public:
    MinStack() {
    }
   // 7 5 9 8 3 2 3  
   //3 8 9 7 5 3 2  
   //min: 7 5 9 8 3
   //nodeMin: 7 5 5 5 3 
    void push(int val) {
        minStack.push(val);
        if(!nodeMinStack.empty())
        {
            if(val <= nodeMinStack.top())
            {
                nodeMinStack.push(val);
            }
            else
            {
                nodeMinStack.push(nodeMinStack.top());
            }
        }
        else nodeMinStack.push(val);
        
    }
    
    void pop() {
        if(!minStack.empty())
        {
            minStack.pop();
            nodeMinStack.pop();
        }
    }
    
    int top() {
        if(!minStack.empty())
        {
            int top = 0;
            top = minStack.top();
            return top; 
        }
        return -1;
    }
    
    int getMin() {
        if(!minStack.empty())
        {
           return nodeMinStack.top();
        }
        return -1;
    }
};
