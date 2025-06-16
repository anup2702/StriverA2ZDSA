/* Link list node */
/*
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; */

class Solution {
  public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, struct Node* head, int key) {
        // Code here
        Node* st = head;
 
        while(st->next != nullptr){
            if(st->data==key) return true;
            st = st->next;
        }
        
        return false;
    }
};