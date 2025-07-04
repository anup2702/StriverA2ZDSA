class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        

        if(head==NULL || head->next==NULL) return NULL;

        ListNode* fast = head;
        ListNode* slow = head;
        fast=head->next->next;
    
        while(fast !=NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};