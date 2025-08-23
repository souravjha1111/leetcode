/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        // Step 1: Move prev to node before left
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // Step 2: Reverse sublist [left, right]
        ListNode* curr = prev->next;
        ListNode* next = nullptr;
        ListNode* tail = curr; // will become tail of reversed part

        for (int i = 0; i < right - left + 1; i++) {
            next = curr->next;
            curr->next = prev->next;
            prev->next = curr;
            curr = next;
        }

        // Step 3: Connect tail to remaining part
        tail->next = curr;

        return dummy.next;
    }
};
