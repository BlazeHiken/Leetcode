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
class Solution { // dummy soln, no dummy soln, double reverse soln
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *slow, *fast;
        fast=head;
        slow=&dummy;
        for(int i=0; i<n; i++) {
            fast=fast->next;
        }
        while(fast!=NULL) {
            slow=slow->next;
            fast=fast->next;
        }
        ListNode *victim = slow->next;
        slow->next = victim->next;
        delete victim;
        return dummy.next;
    }
};