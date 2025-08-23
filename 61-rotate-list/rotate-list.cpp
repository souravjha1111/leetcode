class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        int size = 1;
        ListNode* temp = head;
        while (temp->next) {
            temp = temp->next;
            size++;
        }
        k = k % size;
        if (k == 0) return head;
        temp->next = head;

        int stepsToNewHead = size - k;
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewHead; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
