class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        map <int , int> memo;
        ListNode *it = head;
        while (it != nullptr)
        {
            memo[it -> val]++;
            it = it -> next;
        }
        ListNode* head2 = new ListNode(INT_MIN);
        ListNode *it2 = head2 ;
        for (auto &p : memo)
        {
            if (p.second == 1)
            {
                it2 -> next = new ListNode(p.first);
                it2 = it2 -> next;
            }
        }
        return head2 -> next;
    }
};
