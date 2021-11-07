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
    bool isPalindrome(ListNode* head) {
        //finding mid
        if(!head || !(head->next)) return true;
        
        ListNode* slow =  head;
        ListNode* fast = head;
        ListNode* prev_slow = NULL;
        
        while(fast && fast->next)
        {
            prev_slow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev_slow->next=NULL; 
        ListNode* head2 = slow;
        
        
        //reverse
        ListNode* prev = NULL;
        ListNode* curr = slow;
        ListNode* next;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head2 = prev;
        
        //comparing first half and reversed second half
        while(head && head2)
        {
            if(head->val != head2->val) return false;
            head = head->next;
            head2 = head2->next;
        } 
    
        return true;
    }
};