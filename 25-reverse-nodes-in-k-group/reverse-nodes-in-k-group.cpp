class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        int length = 0;
        ListNode* temp = head;
        while (temp) {
            length++;
            temp = temp->next;
        }

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroup = &dummy;

        while (length >= k) {
            ListNode* curr = prevGroup->next;
            ListNode* next = curr->next;

            for (int i = 1; i < k; i++) {
                curr->next = next->next;
                next->next = prevGroup->next;
                prevGroup->next = next;
                next = curr->next;
            }

            prevGroup = curr;
            length -= k;
        }

        return dummy.next;
    }
};
