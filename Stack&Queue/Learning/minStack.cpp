class MinStack {
public:
    stack<int> st, minStack;
    
    MinStack() {}
    
    void push(int val) {
        st.push(val);
        if(minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        if(st.empty()) return;
        if(st.top() == minStack.top()) {
            minStack.pop();
        }
        st.pop();
    }

    int top() {
        return st.empty() ? -1 : st.top();
    }

    int getMin() {
        return minStack.empty() ? -1 : minStack.top();
    }
};



// Optimised Approach - 2

class MinStack {
    stack<long long> st;
    long long minEle;
public:
    MinStack() {}

    void push(int x) {
        if(st.empty()){
            st.push(x);
            minEle = x;
        } else {
            if(x >= minEle){
                st.push(x);
            } else {
                st.push(2LL*x - minEle); // store encoded value
                minEle = x; // update min
            }
        }
    }

    void pop() {
        if(st.empty()) return;
        long long t = st.top(); st.pop();
        if(t < minEle){
            minEle = 2*minEle - t; // restore previous min
        }
    }

    int top() {
        long long t = st.top();
        if(t >= minEle) return t;
        else return minEle; // encoded value
    }

    int getMin() {
        return minEle;
    }
};
