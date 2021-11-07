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
    //1->2->(3->4->5->6)->7->8
    //1->2->(6->5->4->3)->7->8
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || !(head->next) || n == m) return head;
        
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode* temp = dummyhead;
        for(int i = 1; i < m; i++)
            temp = temp->next;
        
        ListNode* mprev = temp; //2
        ListNode* mstart = temp->next; //3
        ListNode* curr = mstart;
        ListNode* pre = NULL;
        ListNode* next;
        for(int i = m; i <= n && curr; i++)
        {
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        
        //linking 2 to 6
        mprev->next = pre;
        
        //linking 3 to 7
        mstart->next = next; 
        
        return dummyhead->next;
        
    }
};