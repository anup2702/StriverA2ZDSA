class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        // Your code here
        unordered_map<int, int> mpp;
        Node* temp = head;
        while(temp) {
            if(mpp[temp->data]==1){
                if(temp->prev!=NULL)
                    temp->prev->next=temp->next;
                if(temp->next!=NULL)
                    temp->next->prev=temp->prev;
            } else {
                mpp[temp->data]++;
            }
            temp=temp->next;
        }
        return head;
    }
};