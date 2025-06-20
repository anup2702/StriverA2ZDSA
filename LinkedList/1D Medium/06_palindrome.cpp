class Solution {
public:
    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = reverseLL(slow);

        ListNode* firstHalf = head;
        ListNode* copySecond = secondHalf; 
        while (copySecond) {
            if (firstHalf->val != copySecond->val) {
                reverseLL(secondHalf); 
                return false;
            }
            firstHalf = firstHalf->next;
            copySecond = copySecond->next;
        }

        reverseLL(secondHalf);

        return true;
    }
};
