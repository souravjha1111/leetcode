class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode smallDummy(0), bigDummy(0);
        ListNode* small = &smallDummy;
        ListNode* big = &bigDummy;

        while (head) {
            if (head->val < x) {
                small->next = head;
                small = small->next;
            } else {
                big->next = head;
                big = big->next;
            }
            head = head->next;
        }

        big->next = nullptr;          // end the big list
        small->next = bigDummy.next;  // connect two lists

        return smallDummy.next;
    }
};
