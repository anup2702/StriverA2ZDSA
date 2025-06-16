/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Code here
        Node* temp = new Node(x);
        
        if(head==nullptr) return temp;
        
        Node* st = head;
        while(st->next != nullptr){
            st = st->next;
        }
        
        st->next = temp;
   
        return head;
    }
};