class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        Node* temp=*head_ref;
        if(temp==NULL)
            return;
        if(temp->data==x&&temp->next==NULL) {
            *head_ref=NULL;
            free(temp);
            return;
        }
        
        while(temp!=NULL) {
            if(temp->data==x){
                if(temp->prev==NULL) {
                    temp->next->prev=NULL;
                    *head_ref=temp->next;
                }
                if(temp->prev!=NULL)
                    temp->prev->next=temp->next;
                if(temp->next!=NULL)
                    temp->next->prev=temp->prev;
            }
            temp=temp->next;
        }
    }
};