class Solution {
private: 
    void insertNodeAtPos(ListNode*& head, int data)
    {
        ListNode* newNode = new ListNode(data);
        ListNode* it = head;

        while (it->next != nullptr && it->next->val < data)
        {
            it = it->next;
        }
        newNode->next = it->next;
        it->next = newNode;
    }
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return nullptr; 

        ListNode* ans = new ListNode(INT_MIN);
        ListNode* it = head;
        while (it != nullptr)
        {
            insertNodeAtPos(ans, it->val);
            it = it->next;
        }
        return ans->next;
    }
};
