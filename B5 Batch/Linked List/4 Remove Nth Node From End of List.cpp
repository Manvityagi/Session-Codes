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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode* fast = dummyhead;
        ListNode* slow = dummyhead;
        
         for(int i = 1; i <= n+1; i++)
         {
             fast = fast->next;
         }
        
        while(fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        
        if(slow && slow->next)
            slow->next = slow->next->next;
        
        return dummyhead->next;
    }
};