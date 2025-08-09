

class Solution {
  public:
  
  int addHelper(Node* temp){
      if(temp==NULL) return 1;
      int carry = addHelper(temp->next);
      temp->data += carry;
      
      if(temp->data <10) return 0;
      
      temp->data = 0;
      return 1;
  }
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        Node* temp = head;
        int carry = addHelper(temp);
        if(carry==1){
            Node* newNode= new Node(1);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};