class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while (temp1 != temp2) {
            temp1 = temp1 ? temp1->next : headB;
            temp2 = temp2 ? temp2->next : headA;
        }

        return temp1;
    }
};
