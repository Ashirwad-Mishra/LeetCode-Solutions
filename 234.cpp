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
ListNode* middleNode(ListNode* head) 
{
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* reverseList(ListNode* head) 
{
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* nextNode = nullptr;
    while (curr != nullptr) 
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev; 
}

bool isPalindrome(ListNode* head) 
{
    if (head == nullptr || head->next == nullptr) return true; 
    ListNode* middle = middleNode(head);
    ListNode* secondHalf = reverseList(middle);
    ListNode* firstHalf = head;
    ListNode* secondHalfStart = secondHalf; 

    while (secondHalf != nullptr) 
    {
        if (firstHalf->val != secondHalf->val) 
        {
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    return true;
}

};
