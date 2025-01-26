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
    ListNode* removeElements(ListNode* head, int val) {
    if (head == nullptr) return head;

    ListNode* i = new ListNode(0);
    i->next = head;
    ListNode* j = i;

    while (j->next != nullptr) {
        if (j->next->val == val) {
            j->next = j->next->next;
        } else {
            j = j->next;
        }
    }

    return i->next;
}

};
