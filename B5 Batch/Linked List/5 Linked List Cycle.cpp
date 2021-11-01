/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *A)
    {
        if (!A || !(A->next))
            return false;

        ListNode *slow = A;
        ListNode *fast = A->next;

        while (fast && fast->next && slow != fast)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (slow == fast)
            return true;

        return false;
    }
};