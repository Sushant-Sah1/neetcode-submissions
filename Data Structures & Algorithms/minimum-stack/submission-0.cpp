class MinStack {
public:
    stack<int>st,minst;
    MinStack() {
        st.push(INT_MAX);
        minst.push(INT_MAX);
    }
    
    void push(int val) {
        st.push(val);
        minst.push(min(minst.top(),val));
    }
    
    void pop() {
        st.pop();
        minst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};
