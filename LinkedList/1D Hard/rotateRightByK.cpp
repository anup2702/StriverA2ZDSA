class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int len = 1;
        ListNode* tail = head;
        while(tail->next){
            len++;
            tail = tail->next;
        }
        if(k%len == 0) return head;
        k %= len;
        tail->next = head;
        tail = head;

        for(int i=1; i< len-k; i++){
            tail = tail->next;
        }
        head = tail->next;
        tail->next = NULL;
        return head;
    }
};