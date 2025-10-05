class ArrayStack {
    int *arr;
    int capacity;
    int topIndex;

public:
    ArrayStack(int size = 1000) { 
        capacity = size;
        arr = new int[capacity];
        topIndex = -1;
    }
    
    void push(int x) {
        if (topIndex == capacity - 1) {
            return;
        }
        arr[++topIndex] = x;
    }
    
    int pop() {
        if (topIndex == -1) {
            return -1;
        }
        return arr[topIndex--];
    }
    
    int top() {
        if (topIndex == -1) {
            return -1;
        }
        return arr[topIndex];
    }
    
    bool isEmpty() {
        return topIndex == -1;
    }
};
