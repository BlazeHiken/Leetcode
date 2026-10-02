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
    void reorderList(ListNode* head) {
        
        ListNode *slow, *fast; // find middle
        slow=fast=head;
        while(fast!=NULL && fast->next!=NULL) {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode *prev, *next1; //reverse from middle
        prev = NULL;
        while(slow!=NULL) {
            next1=slow->next;
            slow->next=prev;
            prev=slow;
            slow=next1;
        }

        ListNode *strt, *end, *next2;
        strt=head;
        end=prev;
        while(strt!=end) {
            next1=strt->next; // i points to n-i
            strt->next=end;
            strt=next1;

            if(strt==end) break;
            
            next2=end->next; // n-i points to i+1
            end->next=strt;
            end=next2;
        }
    }
};