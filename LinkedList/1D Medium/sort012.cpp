class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        if(!head) return head;
        Node *oneHead = new Node(-1);
        Node *twoHead = new Node(-1);
        Node *zeroHead = new Node(-1);
        
        Node *one = oneHead, *two = twoHead, *zero = zeroHead;
        
        Node* temp = head;
        while(temp){
            if(temp->data == 1){
                one->next = temp;
                one = one->next;
            } else if(temp->data == 2){
                two->next = temp;
                two = two->next;
            } else{
                zero->next = temp;
                zero = zero->next;
            }
            temp = temp->next;
        }
        
        zero->next = (oneHead->next) ? (oneHead->next) : (twoHead->next);
        one->next = twoHead->next;
        two->next = NULL;
        
        Node* newNode = zeroHead->next;
        
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        
        return newNode;
    }
};