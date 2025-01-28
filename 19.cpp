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
int LOL(ListNode* head)
{
    int count = 0;
    auto it = head;
    while (it != nullptr)
    {
        count += 1;
        it = it -> next;
    }
    return count;
}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int k = LOL(head);
        int t = k - n ;
        auto it = head;
        if (t == 0) return it -> next; 
        while (t-- > 1)
        {
            it = it -> next;
        }
        it -> next = it -> next -> next;
        return head;
    }
};
