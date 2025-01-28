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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head -> next == nullptr ) return head;
        ListNode* i = head;
        ListNode* j = head -> next;
        while ( i != nullptr && j != nullptr)
        {
            swap(i-> val , j -> val );
            i = j -> next;
            if ( i != nullptr) j = i -> next;
        }
        return head;
    }
};
