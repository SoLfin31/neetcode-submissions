class MyStack {
private:
    queue<int> q;
    int length;
public:
    MyStack() {
        length = 0;
    }
    
    void push(int x) {
       q.push(x);
       length += 1;
    }
    
    int pop() {
       for(int i = 0; i < length - 1 ; i++) 
       {
            q.push(q.front());
            q.pop();
       }
       int top = q.front();
       q.pop();
       length --;
       return top;
    }
    
    int top() {
       return q.back();
    }
    
    bool empty() {
        return q.empty();
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