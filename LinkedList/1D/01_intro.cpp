// User function Template for C++

/*class Node {
public:
    int data;
    Node* next;
  
    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }
  
    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};*/

class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
        // code here
        if(arr.size()==0) return 0;
        
        Node* head = new Node(arr[0]);
        Node* temp = head;
        
        for(int i=1;i<arr.size();i++){
            temp -> next = new Node(arr[i]);
            temp = temp->next;
        }
        
        return head;
    }
};