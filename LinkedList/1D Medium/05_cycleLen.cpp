int countCycleLength(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            int count = 1;
            fast = fast->next;
            // length is from fast to slow
            while (fast != slow) {
                fast = fast->next;
                count++;
            }

            return count;
        }
    }

    return 0;
}
