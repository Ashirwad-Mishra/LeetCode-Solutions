class Solution {
private:
    ListNode* mid(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr) return head; 
        ListNode* s = head;
        ListNode* f = head;
        ListNode* p = nullptr; 
        while (f != nullptr && f->next != nullptr)
        {
            p = s;
            s = s -> next;
            f = f->next->next;
        }

        if (p) p->next = nullptr; 

        return s;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr; 
        ListNode* m = mid(head);

        TreeNode* ans = new TreeNode(m->val);

        if (m == head) return ans; 

        ans->left = sortedListToBST(head);
        ans->right = sortedListToBST(m->next);

        return ans;
    }
};
