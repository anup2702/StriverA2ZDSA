class MyStack {
public:
    queue<int> q;
    MyStack() {  
    }
    void push(int x) {
        q.push(x);
        int size= q.size();
        for(int i=0;i<size-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    int pop() {
        int res = q.front();
        q.pop();
        return res;
    }
    int top() {
        return q.front();
    }
    bool empty() {
        return q.empty();
    }
};

// Using Double Queue
class Stack {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    void pop() {
        if (q1.empty()) return;
        q1.pop();
    }
    int top() {
        if (q1.empty()) return -1;
        return q1.front();
    }
    bool isEmpty() {
        return q1.empty();
    }
};

