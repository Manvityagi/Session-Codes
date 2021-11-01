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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummyhead = new ListNode(0); 
        ListNode* move1 = l1, *move2 = l2;
        
        ListNode* tail = dummyhead; 
        
        while(move1 && move2){
            if(move1->val < move2->val){
                tail->next = move1;
                move1 = move1->next;
            } else {
                tail->next = move2;
                move2 = move2->next; 
            }
            tail = tail->next; 
        }
        
        while(move1){
            tail->next = move1; 
            move1 = move1->next;
            tail = tail->next;
        }
        
        while(move2){
            tail->next = move2; 
            move2 = move2->next;
            tail = tail->next; 
        }
        
        return dummyhead->next;
    }
};