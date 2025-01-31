/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        vector <ListNode*> temp;
        ListNode* it = head;
        while (it != nullptr)
        {
            if (find(temp.begin() , temp.end() ,it) != temp.end()) return it;
            else
            {
                temp.push_back(it);
            }
            it = it -> next;
        }
        return nullptr;
    }
};
