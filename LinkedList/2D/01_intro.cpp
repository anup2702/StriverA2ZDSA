// User function Template for C++

/*
class Node{
public:
    Node* prev;
    int data;
    Node* next;

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};*/

class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
        // code here
        
        if(arr.size()==0) return 0;
        
        Node* head = new Node(arr[0]);
        Node* temp = head;
        
        for(int i=1;i<arr.size();i++){
            temp->next = new Node(arr[i]);
            temp->next->prev = temp;
            temp=temp->next;
        }
        
       return head;
    }
};