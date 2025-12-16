class Node {
  public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class myQueue {
    Node *front, *rear;
    int curSize;
  public:
    myQueue() {
        // Initialize your data members
        front = NULL; rear = NULL;
        curSize = 0;
    }

    bool isEmpty() {
        // check if the queue is empty
        return curSize==0;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue
        Node* temp = new Node(x);
        if(isEmpty()){
            front = temp; rear = temp;
        } else{
            rear->next = temp;
            rear = temp;
        }
        curSize++;
        return;
    }

    void dequeue() {
        // Removes the front element of the queue
        if(front == rear){
            front = NULL; rear = NULL;
        }
        else front = front->next;
        curSize--;
        return;
    }

    int getFront() {
        // Returns the front element of the queue
        // If queue is empty, return -1
        if(isEmpty()) return -1;
        return front->data;
    }

    int size() {
        // Returns the current size of the queue.
        return curSize;
    }
};
