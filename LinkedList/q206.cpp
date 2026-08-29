class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) {
            return NULL;
        }
        ListNode *prev, *curr, *next1;
        curr = head;
        while(curr!=NULL) {
            next1 = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next1;
        }
        return prev;
    }
};