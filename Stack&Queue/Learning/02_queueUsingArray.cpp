class ArrayQueue {
        int *arr;
        int capacity;
        int rear, front, cnt;
public:
    ArrayQueue(int size = 1000) {
        capacity = size;
        arr = new int[capacity];
        rear = -1;
        cnt = 0;
        front = 0;
    }
    
    void push(int x) {
        if(cnt == capacity){
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        cnt++;
    }
    
    int pop() {
        if(cnt == 0){
            return -1;
        }
        int el = arr[front];
        front = (front + 1) % capacity;
        cnt--;
        return el;
    }
    
    int peek() {
        if(cnt == 0) return -1;
        return arr[front];
    }
    
    bool isEmpty() {
        return cnt == 0;
    }
};