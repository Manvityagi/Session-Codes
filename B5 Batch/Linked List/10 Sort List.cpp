class Solution {
private:
    ListNode* midpoint(ListNode* head){
        if(head == NULL) return head;
        ListNode *c, *f, *p;
        c = head, f = head;
        while(f != NULL && f->next != NULL){
            p = c;
            c = c->next;
            f = f->next->next;
        }
        p->next = NULL; // break list at the midpoint
        return c;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1->val <= l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
            l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
    ListNode* sortlist(ListNode* head){
        if(head->next == NULL) return head;
        ListNode* mid = midpoint(head);
        //breaklist(head, mid);
        ListNode* res = mergeTwoLists(sortlist(head), sortlist(mid));
        return res;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL) return head;
        return sortlist(head);
    }
};