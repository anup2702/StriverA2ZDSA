
class Solution {
public:

    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge2List(ListNode* l1, ListNode* l2){

        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while(l1 && l2){
            if(l1->val < l2->val){
                temp->next = l1;
                temp = l1;
                l1 = l1->next;
            }
            else{
                temp->next = l2;
                temp = l2;
                l2 = l2->next;
            }

            if(l1) temp->next = l1;
            else temp->next = l2;

        }
        return dummyNode->next;

    }

    ListNode* sortList(ListNode* head) {
        
        if(head==NULL || head->next ==NULL) return head;

        ListNode* middle = findMiddle(head);

        ListNode* left = head;
        ListNode* right = middle->next;

        middle->next = NULL;

        left = sortList(left);
        right = sortList(right);

        return merge2List(left, right);

    }
};

// find middle, sort left and right half and merge them call recursively 