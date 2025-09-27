class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        Node* curr = head;
        Node* newHead = NULL;
        Node* tail = NULL;
        
        while(curr){
            Node* grpHead = curr;
            Node* prev = NULL;
            Node* nextNode = NULL;
            int cnt = 0;
            while(cnt < k and curr){
                nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
                cnt++;
            }
            if(!newHead) newHead = prev; // first grp
            if(tail) tail->next = prev; // prev tail to curr head
            tail = grpHead;
        }
        return newHead;
    }
};