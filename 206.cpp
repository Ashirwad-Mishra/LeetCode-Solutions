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
    ListNode* reverseList(ListNode* head) {
        ListNode* p1 = nullptr;
        ListNode* p2 = head;
        ListNode* p3 = nullptr;
        while (p2 != nullptr)
        {
            p3 = p2 -> next;
            p2 -> next = p1;
            p1 = p2;
            p2 = p3;
        }
        return p1;
    }
};
