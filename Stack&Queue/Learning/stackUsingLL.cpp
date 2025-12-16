/* class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class myStack {
    Node* top;

  public:
    myStack() {
        // Initialize your data members
        top = NULL;
    }

    bool isEmpty() {
        // check if the stack is empty
        return top == NULL;
    }

    void push(int x) {
        // Adds an element x at the top of the stack
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
        return;
    }

    void pop() {
        // Removes the top element of the stack
        top = top->next;
        return;
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(top==NULL) return -1;
        return top->data;
    }

    int size() {
        // Returns the current size of the stack.
        if(!top) return 0;
        int len = 0; Node* temp = top;
        while(temp){
            len++;
            temp = temp->next;
        }
        return len;
    }
};